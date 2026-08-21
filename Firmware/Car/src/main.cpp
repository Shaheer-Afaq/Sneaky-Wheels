// Run this first to get the MAC address of the ESP32
/*
#include "WiFi.h"

void setup() {

  // Setup Serial Monitor
  Serial.begin(115200);

  // Put ESP32 into Station mode
  WiFi.mode(WIFI_MODE_STA);

  // Print MAC Address to Serial monitor
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
}

void loop() {

}
*/

#include <WiFi.h>
#include <esp_now.h>
#include <esp_wifi.h>

#define motorA1 12
#define motorA2 13
#define motorAS 14

#define motorB1 26
#define motorB2 27
#define motorBS 25

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

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len);
void driveRightMotor(int speed);
void driveLeftMotor(int speed);

void setup() {
   Serial.begin(115200);

   pinMode(motorA1, OUTPUT);
   pinMode(motorA2, OUTPUT);
   pinMode(motorAS, OUTPUT);
   pinMode(motorB1, OUTPUT);
   pinMode(motorB2, OUTPUT);
   pinMode(motorBS, OUTPUT);
   pinMode(headlight, OUTPUT);

   WiFi.mode(WIFI_STA);
   esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);

   if (esp_now_init() != ESP_OK) {
      Serial.println("Error initializing ESP-NOW");
      return;
   }
   esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
   // stop the car if the connection is lost for more than 300ms
   if (millis() - lastPacketTime > 300) {
      driveRightMotor(0);
      driveLeftMotor(0);
      digitalWrite(headlight, LOW);
      return;
   }

   sensitivity = map(myData.p1, 0, 4095, 30, 90);

   int throttle, steering;
   if (myData.b1) { // if gyro mode is enabled
      throttle = constrain(map(myData.aX, -sensitivity, sensitivity, -255, 255), -255, 255);
      steering = constrain(map(myData.aY, -sensitivity, sensitivity, -255, 255), -255, 255);
   } else {
      throttle = map(myData.y1, 0, 4095, -255, 255);
      steering = map(myData.x2, 0, 4095, -255, 255);
   }

   int rightSpeed, leftSpeed;
   if (abs(throttle) < 20) { // for spinning in place
      rightSpeed = -steering;
      leftSpeed = steering;
   } else {
      rightSpeed = throttle;
      leftSpeed = throttle;
      // to reduce the speed of one motor based on steering strength and direction
      if (steering > 20) rightSpeed = throttle * (255 - steering) / 255;
      else if (steering < -20) leftSpeed = throttle * (255 + steering) / 255;
   }
   driveRightMotor(rightSpeed);
   driveLeftMotor(leftSpeed);

   // toggle headlight
   if (myData.b3) lightButtonWasPressed = true;

   if (lightButtonWasPressed && !myData.b3) {
      lightOn = !lightOn;
      lightButtonWasPressed = false;
      digitalWrite(headlight, lightOn);
   }
}

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
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