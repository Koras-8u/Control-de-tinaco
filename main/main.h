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

// Components
JSN_SR04T millerSensor(TRIGPIN, ECHOPIN);
WaterTank millerWaterTank(millerSensor, WATER_TANK_HEIGHT, MIN_WATER_DISTANCE);
Pump millerPump(PUMPPIN);

// Operators
    // Water tank
    uint8_t waterTankStatus = FULL; // 0 = EMPTY, 1 = FULL, 2 = FINE
    // Controller
    unsigned int fullChecks = 0;
    unsigned int emptyChecks = 0;
    // unsigned int failChecks = 0;
    bool pumpConfirmation = false;

#endif