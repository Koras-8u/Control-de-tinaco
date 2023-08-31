#ifndef PumpController_h
#define PumpController_h

#include "WaterTank.h"

class PumpController
{
public:
    PumpController();
    ~PumpController();

    // Functions
    void init(int);
    void validate(int);
    void validate(uint8_t);
    void validate(uint8_t, bool);

    // Setters and getters
    void setWaterLevel(int);
    bool getValidation(void);

private:
// Inputs
    int water_level = 0;
    int last_water_level = 0;
    // Operators
    int delta = 0;
    unsigned int full_checks = 0;
    unsigned int empty_checks = 0;
    // unsigned int failChecks = 0;

    // Outputs
    bool validation = false;

    // Functions
    void Delta();
};

#endif