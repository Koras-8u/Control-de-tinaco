#include "main.h"

void setup() {
  // Set up serial monitor
  Serial.begin(115200);

  // Start pump
  pinMode(PUMPPIN, OUTPUT);
  millerPump.activates(false);
  Serial.println("-Pump is OFF");

  // Start sensor
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(CTRLOMITTER, INPUT);
  millerWaterTank.measureWaterLvl();
  Serial.println("-Water level sensor is ready!");

  // Start clock
  pumpClock.start();
}

void loop() {
  // Measure the water level every 3sec
  Serial.println(SERIAL_LINE);
  pumpClock.checksEvery(3000/*ms*/, updateWaterTankStatus);

  // Controller
  switch (waterTankStatus) {
    case EMPTY:
      emptyChecks++; // How many times the water tank has been detected as empty
      fullChecks = 0;
      // failChecks++;
      waterTankStatus = FINE;
      if (emptyChecks == 3) {
          pumpConfirmation = true;
          emptyChecks = 0;
      }
      break;
    case FULL:
      fullChecks++; // How many times the water tank has been detected as full
      emptyChecks = 0;
      // failChecks++;
      waterTankStatus = FINE;
      if (fullChecks == 3) {
          pumpConfirmation = false;
          fullChecks = 0;
      }
      break;
    default:
      break;
    }

  // Activates the pump
  millerPump.activates(pumpConfirmation);
}

void updateWaterTankStatus() {
  millerWaterTank.measureWaterLvl();
  waterTankStatus = millerWaterTank.getWaterTankStatus();
}