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
  wifiClock.start();

  // Start wifi
  wifiManager.begin();
}

void loop()
{
  // Check the wifi and the broker every minute
  wifiClock.checksEvery(1, MIN, []() {
    wifiManager.connect2Wifi();
    wifiManager.connect2Broker();
    wifiManager.publish("water-tank/ad", "Still alive!");
  });

  client.loop();

  // Check the water tank status every 3 seconds
  sensorClock.checksEvery(3/*seconds*/, []()
  {
    Serial.println(SERIAL_LINE);

    // Measure and publish the water level
    waterTank.measureWaterLvl();
    wifiManager.publish("water-tank/level", waterTank.getWaterTankLevel());

    // Confirm if the water tank needs to be filled
    int waterTankLevel = waterTank.getWaterTankLevel();
    uint8_t waterTankStatus = waterTank.getWaterTankStatus();
    bool ignore = digitalRead(IGNORER);
    wifiManager.publish("water-tank/ignore", ignore ? "TRUE" : "FALSE");
    pumpController.validate(waterTankLevel, waterTankStatus, ignore);
    wifiManager.publish("water-tank/timer", pumpController.getTimer());
    
    // Activate the pump during 20 minutes and stop it if the water tank is full
    bool pumping =  pumpController.getValidation();
    pump.activate(pumping);
    wifiManager.publish("water-tank/pump", pumping? "ON" : "OFF");
  });
  
}

// --------------------------------------------------
//                   CALLBACKS
// --------------------------------------------------
void rebootThroughMqtt(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // reboot the device
  if ((char)payload[0] == '1') {
    ESP.restart();
  } else {
    Serial.println("Invalid command");
  }
}