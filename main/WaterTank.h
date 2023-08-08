#ifndef WaterTank_h
#define WaterTank_h

#include "JSN_SR04T.h"

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
        bool getWaterTankStatus();

    private:
        // Components
        JSN_SR04T sensor;

        // Config        
        unsigned int water_tank_height = 0; // mm
        unsigned int min_water_distance = 0; // mm

        // Operators
        unsigned int distance = 0; // mm

        // Outputs
        uint8_t water_level = 0; // Percentage
        uint8_t status = 1; // 0 = Empty, 1 = Full, 2 = In use

        // Functions
        void changeStatus();
};

#endif