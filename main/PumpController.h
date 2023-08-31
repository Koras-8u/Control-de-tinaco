#ifndef PumpController_h
#define PumpController_h

#include "WaterTank.h"
#include "TaskManagerClock.h"

class PumpController
{
public:
    PumpController();
    ~PumpController();

    // Functions
    void init(int);
    void validate(int, uint8_t);
    void validate(int, uint8_t, bool);

    // Setters and getters
    void setWaterLevel(int);
    bool getValidation(void);

private:
    // Components
    TaskManagerClock clock;

    // Inputs
    int last_water_level = 0;

    // Operators
    const int threshold = 10;
    int delta = 0;
    unsigned int full_checks = 0;
    unsigned int empty_checks = 0;
    unsigned int fail_checks = 0;

    // Outputs
    bool validation = false;

    // Functions
    void Delta(int);
    void checkStatus(int, uint8_t);
    void countChecks();
    void clockValidation();
};

#endif