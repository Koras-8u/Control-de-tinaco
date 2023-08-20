#ifndef connectionThroughWifiAdapterClass_h
#define connectionThroughWifiAdapterClass_h

#include "WifiAdapter.h"
#include "Relay.h"

#define SERIAL_LINE "________________________________________"

// Actuator pins
#define RELAYPIN 13 // D7

// Credentials
// const char* mqtt_server = "test.mosquitto.org";

Relay someRelay(RELAYPIN);
WifiAdapter waterTankWifiAdapter("MEGACABLE-2.4G-CAA5", "T339FtCBVX");

#endif