#include "main.h"

void setup() {
  // Set up serial monitor
  Serial.begin(115200);

  // Start pump
  pinMode(PUMPPIN, OUTPUT);
  millerPump.pumpsWater(true);
  Serial.println("-Pump is OFF");

  // Start sensor
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  waterTank.measureWaterLvl();
  Serial.println("-Water level sensor is ready!");
}

void loop() {
  // Measuring task
  if (millis() % 3000/*ms*/ == 0) {
    Serial.println("-Measuring water level...");
    waterTank.measureWaterLvl(); // when 3sec has passed, measure water level
    waterTankState = waterTank.getWaterTankState();
  }
  
  // Rele Activation Task
  millerPump.pumpsWater(waterTankState);
}