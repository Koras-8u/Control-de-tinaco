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
void JSN_SR04T::measureDistance() {
    // Set the trigger pin LOW for 2us
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);

    // Set the trigger pin HIGH for 20us to send pulse
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(20);

    // Return the trigger pin to LOW
    digitalWrite(trig_pin, LOW);

    // Measure the width of the incoming pulse
    pulse_duration = pulseIn(echo_pin, HIGH); // us
    Serial.println("|\t|\t-Duration: " + String(pulse_duration) + " us");

    // Determine distance from pulse_duration
    distance = (pulse_duration*SOUND_SPEED/1000)/2; // Converting m/s to mm/us
    Serial.println("|\t|\t-Distance: " + String(distance) + " mm");
}

// --------------------------------------------------
//                 SETTERS & GETTERS                 
// --------------------------------------------------
void JSN_SR04T::setTrigPin(uint8_t trig_pin) {
    this->trig_pin = trig_pin;
}

void JSN_SR04T::setEchoPin(uint8_t echo_pin) {
    this->echo_pin = echo_pin;
}

unsigned int JSN_SR04T::getDistance() {
    return distance;
}

unsigned long JSN_SR04T::getPulseDuration() {
    return pulse_duration;
}