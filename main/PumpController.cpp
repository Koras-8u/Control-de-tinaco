#include "PumpController.h"

// --------------------------------------------------
//                    CONSTRUCTORS                   
// --------------------------------------------------

PumpController::PumpController() {}

PumpController::~PumpController() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void PumpController::ignoreValidations(uint8_t pin) {
    if (digitalRead(pin) == HIGH) {
        ignore = true; // controller has to be omited
    } else {
        ignore = false; // controller has to work normally
    }
}

uint8_t PumpController::validations(uint8_t water_tank_status) {
    if(!ignore) {
        switch (water_tank_status) {
        case EMPTY:
            emptyChecks++; // How many times the water tank has been detected as empty
            fullChecks = 0;
            // failChecks++;
            water_tank_status = FINE;
            if (emptyChecks == 3) {
                confirmation = true;
                emptyChecks = 0;
            }
            break;
        case FULL:
            fullChecks++; // How many times the water tank has been detected as full
            emptyChecks = 0;
            // failChecks++;
            water_tank_status = FINE;
            if (fullChecks == 3) {
                confirmation = false;
                fullChecks = 0;
            }
            break;
        default:
            break;
        }
    }
    else {
        water_tank_status = FINE;
        confirmation = true;
    }

    return water_tank_status;
}

/*
  // if (failChecks >= 10) {
  //   confirmation = false;
  //   failChecks = 0;
  //   Serial.println("-EXCEPTION: Sensor is not working properly!");
  // }
*/

// --------------------------------------------------
//                 GETTERS & SETTERS                 
// --------------------------------------------------
bool PumpController::getConfirmation() {
    return confirmation;
}