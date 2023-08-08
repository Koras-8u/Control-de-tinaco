#ifndef JSN_SR04T_h
#define JSN_SR04T_h

#include <Arduino.h>

// SENSOR
#define MAX_DISTANCE 6000 // mm
#define MIN_DISTANCE 200 // mm

// GLOBAL
#define SOUND_SPEED 343 // m/s

class JSN_SR04T {
    public:
        JSN_SR04T();
        JSN_SR04T(uint8_t, uint8_t);
        ~JSN_SR04T();
        void measureWaterLvl();
        bool getWaterTankState();

    private:
        // Config
        uint8_t trig_pin, echo_pin;
        unsigned int water_tank_height = 1400; // mm
        unsigned int min_func_distance = MIN_DISTANCE + 100; // mm

        // Inputs
        unsigned long duration = 0;

        // Operations
        unsigned int distance = 0;

        // Outputs
        uint8_t water_level = 0; // Percentage
        bool water_tank_status = true;

        // Methods
        void measureDistance();
        unsigned int getDistance();
        void changeStatus();
};

#endif