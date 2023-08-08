#include "main.h"

void setup() {
  // Set up serial monitor
  Serial.begin(115200);

  // Set pinmodes for sensor connections
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(PUMPPIN, OUTPUT);

  mainTank.measureWaterLvl();
}

void loop() {
  // Measuring task
  if (millis() % 5000/*ms*/ == 0) {
    Serial.println("Measuring water level...");
    mainTank.measureWaterLvl(); // when 5sec has passed, measure water level
    waterTankState = mainTank.getWaterTankState();
  }
  
  // Rele Activation Task
  millerPump.pumpsWater(waterTankState);
}