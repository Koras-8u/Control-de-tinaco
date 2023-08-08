#include "JSN_SR04T.h"

// --------------------------------------------------
//                    CONSTRUCTORS                    
// --------------------------------------------------
JSN_SR04T::JSN_SR04T() {}

JSN_SR04T::JSN_SR04T(uint8_t trig_pin, uint8_t echo_pin) {
    this->trig_pin = trig_pin;
    this->echo_pin = echo_pin;
}

JSN_SR04T::~JSN_SR04T() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void JSN_SR04T::measureWaterLvl() {
    measureDistance();
    water_level = map(distance, water_tank_height, min_func_distance, 0, 100);
    Serial.println("|\tWater level: " + String(water_level) + "%");
    changeStatus();
}

void JSN_SR04T::measureDistance() {
    // Set the trigger pin LOW for 2us
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);

    // Set the trigger pin HIGH for 10us to send pulse
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);

    // Return the trigger pin to LOW
    digitalWrite(trig_pin, LOW);

    // Measure the width of the incoming pulse
    duration = pulseIn(echo_pin, HIGH); // us

    // Determine distance from duration
    // Use 343 metres per second as speed of sound
    // Divide by 1000 as we want millimeters
    distance = (duration*SOUND_SPEED/1000)/2;
    distance = constrain(distance, min_func_distance, water_tank_height);

    // Print result to serial monitor
    Serial.println("|\t|\tDistance: " + String(distance) + " mm");
}

void JSN_SR04T::changeStatus() {
    if (water_level > 90) {
        water_tank_status = HIGH;
        Serial.println("|\t|\tWater tank is full!");
    } else if (water_level < 15) {
        water_tank_status = LOW;
        Serial.println("|\t|\tNeed to fill up water tank!");
    }
}

// --------------------------------------------------
//                 GETTERS & SETTERS                 
// --------------------------------------------------
unsigned int JSN_SR04T::getDistance() {
    return distance;
}

bool JSN_SR04T::getWaterTankState() {
    return water_tank_status;
}