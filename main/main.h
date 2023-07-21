#ifndef main_h
#define main_h

#include "CWaterMeter.h"
#include "CPump.h"

// Sensor pins
#define TRIGPIN 12
#define ECHOPIN 14

// Actuator pins
#define PUMPPIN 13

// Constructors
CWaterMeter millerWaterTank(TRIGPIN, ECHOPIN);
CPump millerPump(PUMPPIN);

// Water level variables
bool  waterTankState = LOW;

#endif