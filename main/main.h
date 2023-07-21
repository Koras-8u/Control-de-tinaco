#ifndef main_h
#define main_h

#include "CWaterMeter.h"

// Sensor pins
#define TRIGPIN 12
#define ECHOPIN 14

// Constructors
CWaterMeter tankMeter(TRIGPIN, ECHOPIN);

// Water level variables
float distance = 0.0;

#endif