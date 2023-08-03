#ifndef Pump_h
#define Pump_h

#include <Arduino.h>

class Pump {
    public:
        Pump();
        Pump(uint8_t);
        ~Pump();
        void pumpsWater(bool);

    private:
        // Config
        uint8_t pin;

        // Outputs
        bool status = LOW;
        bool last_status = LOW;

};

#endif