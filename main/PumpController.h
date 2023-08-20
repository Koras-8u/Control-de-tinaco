#ifndef PumpController_h
#define PumpController_h

#include "WaterTank.h"

class PumpController {
    public:
        PumpController();
        ~PumpController();

        // Functions
        void ignoreValidations(uint8_t);
        uint8_t validations(uint8_t);

        // Setters and getters
        bool getConfirmation();

    private:
        // Operators
        unsigned int fullChecks = 0;
        unsigned int emptyChecks = 0;
        // unsigned int failChecks = 0;
        bool ignore = false;

        // Outputs
        bool confirmation = false;
};

#endif