#ifndef WaterTank_h
#define WaterTank_h

#include "JSN_SR04T.h"

// Water tank status
#define EMPTY 0
#define FULL 1
#define FINE 2

class WaterTank {
    public:
        WaterTank();
        WaterTank(JSN_SR04T);
        WaterTank(JSN_SR04T, unsigned int, unsigned int);
        ~WaterTank();

        // Functions
        void measureWaterLvl();

        // Setters and getters
        void setWaterTankHeight(unsigned int);
        void setMinWaterDistance(unsigned int);
        int getWaterTankLevel();
        uint8_t getWaterTankStatus();

    private:
        // Components
        JSN_SR04T sensor;

        // Config        
        unsigned int water_tank_height = 0; // mm
        unsigned int min_water_distance = 0; // mm

        // Operators
        unsigned int distance = 0; // mm

        // Outputs
        int water_level = 0; // Percentage
        uint8_t status = FULL; // 0 = EMPTY, 1 = FULL, 2 = FINE

        // Functions
        void changeStatus();
};

#endif