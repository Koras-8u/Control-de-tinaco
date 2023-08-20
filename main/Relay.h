#ifndef Relay_h
#define Relay_h

#include <Arduino.h>

/*
    Tip: when naming a object of this class, use the name of the actuator
    or device attached to the relay.
*/

class Relay {
    public:
        Relay();
        Relay(uint8_t, String);
        Relay(uint8_t);
        ~Relay();

        // Functions
        void activate(bool, String);
        void activate(bool);

        // Setters and getters
        void setPin(uint8_t);
        void setDeviceName(String);
        String getDeviceName();

    private:
        // Config
        uint8_t pin = 0;
        String device_name = "Relay";

        // Inputs
        bool status = LOW;

        // Operators
        bool last_status = LOW;
};

#endif