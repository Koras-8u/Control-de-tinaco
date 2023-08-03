#ifndef main_h
#define main_h

#include "JSN_SR04T.h"
#include "Pump.h"

// Sensor pins
#define TRIGPIN 12
#define ECHOPIN 14

// Actuator pins
#define PUMPPIN 13

// Constructors
JSN_SR04T waterTank(TRIGPIN, ECHOPIN);
Pump millerPump(PUMPPIN);

// Water level variables
bool  waterTankState = LOW;

#endif