#ifndef connectionThroughWifiAdapterClass_h
#define connectionThroughWifiAdapterClass_h

#include "WifiAdapter.h"
#include "Relay.h"
#include <PubSubClient.h>

#define SERIAL_LINE "________________________________________"

// Actuator pins
#define RELAYPIN 13 // D7

Relay someRelay(RELAYPIN);

WiFiClient espClient;
PubSubClient client(espClient);
WifiAdapter waterTankWifiAdapter("MEGACABLE-2.4G-CAA5", "T339FtCBVX", "test.mosquitto.org", client);

#endif