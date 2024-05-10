#include "wifi_helper.h"

void connectToWiFi(const char* ssid1, const char* password1, const char* ssid2, const char* password2) {
  Serial.println("Conectando a la red WiFi...");

  // Intenta conectarse a la primera red WiFi
  WiFi.begin(ssid1, password1);
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 10) {
    delay(1000);
    Serial.println("Intentando conectar a la red WiFi 1...");
    attempts++;
  }

  // Si no se conecta a la primera red, intenta la segunda
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid2, password2);
    attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 10) {
      delay(1000);
      Serial.println("Intentando conectar a la red WiFi 2...");
      attempts++;
    }
  }
  
  // Si está conectado a alguna red WiFi, muestra la dirección IP
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Conexión exitosa!");
    Serial.print("Dirección IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Error al conectar a ninguna de las redes WiFi.");
    while (1);
  }
}
