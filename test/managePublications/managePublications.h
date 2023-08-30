#ifndef managePublications_h
#define managePublications_h

// #include "WaterTank.h"
// #include "TaskManagerClock.h"
#include "WifiAdapter.h"
#include <PubSubClient.h>

#define SERIAL_LINE "________________________________________"

// Sensor pins
#define TRIGPIN 12 // D6
#define ECHOPIN 14 // D5

// Credentials
const char *ssid = "MEGACABLE-2.4G-CAA5";
const char *pass = "T339FtCBVX";
const char *mqtt_server = "test.mosquitto.org";

// Water tank Specs
// #define WATER_TANK_HEIGHT 1400 // mm
// #define MIN_WATER_DISTANCE 500 // mm

// Callbacks
void updateWaterTankStatus(void);
void getMqttData(char *topic, byte *payload, unsigned int length);

// Components
// JSN_SR04T millerSensor(TRIGPIN, ECHOPIN);
// WaterTank millerWaterTank(millerSensor, WATER_TANK_HEIGHT, MIN_WATER_DISTANCE);
WiFiClient espClient;
PubSubClient client("broker.emqx.io", 1883, getMqttData, espClient);
WifiAdapter waterTankWifiAdapter("MEGACABLE-2.4G-CAA5", "T339FtCBVX", client);

// Operators
// Water tank
// uint8_t waterTankStatus = FULL; // 0 = EMPTY, 1 = FULL, 2 = FINE

#endif