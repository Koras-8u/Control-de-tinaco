#include "WaterTank.h"

// --------------------------------------------------
//                    CONSTRUCTORS                    
// --------------------------------------------------
WaterTank::WaterTank() {}

WaterTank::WaterTank(JSN_SR04T sensor) {
    WaterTank(sensor, 1400, 500); // Default height values
}

WaterTank::WaterTank(JSN_SR04T sensor, unsigned int water_tank_height, unsigned int min_water_distance) {
    this->sensor = sensor;
    this->water_tank_height = water_tank_height;
    this->min_water_distance = min_water_distance;
}

WaterTank::~WaterTank() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void WaterTank::measureWaterLvl() {
    sensor.measureDistance();

    // Constrain distance to max water height
    distance = constrain(sensor.getDistance(), min_water_distance, water_tank_height);
    // Serial.println("|\t-Constrained distance: " + String(distance) + " mm");

    // Calculate water level
    water_level = map(distance, water_tank_height, min_water_distance, 0, 100);
    Serial.println("|\t-Water level: " + String(water_level) + "%");

    changeStatus();
}

void WaterTank::changeStatus() {
    if (water_level >= 90) {
        status = 1;
        Serial.println("|\t-Water tank is full!");
    } else if (water_level > 10 && water_level < 90) {
        status = 2;
        Serial.println("|\t-Water is in use");
    } else if (water_level <= 10) {
        status = 0;
        Serial.println("|\t-Need to fill up water tank!");
    }
}

// --------------------------------------------------
//                 SETTERS & GETTERS                 
// --------------------------------------------------
void WaterTank::setWaterTankHeight(unsigned int water_tank_height) {
    this->water_tank_height = water_tank_height;
}

void WaterTank::setMinWaterDistance(unsigned int min_water_distance) {
    this->min_water_distance = min_water_distance;
}

bool WaterTank::getWaterTankStatus() {
    return status;
}