#include <Arduino.h>
#include "bme280.h"
#include "wifi_helper.h"
#include "mqtt_helper.h"

const char* ssid1 = "504";         // Nombre de tu primera red WiFi
const char* password1 = "cardenas16V";     // Contraseña de tu primera red WiFi
const char* ssid2 = "Casa CV";         // Nombre de tu segunda red WiFi
const char* password2 = "cardenas16VC2";     // Contraseña de tu segunda red WiFi

const char* mqttBroker = "192.168.68.62";   // Dirección IP o nombre del broker MQTT
int mqttPort = 1883;                        // Puerto MQTT (por defecto es 1883)
const char* mqttClientId = "esp32_client";
const char* mqttTopic = "sensor/data";

void setup() {
  Serial.begin(115200);
  Serial.println(F("BME280 test"));

  // Conectar a las redes WiFi
  connectToWiFi(ssid1, password1, ssid2, password2);

  // Conectar al servidor MQTT
  connectToMQTT(mqttBroker, mqttPort, mqttClientId, mqttTopic);
  
  // Inicializar el sensor BME280
  setupBME280();
}

void loop() {
  // Leer datos del sensor
  float temperature = readTemperature();
  float humidity = readHumidity();
  float pressure = readPressure();
  float altitude = readAltitude();

  // Formatear los datos del sensor en un formato JSON
  char payload[100];
  snprintf(payload, sizeof(payload), "{\"temperature\":%.2f,\"humidity\":%.2f,\"pressure\":%.2f,\"altitude\":%.2f}", temperature, humidity, pressure, altitude);

  // Publicar los datos por MQTT
  publishMessage(mqttTopic, payload);

  // Esperar antes de la siguiente lectura y publicación
  delay(5000);
}
