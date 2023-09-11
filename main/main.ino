#include "main.h"

void setup()
{
  // Set up serial monitor
  Serial.begin(115200);

  // Start pump
  pinMode(PUMPPIN, OUTPUT);
  pump.activate(false);
  Serial.println("-Pump is OFF");

  // Start sensor
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(IGNORER, INPUT);
  waterTank.measureWaterLvl();
  Serial.println("-Water level sensor is ready!");

  // Start controller
  pumpController.init(waterTank.getWaterTankLevel());

  // Start clock
  sensorClock.start();

  // Start wifi
  wifiAdapter.connect2Wifi();
}

void loop()
{
  wifiAdapter.connect2Broker();
  client.loop();

  // Check the water tank status every 3 seconds
  sensorClock.checksEvery(3/*seconds*/, []()
  {
    Serial.println(SERIAL_LINE);

    // Measure and publish the water level
    waterTank.measureWaterLvl();
    wifiAdapter.publish("water-tank/level", waterTank.getWaterTankLevel());

    // Confirm if the water tank needs to be filled
    int waterTankLevel = waterTank.getWaterTankLevel();
    uint8_t waterTankStatus = waterTank.getWaterTankStatus();
    bool ignore = digitalRead(IGNORER);
    pumpController.validate(waterTankLevel, waterTankStatus, ignore);
    wifiAdapter.publish("water-tank/timer", pumpController.getTimer());
    
    // Activate the pump during 20 minutes and stop it if the water tank is full
    bool pumping =  pumpController.getValidation();
    pump.activate(pumping);
    wifiAdapter.publish("water-tank/pump", pumping? "ON" : "OFF");
  });
  
}

// --------------------------------------------------
//                   CALLBACKS
// --------------------------------------------------
void getMqttData(char *topic, byte *payload, unsigned int length)
{
  // Serial.print("Mensaje recibido [");
  // Serial.print(topic);
  // Serial.print("] ");
  // for (int i = 0; i < length; i++)
  // {
  //   Serial.print((char)payload[i]);
  // }
  // Serial.println();
}