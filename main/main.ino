#include "main.h"

void setup()
{
  // Set up serial monitor
  Serial.begin(115200);

  // Start pump
  pinMode(PUMPPIN, OUTPUT);
  millerPump.activate(false);
  Serial.println("-Pump is OFF");

  // Start sensor
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(IGNORER, INPUT);
  millerWaterTank.measureWaterLvl();
  Serial.println("-Water level sensor is ready!");

  // Start controller
  millerPumpController.init(millerWaterTank.getWaterTankLevel());

  // Start clock
  millerPumpClock.start();

  // Start wifi
  waterTankWifiAdapter.connect2Wifi();
}

void loop()
{
  waterTankWifiAdapter.connect2Broker();
  client.loop();

  // Check the water tank status every 3 seconds
  millerPumpClock.checksEvery(3000 /*ms*/, []()
  {
    Serial.println(SERIAL_LINE);

    // Measure and publish the water level
    millerWaterTank.measureWaterLvl();
    waterTankWifiAdapter.publish(millerWaterTank.getWaterTankLevel());

    // Confirm if the water tank needs to be filled
    int waterTankLevel = millerWaterTank.getWaterTankLevel();
    uint8_t waterTankStatus = millerWaterTank.getWaterTankStatus();
    bool ignore = digitalRead(IGNORER);
    millerPumpController.validate(waterTankLevel, waterTankStatus, ignore);

    // Activate the pump
    millerPump.activate(millerPumpController.getValidation());
  });
}

// --------------------------------------------------
//                   CALLBACKS
// --------------------------------------------------
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