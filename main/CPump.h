#ifndef CPump_h
#define CPump_h

#include <Arduino.h>

class CPump {
    public:
        CPump();
        CPump(uint8_t);
        ~CPump();
        void pumpsWater(bool);

    private:
        // Config
        uint8_t pin;

        // Outputs
        bool state = LOW;
        bool last_state = LOW;

};

#endif