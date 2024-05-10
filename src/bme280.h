#ifndef BME280_H
#define BME280_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25) // Presión al nivel del mar
#define BME280_ADDRESS 0x76 // Dirección predeterminada del sensor BME280

extern Adafruit_BME280 bme;

void setupBME280();
float readTemperature();
float readHumidity();
float readPressure();
float readAltitude();

#endif
