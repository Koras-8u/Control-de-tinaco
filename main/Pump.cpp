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
        digitalWrite(pin, status); // HIGH = OFF, LOW = ON
        if(status != last_status) {
            Serial.print("|\tPump:");
            Serial.println(status ? " OFF" : " ON");
            last_status = status;
        }
}

// --------------------------------------------------
//                 GETTERS & SETTERS                 
// --------------------------------------------------