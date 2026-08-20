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

#include "esp_wifi.h"
#include <WiFi.h>
#include <esp_now.h>


// MAC Address of responder
uint8_t broadcastAddress[] = {0x24, 0x6F, 0x28, 0x7A, 0xAE, 0x7C}; //dummy address

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
   int16_t x1;
   int16_t y1;
   boolean b1;
   int16_t x2;
   int16_t y2;
   boolean b2;
   int16_t p1;
   int16_t p2;
   boolean b3;
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

   WiFi.mode(WIFI_STA);
   esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);

   if (esp_now_init() != ESP_OK) {
      Serial.println("Error initializing ESP-NOW");
      return;
   }

   esp_now_register_send_cb(OnDataSent);

   // Register peer
   memcpy(peerInfo.peer_addr, broadcastAddress, 6);
   peerInfo.channel = 1;
   peerInfo.encrypt = false;

   // Add peer
   if (esp_now_add_peer(&peerInfo) != ESP_OK) {
      Serial.println("Failed to add peer");
      return;
   }
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

   esp_err_t result =
       esp_now_send(broadcastAddress, (uint8_t *)&myData, sizeof(myData));

   if (result == ESP_OK) {
      Serial.println("Sending confirmed");
   } else {
      Serial.println("Sending error");
   }
   delay(50);
}