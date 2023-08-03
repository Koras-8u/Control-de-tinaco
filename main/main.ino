#include "main.h"

void setup() {
  // Set up serial monitor
  Serial.begin(115200);

  // Set pinmodes for sensor connections
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(PUMPPIN, OUTPUT);

  waterTank.measureWaterLvl();
}

void loop() {
  // Measuring task
  if (millis() % 5000/*ms*/ == 0) {
    Serial.println("Measuring water level...");
    waterTank.measureWaterLvl(); // when 10sec has passed, measure water level
    waterTankState = waterTank.getWaterTankState();
  }
  
  // Rele Activation Task
  millerPump.pumpsWater(waterTankState);
}