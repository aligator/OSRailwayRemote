#include <Arduino.h>

#include "Display.h"
#include "Mqtt.h"
#include "Web.h"
#include "config.h"

const char* ssid = WIFI_SSID;
const char* wiFiPassword = WIFI_PASSWD;
const char* hostname = WIFI_HOSTNAME;

const uint16_t otaPort = OTA_PORT;
const char* otaPassword = OTA_PASSWD;

// it did not work when putting this inside of the display class...
TFT_eSPI tft = TFT_eSPI(135, 240);

Web* web = new Web(ssid, wiFiPassword, hostname, otaPort, otaPassword);
Mqtt* mqtt = new Mqtt();
Display* display = new Display(&tft);

void setup() {
  Serial.begin(9600);
  web->setup();
  mqtt->setup();
  display->setup();
}

void loop() {
  web->loop();
  mqtt->loop();
  display->loop();
}