#include "esp_camera.h"

#include <WiFi.h>

#define CAMERA_MODEL_AI_THINKER // Has PSRAM

#include "camera_pins.h"

// ===========================

// Enter your WiFi credentials

// ===========================

const char *ssid = "spycar";

const char *password = "1234";

void startCameraServer();

void setup() {

   Serial.begin(115200);

   Serial.setDebugOutput(true);

   Serial.println();

   camera_config_t config;

   config.ledc_channel = LEDC_CHANNEL_0;

   config.ledc_timer = LEDC_TIMER_0;

   config.pin_d0 = Y2_GPIO_NUM;

   config.pin_d1 = Y3_GPIO_NUM;

   config.pin_d2 = Y4_GPIO_NUM;

   config.pin_d3 = Y5_GPIO_NUM;

   config.pin_d4 = Y6_GPIO_NUM;

   config.pin_d5 = Y7_GPIO_NUM;

   config.pin_d6 = Y8_GPIO_NUM;

   config.pin_d7 = Y9_GPIO_NUM;

   config.pin_xclk = XCLK_GPIO_NUM;

   config.pin_pclk = PCLK_GPIO_NUM;

   config.pin_vsync = VSYNC_GPIO_NUM;

   config.pin_href = HREF_GPIO_NUM;

   config.pin_sscb_sda = SIOD_GPIO_NUM;

   config.pin_sscb_scl = SIOC_GPIO_NUM;

   config.pin_pwdn = PWDN_GPIO_NUM;

   config.pin_reset = RESET_GPIO_NUM;

   config.xclk_freq_hz = 20000000;

  //  config.pixel_format = PIXFORMAT_RGB565;    // for face detection/recognition
   config.pixel_format = PIXFORMAT_GRAYSCALE; // for face detection/recognition

   config.frame_size = FRAMESIZE_QVGA;
   //  config.frame_size = FRAMESIZE_240X240;

   config.fb_location = CAMERA_FB_IN_PSRAM;

   config.fb_count = 2;

   config.grab_mode = CAMERA_GRAB_LATEST;
   // camera init

   esp_err_t err = esp_camera_init(&config);

   if (err != ESP_OK) {

      Serial.printf("Camera init failed with error 0x%x", err);

      return;
   }

   sensor_t *s = esp_camera_sensor_get();
   if (s != NULL) {
      s->set_vflip(s, 1);                    // 1 = Flip image vertically (upside down fix)
      s->set_hmirror(s, 1);                  // 1 = Mirror image horizontally
      s->set_brightness(s, 2);               // Range: -2 to 2
      s->set_contrast(s, 0);                 // Range: -2 to 2
      s->set_saturation(s, 2);               // Range: -2 to 2
      s->set_whitebal(s, 1);                 // 1 = Auto White Balance ON
      s->set_awb_gain(s, 1);                 // 1 = Auto White Balance Gain ON
      s->set_exposure_ctrl(s, 1);            // 1 = Auto Exposure ON
      s->set_gainceiling(s, GAINCEILING_2X); // Prevents excessive noise
   }

   WiFi.softAP(ssid);

   WiFi.setSleep(false);

   Serial.println("");

   Serial.println("WiFi AP started");

   startCameraServer();

   Serial.print("Camera Ready! Use 'http://");

   Serial.print(WiFi.softAPIP());

   Serial.println("' to connect");
}

void loop() {

   delay(10000);
}
