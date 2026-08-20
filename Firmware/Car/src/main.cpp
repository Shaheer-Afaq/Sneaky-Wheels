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

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
   memcpy(&myData, incomingData, sizeof(myData));
}

void setup() {
   Serial.begin(115200);
   WiFi.mode(WIFI_STA);
   esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);

   if (esp_now_init() != ESP_OK) {
      Serial.println("Error initializing ESP-NOW");
      return;
   }

   esp_now_register_recv_cb(OnDataRecv);


}

void loop() {}