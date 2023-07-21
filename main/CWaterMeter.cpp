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
    distance = float(duration/2)*SOUND_SPEED*MPS2MMPUS;

    // Print result to serial monitor
    Serial.print("distance: ");
    Serial.print(distance);
    Serial.println(" mm");
}

// --------------------------------------------------
//                 GETTERS & SETTERS                 
// --------------------------------------------------
float CWaterMeter::getDistance() {
    return distance;
}