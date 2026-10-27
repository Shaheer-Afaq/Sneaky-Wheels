// Run this first to get the MAC address of the ESP32
// #include "WiFi.h"

// void setup() {

//   // Setup Serial Monitor
//   Serial.begin(115200);

//   // Put ESP32 into Station mode
//   WiFi.mode(WIFI_MODE_STA);

//   // Print MAC Address to Serial monitor
//   Serial.print("MAC Address: ");
//   Serial.println(WiFi.macAddress());
// }

// void loop() {

// }

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

#define motorA1 27
#define motorA2 26
#define motorAS 25

#define motorB1 12
#define motorB2 13
#define motorBS 14

#define standby 33

#define headlight 23

struct data {
   int16_t x1; // joystick 1 x-axis
   int16_t y1; // joystick 1 y-axis
   boolean b1; // joystick 1 button
   int16_t x2; // joystick 2 x-axis
   int16_t y2; // joystick 2 y-axis
   boolean b2; // joystick 2 button
   int16_t p1; // potentiometer 1
   int16_t p2; // potentiometer 2
   boolean b3; // button
   int16_t aX; // angle x
   int16_t aY; // angle y
   int16_t aZ; // angle z
};

data myData;

bool lightButtonWasPressed = false;
bool lightOn = false;
unsigned long lastPacketTime = 0;
int sensitivity = 30;
int maxSpeed = 255;
bool firstPacketReceived = false;

const int joy1YCenter = 1760;
const int joy2XCenter = 1670;
const int deadzone = 80;

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len);
void driveRightMotor(int speed);
void driveLeftMotor(int speed);

void setup() {
   Serial.begin(115200);
   pinMode(standby, OUTPUT);
   digitalWrite(standby, LOW);

   pinMode(motorA1, OUTPUT);
   pinMode(motorA2, OUTPUT);
   pinMode(motorAS, OUTPUT);
   pinMode(motorB1, OUTPUT);
   pinMode(motorB2, OUTPUT);
   pinMode(motorBS, OUTPUT);
   pinMode(headlight, OUTPUT);

   WiFi.mode(WIFI_STA);
   esp_wifi_set_ps(WIFI_PS_NONE);
   esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);

   if (esp_now_init() != ESP_OK) {
      Serial.println("Error initializing ESP-NOW");
      return;
   }
   esp_now_register_recv_cb(OnDataRecv);
   driveRightMotor(0);
   driveLeftMotor(0);
}

void loop() {
   // stop the car if the connection is lost for more than 300ms
   if (!firstPacketReceived || millis() - lastPacketTime > 300) {
      digitalWrite(standby, LOW);
      driveRightMotor(0);
      driveLeftMotor(0);
      digitalWrite(headlight, LOW);
      Serial.println("Connection lost");
      if (millis() - lastPacketTime > 1000 && firstPacketReceived) {
         ESP.restart();
      }
      return;
   }
   digitalWrite(standby, HIGH);

   int throttle, steering;
   if (myData.b3) { // if gyro mode is enabled
      sensitivity = map(myData.p2, 0, 4095, 30, 90);
      throttle = constrain(map(myData.aY, -sensitivity, sensitivity, -255, 255), -255, 255);
      steering = constrain(map(myData.aX, -sensitivity, sensitivity, -255, 255), -255, 255) * -1;
      maxSpeed = 255;
   } else {
      maxSpeed = map(myData.p2, 0, 4095, 100, 255);
      int rawThrottle = myData.y1 - joy1YCenter; // to adjust for joystick inaccuracy
      int rawSteering = myData.x2 - joy2XCenter;

      if (abs(rawThrottle) < deadzone) {
         throttle = 0;
      } else if (rawThrottle >= 0) {
         throttle = map(rawThrottle, deadzone, 4095 - joy1YCenter, 0, maxSpeed);
      } else {
         throttle = map(rawThrottle, -joy1YCenter, -deadzone, -maxSpeed, 0);
      }

      if (abs(rawSteering) < deadzone) {
         steering = 0;
      } else if (rawSteering >= 0) {
         steering = map(rawSteering, 0, 4095 - joy2XCenter, 0, maxSpeed);
      } else {
         steering = map(rawSteering, -joy2XCenter, 0, -maxSpeed, 0);
      }
      steering = steering * -1; // invert steering direction
   }
   int rightSpeed, leftSpeed;
   if (abs(throttle) < 20) { // for spinning in place
      rightSpeed = -steering;
      leftSpeed = steering;
   } else {
      rightSpeed = throttle;
      leftSpeed = throttle;
      // to reduce the speed of one motor based on steering strength and direction
      if (steering > 20) rightSpeed = throttle * (maxSpeed - steering) / maxSpeed;
      else if (steering < -20) leftSpeed = throttle * (maxSpeed + steering) / maxSpeed;
   }

   driveRightMotor(rightSpeed);
   driveLeftMotor(leftSpeed);

   // toggle headlight
   if (myData.b1) lightButtonWasPressed = true;

   if (lightButtonWasPressed && !myData.b1) {
      lightOn = !lightOn;
      lightButtonWasPressed = false;
      digitalWrite(headlight, lightOn);
   }
   delay(10);
}

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
   firstPacketReceived = true;
   if (len == sizeof(myData)) {
      memcpy(&myData, incomingData, sizeof(myData));
      lastPacketTime = millis();
   }
}

void driveRightMotor(int speed) {
   if (speed > 0) {
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
   } else if (speed < 0) {
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
   } else {
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, LOW);
   }
   analogWrite(motorAS, abs(speed));
}

void driveLeftMotor(int speed) {
   if (speed > 0) {
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
   } else if (speed < 0) {
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);
   } else {
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);
   }
   analogWrite(motorBS, abs(speed));
}