#include "PumpController.h"

// --------------------------------------------------
//                    CONSTRUCTORS
// --------------------------------------------------

PumpController::PumpController() {}

PumpController::~PumpController() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void PumpController::validate(uint8_t water_tank_status)
{
    switch (water_tank_status)
    {
    case EMPTY:
        emptyChecks++; // How many times the water tank has been detected as empty
        fullChecks = 0;
        // failChecks++;
        water_tank_status = FINE;
        if (emptyChecks == 3)
        {
            validation = true;
            emptyChecks = 0;
        }
        break;
    case FULL:
        fullChecks++; // How many times the water tank has been detected as full
        emptyChecks = 0;
        // failChecks++;
        water_tank_status = FINE;
        if (fullChecks == 3)
        {
            validation = false;
            fullChecks = 0;
        }
        break;
    default:
        // emptyChecks = 0;
        // fullChecks = 0;
        break;
    }
}

void PumpController::validate(uint8_t water_tank_status, bool ignore)
{
    if (ignore) validation = true;
    else validate(water_tank_status);
}

/*
  // if (failChecks >= 10) {
  //   validation = false;
  //   failChecks = 0;
  //   Serial.println("-EXCEPTION: Sensor is not working properly!");
  // }
*/

// --------------------------------------------------
//                 GETTERS & SETTERS
// --------------------------------------------------
bool PumpController::getValidation()
{
    return validation;
}