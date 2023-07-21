#include "CPump.h"

// --------------------------------------------------
//                    CONSTRUCTORS                    
// --------------------------------------------------
CPump::CPump() {}

CPump::CPump(uint8_t pin) {
    this->pin = pin;
}

CPump::~CPump() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------

void CPump::pumpsWater(bool state) {
        digitalWrite(pin, state);
        if(state != last_state) {
            Serial.print("|\tPump:");
            Serial.println(state ? " ON" : " OFF");
            last_state = state;
        }
}

// --------------------------------------------------
//                 GETTERS & SETTERS                 
// --------------------------------------------------