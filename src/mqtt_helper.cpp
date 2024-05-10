#include "mqtt_helper.h"

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void connectToMQTT(const char* broker, int port, const char* clientId, const char* topic) {
  mqttClient.setServer(broker, port);
  mqttClient.setCallback(callback);

  while (!mqttClient.connected()) {
    Serial.print("Conectando al servidor MQTT...");
    if (mqttClient.connect(clientId)) {
      Serial.println("Conexión exitosa al servidor MQTT");
      mqttClient.subscribe(topic);
    } else {
      Serial.print("Fallo al conectar al servidor MQTT, rc=");
      Serial.println(mqttClient.state());
      Serial.println("Intentando nuevamente en 5 segundos");
      delay(5000);
    }
  }
}

void publishMessage(const char* topic, const char* payload) {
  mqttClient.publish(topic, payload);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido en el topic: ");
  Serial.println(topic);
  Serial.print("Contenido del mensaje: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
