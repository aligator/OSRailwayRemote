#ifndef CONFIG_H_
#define CONFIG_H_

#define MQTT_BROKER "192.168.178.53"
#define MQTT_PORT 1883
#define MQTT_USER "...."
#define MQTT_PASSWD "...."

#define WIFI_SSID "...."
#define WIFI_PASSWD "...."

// used to create the mdns <hostname>.local
// (e.g. can be used for the ota update)
#define WIFI_HOSTNAME "os-railway-train1"

#define OTA_PASSWD "....."
#define OTA_PORT 8266

#endif /* CONFIG_H_ */