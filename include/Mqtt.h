#ifndef MQTT_H_
#define MQTT_H_

#include <PubSubClient.h>
#include <WiFi.h>

#include <vector>

#include "Arduino.h"
#include "Web.h"
#include "config.h"

class Mqtt {
 public:
  Mqtt();
  virtual ~Mqtt();

  void setup();
  void loop();

 private:
  const char* broker = (char*)MQTT_BROKER;
  const uint port = MQTT_PORT;
  const char* user = (char*)MQTT_USER;
  const char* password = (char*)MQTT_PASSWD;

  WiFiClient espClient;
  PubSubClient client;

  void _receiveCallback(char* topic, byte* payload, unsigned int length);
  void _reconnect();

  static String _byte2str(byte* data, unsigned int length);
};

#endif /* MQTT_H_ */