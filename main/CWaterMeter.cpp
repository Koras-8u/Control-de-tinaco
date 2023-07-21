#include "CWaterMeter.h"

// --------------------------------------------------
//                    CONSTRUCTORS                    
// --------------------------------------------------
CWaterMeter::CWaterMeter() {}

CWaterMeter::CWaterMeter(uint8_t trig_pin, uint8_t echo_pin) {
    this->trig_pin = trig_pin;
    this->echo_pin = echo_pin;
}

CWaterMeter::~CWaterMeter() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void CWaterMeter::measureWaterLvl() {
    measureDistance();
    water_level = map(distance, water_tank_height, sensor_min_distance, 0, 100);
    Serial.println("|\tWater level: " + String(water_level) + "%");
    setWaterTankState();
}

void CWaterMeter::measureDistance() {
    // Set the trigger pin LOW for 2us
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);

    // Set the trigger pin HIGH for 20us to send pulse
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(20);

    // Return the trigger pin to LOW
    digitalWrite(trig_pin, LOW);

    // Measure the width of the incoming pulse
    duration = pulseIn(echo_pin, HIGH); // us

    // Determine distance from duration
    // Use 343 metres per second as speed of sound
    // Divide by 1000 as we want millimeters
    distance = (duration*SOUND_SPEED/1000)/2;
    //distance = constrain(distance, sensor_min_distance, water_tank_height);

    // Print result to serial monitor
    Serial.println("|\t|\tDistance: " + String(distance) + " mm");
}

void CWaterMeter::setWaterTankState() {
    if (water_level > 90) {
        water_tank_state = LOW;
        Serial.println("|\t|\tWater tank is full!");
    } else if (water_level < 10) {
        water_tank_state = HIGH;
        Serial.println("|\t|\tNeed to fill up water tank!");
    }
}

// --------------------------------------------------
//                 GETTERS & SETTERS                 
// --------------------------------------------------
unsigned int CWaterMeter::getDistance() {
    return distance;
}

bool CWaterMeter::getWaterTankState() {
    return water_tank_state;
}