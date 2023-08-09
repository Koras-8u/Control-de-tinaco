#include "Pump.h"

// --------------------------------------------------
//                    CONSTRUCTORS                    
// --------------------------------------------------
Pump::Pump() {}

Pump::Pump(uint8_t pin) {
    this->pin = pin;
}

Pump::~Pump() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------

void Pump::pumpsWater(bool status) {
        digitalWrite(pin, !status);
        if(status != last_status) {
            Serial.print("|\t-Pump:");
            Serial.println(status ? " ON" : " OFF");
            last_status = status;
        }
}

// --------------------------------------------------
//                 GETTERS & SETTERS                 
// --------------------------------------------------