#include "managePublications.h"

void setup()
{
    // Set up serial monitor
    Serial.begin(115200);

    // Start sensor
    // pinMode(ECHOPIN, INPUT);
    // pinMode(TRIGPIN, OUTPUT);
    // pinMode(IGNORER, INPUT);
    // millerWaterTank.measureWaterLvl();
    // Serial.println("-Water level sensor is ready!");

    // Start clock
    millerPumpClock.start();

    // Start wifi
    waterTankWifiAdapter.connect2Wifi();
}

void loop()
{
    waterTankWifiAdapter.connect2Broker();
    client.loop();

    millerPumpClock.checksEvery(3000 /*ms*/, []() {
        client.publish("water-tank/level", "20");
    });
    // Measure the water level every 3sec
    // millerPumpClock.checksEvery(3000 /*ms*/, updateWaterTankStatus);
}

// --------------------------------------------------
//                   CALLBACKS
// --------------------------------------------------
// void updateWaterTankStatus()
// {
//     Serial.println(SERIAL_LINE);
//     millerWaterTank.measureWaterLvl();
//     waterTankStatus = millerWaterTank.getWaterTankStatus();
// }

void getMqttData(char *topic, byte *payload, unsigned int length)
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