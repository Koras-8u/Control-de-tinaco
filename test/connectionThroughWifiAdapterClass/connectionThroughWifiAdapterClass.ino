#include "connectionThroughWifiAdapterClass.h"

void setup()
{
    pinMode(BUILTIN_LED, OUTPUT); // Initialize the BUILTIN_LED pin as an output
    Serial.begin(115200);
    waterTankWifiAdapter.connect2Wifi();
}

void loop()
{
    waterTankWifiAdapter.connect2Broker();
    client.loop();
}

void callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Mensaje recibido [");
    Serial.print(topic);
    Serial.print("] ");
    for (int i = 0; i < length; i++)
    {
        Serial.print((char)payload[i]);
    }
    Serial.println();
}