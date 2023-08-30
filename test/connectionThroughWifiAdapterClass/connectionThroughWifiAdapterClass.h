#ifndef connectionThroughWifiAdapterClass_h
#define connectionThroughWifiAdapterClass_h

#include "WifiAdapter.h"
#include "Relay.h"
#include <PubSubClient.h>

#define SERIAL_LINE "________________________________________"

// Actuator pins
#define RELAYPIN 13 // D7

void callback(char* topic, byte* payload, unsigned int length);

Relay someRelay(RELAYPIN);
WiFiClient espClient;
PubSubClient client("broker.emqx.io", 1883, callback, espClient);
WifiAdapter waterTankWifiAdapter("MEGACABLE-2.4G-CAA5", "T339FtCBVX", client);

#endif