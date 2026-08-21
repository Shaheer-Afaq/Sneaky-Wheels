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

bool gyroModeOn = false;
bool headlightOn = false;

const int turnRadius = 10;

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len);

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
   gyroModeOn = myData.b1;

   if (gyroModeOn) {

   } else {
      int throttle = map(myData.y1, 0, 4095, -255, 255);
      int steering = map(myData.x2, 0, 4095, -255, 255);
      int rightSpeed, leftSpeed;

      if (throttle < 20){
         rightSpeed = -steering;
         leftSpeed = steering;
      } else {
         rightSpeed = throttle;
         leftSpeed = throttle;

         if (steering > 20) {
            rightSpeed = throttle * (255 - steering) / 255;
         } else if (steering < -20) {
            leftSpeed = throttle * (255 + steering) / 255;
         }
      }
   }
}

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
   memcpy(&myData, incomingData, sizeof(myData));
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