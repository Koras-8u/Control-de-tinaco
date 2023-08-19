#include "Relay.h"

// --------------------------------------------------
//                    CONSTRUCTORS                    
// --------------------------------------------------
Relay::Relay() {}

Relay::Relay(uint8_t pin, String device_name) {
    this->pin = pin;
    this->device_name = device_name;
}

Relay::Relay(uint8_t pin) {
    Relay(pin, "Relay");
}

Relay::~Relay() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------

void Relay::activates(bool status, String device_name) {
        digitalWrite(pin, !status);
        if(status != last_status) {
            Serial.print("|\t-" + device_name + ":");
            Serial.println(status ? " ON" : " OFF");
            last_status = status;
        }
}

void Relay::activates(bool status) {
    activates(status, device_name);
}

// --------------------------------------------------
//                 GETTERS & SETTERS                 
// --------------------------------------------------
void Relay::setPin(uint8_t pin) {
    this->pin = pin;
}

void Relay::setDeviceName(String device_name) {
    this->device_name = device_name;
}