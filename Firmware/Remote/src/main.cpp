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

// MAC Address of responder
uint8_t broadcastAddress[] = {0x24, 0x6F, 0x28, 0x7A, 0xAE, 0x7C};

#define joy1x 34;
#define joy1y 35;
#define joy1s 14;
#define joy2x 32;
#define joy2y 33;
#define joy2s 13;

#define pot1 36;
#define pot2 39;

#define button 23;

// Define a data structure
typedef struct struct_message {

} struct_message;

struct_message myData;
esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
   Serial.print("\r\nLast Packet Send Status:\t");
   Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success"
                                                 : "Delivery Fail");
}

void setup() {
   Serial.begin(115200);
   pinMode(23, INPUT_PULLUP);

   WiFi.mode(WIFI_STA);

   if (esp_now_init() != ESP_OK) {
      Serial.println("Error initializing ESP-NOW");
      return;
   }

   esp_now_register_send_cb(OnDataSent);

   // Register peer
   memcpy(peerInfo.peer_addr, broadcastAddress, 6);
   peerInfo.channel = 0;
   peerInfo.encrypt = false;

   // Add peer
   if (esp_now_add_peer(&peerInfo) != ESP_OK) {
      Serial.println("Failed to add peer");
      return;
   }
}

void loop() {


   esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)&myData, sizeof(myData));

   if (result == ESP_OK) {
      Serial.println("Sending confirmed");
   } else {
      Serial.println("Sending error");
   }
   delay(50);
}