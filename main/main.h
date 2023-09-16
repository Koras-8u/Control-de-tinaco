#ifndef main_h
#define main_h

#include "WaterTank.h"
#include "Relay.h"
#include "PumpController.h"
#include "TaskManagerClock.h"
#include "WifiManager.h"
#include <PubSubClient.h>

#define SERIAL_LINE "________________________________________"

// Sensor pins
#define TRIGPIN 12 // D6
#define ECHOPIN 14 // D5
// Omisor de sensor
#define IGNORER 5 // D1

// Actuator pins
#define PUMPPIN 13 // D7

// Water tank Specs
#define WATER_TANK_HEIGHT 1400 // mm
#define MIN_WATER_DISTANCE 500 // mm

// Callbacks
void rebootThroughMqtt(char *topic, byte *payload, unsigned int length);

// Components
JSN_SR04T sensor(TRIGPIN, ECHOPIN);
WaterTank waterTank(sensor, WATER_TANK_HEIGHT, MIN_WATER_DISTANCE);
WiFiClient espClient;
PubSubClient client("broker.emqx.io", 1883, rebootThroughMqtt, espClient);
WifiManager wifiManager("MEGACABLE-2.4G-CAA5", "T339FtCBVX", client);
Relay pump(PUMPPIN, "Pump");
PumpController pumpController;
TaskManagerClock sensorClock, wifiClock;

#endif