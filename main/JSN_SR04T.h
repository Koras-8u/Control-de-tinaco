#ifndef JSN_SR04T_h
#define JSN_SR04T_h

#include <Arduino.h>

// GLOBAL
#define SOUND_SPEED 343 // m/s

// SENSOR MAX RATINGS
#define MAX_DISTANCE 6000 // mm
#define MIN_DISTANCE 200 // mm

class JSN_SR04T {
    public:
        JSN_SR04T();
        JSN_SR04T(uint8_t, uint8_t);
        ~JSN_SR04T();

        // Functions
        void measureDistance();

        // Setters and getters
        void setTrigPin(uint8_t);
        void setEchoPin(uint8_t);
        unsigned int getDistance();
        unsigned long getPulseDuration();

    private:
        // Config
        uint8_t trig_pin = 0, echo_pin = 0;

        // Operators
        unsigned long pulse_duration = 0; // us

        // Outputs
        unsigned int distance = 0; // mm
};

#endif