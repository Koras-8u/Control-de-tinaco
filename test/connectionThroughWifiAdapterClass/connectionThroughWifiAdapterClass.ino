#include "connectionThroughWifiAdapterClass.h"

void setup() {
    pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
    Serial.begin(115200);
    waterTankWifiAdapter.connect();
}

void loop() {

}