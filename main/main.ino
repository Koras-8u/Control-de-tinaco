#include "main.h"

void setup() {
  // Set up serial monitor
  Serial.begin(115200);

  // Start pump
  pinMode(PUMPPIN, OUTPUT);
  millerPump.pumpsWater(false);
  Serial.println("-Pump is OFF");

  // Start sensor
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  millerWaterTank.measureWaterLvl();
  Serial.println("-Water level sensor is ready!");
}

void loop() {
  // Measure the water level every 3sec
  if (millis() % 3000/*ms*/ == 0) {
    Serial.println("-Measuring water level...");
    millerWaterTank.measureWaterLvl();
    waterTankStatus = millerWaterTank.getWaterTankStatus();
  }

  // Controller
  switch (waterTankStatus) {
    case EMPTY:
      emptyChecks++; // How many times the water tank has been detected as empty
      fullChecks = 0;
      // failChecks++;
      waterTankStatus = FINE;
      if (emptyChecks == 5) {
        pumpConfirmation = true;
        emptyChecks = 0;
      }
      break;
    case FULL:
      fullChecks++; // How many times the water tank has been detected as full
      emptyChecks = 0;
      // failChecks++;
      waterTankStatus = FINE;
      if (fullChecks == 5) {
        pumpConfirmation = false;
        fullChecks = 0;
      }
      break;
    default:
      break;
  }

  // if (failChecks >= 10) {
  //   pumpConfirmation = false;
  //   failChecks = 0;
  //   Serial.println("-EXCEPTION: Sensor is not working properly!");
  // }

  // Activates the pump
  millerPump.pumpsWater(pumpConfirmation);
}