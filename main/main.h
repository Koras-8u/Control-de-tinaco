#ifndef main_h
#define main_h

#include "JSN_SR04T.h"
#include "Pump.h"
#include "WifiAdapter.h"

// Sensor pins
#define TRIGPIN 12
#define ECHOPIN 14

// Actuator pins
#define PUMPPIN 13

// Credentials
const char* ssid = "MEGACABLE-2.4G-CAA5";
const char* pass = "T339FtCBVX";

// mDash
char* deviceKey = "22FqcOwyO6IUN0BmCYK9099g";

// Constructors
JSN_SR04T mainTank(TRIGPIN, ECHOPIN);
Pump millerPump(PUMPPIN);
WifiAdapter waterTank();

// Water level variables
bool  waterTankState = LOW;

#endif