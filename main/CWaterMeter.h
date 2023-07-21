#ifndef CWaterMeter_h
#define CWaterMeter_h

#include <Arduino.h>

#define SOUND_SPEED 343.0 // m/s

class CWaterMeter {
    public:
        CWaterMeter();
        CWaterMeter(uint8_t, uint8_t);
        ~CWaterMeter();
        void measureWaterLvl();
        bool getWaterTankState();

    private:
        // Config
        uint8_t trig_pin, echo_pin;
        unsigned int water_tank_height = 1500; // mm
        unsigned int sensor_min_distance = 450; // mm

        // Inputs
        unsigned long duration = 0;

        // Operations
        unsigned int distance = 0;

        // Outputs
        uint8_t water_level = 0; // Percentage
        bool water_tank_state = false;

        // Methods
        void measureDistance();
        unsigned int getDistance();
        void setWaterTankState();
};

#endif