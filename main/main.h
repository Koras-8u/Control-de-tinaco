#ifndef main_h
#define main_h

#include "WaterTank.h"
#include "Relay.h"
#include "PumpController.h"
#include "TaskManagerClock.h"
#include "WifiAdapter.h"

#define SERIAL_LINE "________________________________________"

// Sensor pins
#define TRIGPIN 12 // D6
#define ECHOPIN 14 // D5
    // Omisor de sensor
    #define IGNORER 5 // D1

// Actuator pins
#define PUMPPIN 13 // D7

// Credentials
const char* ssid = "MEGACABLE-2.4G-CAA5";
const char* pass = "T339FtCBVX";
const char* mqtt_server = "test.mosquitto.org";

// Water tank Specs
#define WATER_TANK_HEIGHT 1400 // mm
#define MIN_WATER_DISTANCE 500 // mm

// Components
JSN_SR04T millerSensor(TRIGPIN, ECHOPIN);
WaterTank millerWaterTank(millerSensor, WATER_TANK_HEIGHT, MIN_WATER_DISTANCE);
Relay millerPump(PUMPPIN, "Pump");
//TaskManagerClock fillingClock;
TaskManagerClock millerPumpClock;
PumpController millerPumpController;
//WifiAdapter waterTankWifiAdapter;

// Operators
    // Water tank
    uint8_t waterTankStatus = FULL; // 0 = EMPTY, 1 = FULL, 2 = FINE

#endif