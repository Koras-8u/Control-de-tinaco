#include "main.h"

void setup() {
  // Set up serial monitor
  Serial.begin(115200);

  // Start pump
  pinMode(PUMPPIN, OUTPUT);
  millerPump.activate(false);
  Serial.println("-Pump is OFF");

  // Start sensor
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(IGNORER, INPUT);
  millerWaterTank.measureWaterLvl();
  Serial.println("-Water level sensor is ready!");

  // Start clock
  millerPumpClock.start();
}

void loop() {
  // Measure the water level every 3sec
  millerPumpClock.checksEvery(3000/*ms*/, updateWaterTankStatus);

  // Confirm if the water tank needs to be filled
  millerPumpController.ignoreValidations(IGNORER);
  waterTankStatus = millerPumpController.validations(waterTankStatus);
  bool pumpConfirmation = millerPumpController.getConfirmation();

  // Activate the pump
  millerPump.activate(pumpConfirmation);
}

void updateWaterTankStatus() {
  Serial.println(SERIAL_LINE);
  millerWaterTank.measureWaterLvl();
  waterTankStatus = millerWaterTank.getWaterTankStatus();
}