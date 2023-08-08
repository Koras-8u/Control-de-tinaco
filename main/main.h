#ifndef main_h
#define main_h

#include "WaterTank.h"
#include "Pump.h"

// Sensor pins
#define TRIGPIN 12
#define ECHOPIN 14

// Actuator pins
#define PUMPPIN 13

// Water tank Specs
#define WATER_TANK_HEIGHT 1400 // mm
#define MIN_WATER_DISTANCE 500 // mm

// Constructors
JSN_SR04T millerSensor(TRIGPIN, ECHOPIN);
WaterTank millerWaterTank(millerSensor, WATER_TANK_HEIGHT, MIN_WATER_DISTANCE);
Pump millerPump(PUMPPIN);

// Water level variables
bool waterTankStatus = HIGH;

#endif