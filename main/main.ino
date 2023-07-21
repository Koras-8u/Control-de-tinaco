#include "main.h"

void setup() {
  // Set up serial monitor
  Serial.begin(115200);

  // Set pinmodes for sensor connections
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

void loop() {
  if (millis() % 10000 == 0) tankMeter.measureWaterLvl();

  distance = tankMeter.getDistance();
}