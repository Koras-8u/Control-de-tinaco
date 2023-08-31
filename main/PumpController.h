#ifndef PumpController_h
#define PumpController_h

#include "WaterTank.h"

class PumpController
{
public:
    PumpController();
    ~PumpController();

    // Functions
    void validate(uint8_t);
    void validate(uint8_t, bool);

    // Setters and getters
    bool getValidation();

private:
    // Operators
    unsigned int fullChecks = 0;
    unsigned int emptyChecks = 0;
    // unsigned int failChecks = 0;

    // Outputs
    bool validation = false;
};

#endif