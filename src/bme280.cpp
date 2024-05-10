#include "bme280.h"

Adafruit_BME280 bme;

void setupBME280() {
  if (!bme.begin(BME280_ADDRESS)) {
    Serial.println("No se pudo encontrar el sensor, revisa las conexiones!");
    Serial.println("Intentando con la otra dirección...");
    
    if (!bme.begin(BME280_ADDRESS + 1)) {
      Serial.println("No se pudo encontrar el sensor en ninguna dirección, revisa las conexiones o cambia la dirección en el código.");
      while (1);
    }
  }
}

float readTemperature() {
  return bme.readTemperature();
}

float readHumidity() {
  return bme.readHumidity();
}

float readPressure() {
  return bme.readPressure();
}

float readAltitude() {
  return bme.readAltitude(SEALEVELPRESSURE_HPA);
}
