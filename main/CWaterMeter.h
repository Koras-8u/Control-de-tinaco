#ifndef CWaterMeter_h
#define CWaterMeter_h

#include <Arduino.h>

#define SOUND_SPEED 343.0 // m/s
#define MPS2MMPUS 0.001 // Meters per second to millimeters per microsecond

class CWaterMeter {
    public:
        CWaterMeter();
        CWaterMeter(uint8_t, uint8_t);
        ~CWaterMeter();
        void measureWaterLvl();
        float getDistance();

    private:
        // Config
        uint8_t trig_pin, echo_pin;

        // Inputs
        unsigned long duration = 0;

        // Outputs
        float distance = 0.0;

        // Methods

};

#endif