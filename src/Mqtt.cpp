#include "Mqtt.h"

#include <functional>

#include "Util.h"

#define TOPIC_REMOTE "/OSRailway/remote"

/**
 * converts bytes to a String
 */
String Mqtt::_byte2str(byte* data, unsigned int length) {
  char* buffer = (char*)malloc(length + 1);
  memcpy(buffer, data, length);
  buffer[length] = 0;

  // or for unicode:
  // const char* str((const wchar_t*)buffer);
  String out = String((const char*)buffer);
  free(buffer);
  return out;
}

void Mqtt::_receiveCallback(char* topic, byte* payload, unsigned int length) {
  String message = Mqtt::_byte2str(payload, length);
  String topicString = String(topic);

  if (topicString.equals(TOPIC_REMOTE)) {
    Serial.println(TOPIC_REMOTE " called");
    Serial.println(message);
  }
  return;
}

Mqtt::Mqtt() { this->client = PubSubClient(this->espClient); }

Mqtt::~Mqtt() {}

void Mqtt::setup() {
  delay(100);
  this->client.setServer(broker, port);
  this->client.setCallback(
      std::bind(&Mqtt::_receiveCallback, this, std::placeholders::_1,
                std::placeholders::_2, std::placeholders::_3));
}

void Mqtt::_reconnect() {
  if (!this->client.connected()) {
    Serial.println("Reconnecting...");

    String clientId = WIFI_HOSTNAME "-";
    clientId += String(random(0xffff), HEX);
    this->client.setKeepAlive(10);

    // Attempt to connect
    if (!this->client.connect(clientId.c_str(), user, password)) {
      Serial.print("failed, rc=");
      Serial.println(client.state());
    } else {
      Serial.println("Connected");
      delay(100);
      this->client.subscribe(TOPIC_REMOTE);
    }
  }
}

void Mqtt::loop() {
  if (!this->client.connected()) {
    delay(1000);
    _reconnect();
  } else {
    this->client.loop();
  }
}