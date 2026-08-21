#include "esp_wifi.h"
#include <WiFi.h>
#include <esp_now.h>

#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);

uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

#define joy1x 34
#define joy1y 35
#define joy1b 14
#define joy2x 32
#define joy2y 33
#define joy2b 13

#define pot1 36
#define pot2 39

#define button 23

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
esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
   Serial.print("\r\nLast Packet Send Status:\t");
   Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success"
                                                 : "Delivery Fail");
}

void setup() {
   Serial.begin(115200);
   pinMode(joy1b, INPUT_PULLUP);
   pinMode(joy2b, INPUT_PULLUP);
   pinMode(button, INPUT_PULLUP);

   // ESP-NOW Setup
   WiFi.mode(WIFI_STA);
   esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);

   if (esp_now_init() != ESP_OK) {
      Serial.println("Error initializing ESP-NOW");
      return;
   }

   esp_now_register_send_cb(OnDataSent);

   memcpy(peerInfo.peer_addr, broadcastAddress, 6);
   peerInfo.channel = 1;
   peerInfo.encrypt = false;

   if (esp_now_add_peer(&peerInfo) != ESP_OK) {
      Serial.println("Failed to add peer");
      return;
   }

   // MPU6050 Setup
   Wire.begin();
   mpu.begin();
   mpu.calcOffsets();
}

void loop() {
   myData.x1 = analogRead(joy1x);
   myData.y1 = analogRead(joy1y);
   myData.b1 = !digitalRead(joy1b);
   myData.x2 = analogRead(joy2x);
   myData.y2 = analogRead(joy2y);
   myData.b2 = !digitalRead(joy2b);
   myData.p1 = analogRead(pot1);
   myData.p2 = analogRead(pot2);
   myData.b3 = !digitalRead(button);

   mpu.update();
   myData.aX = mpu.getAngleX();
   myData.aY = mpu.getAngleY();
   myData.aZ = mpu.getAngleZ();

   esp_err_t result =
       esp_now_send(broadcastAddress, (uint8_t *)&myData, sizeof(myData));

   if (result == ESP_OK) {
      Serial.println("Sending confirmed");
   } else {
      Serial.println("Sending error");
   }
   delay(40);
}