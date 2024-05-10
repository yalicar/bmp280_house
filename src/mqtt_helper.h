#ifndef MQTT_HELPER_H
#define MQTT_HELPER_H

#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

extern WiFiClient espClient;
extern PubSubClient mqttClient;

void connectToMQTT(const char* broker, int port, const char* clientId, const char* topic);
void publishMessage(const char* topic, const char* payload);
void callback(char* topic, byte* payload, unsigned int length);

#endif
