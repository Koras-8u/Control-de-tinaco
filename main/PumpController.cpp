#include "PumpController.h"

// --------------------------------------------------
//                    CONSTRUCTORS                   
// --------------------------------------------------

PumpController::PumpController() {}

PumpController::~PumpController() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------

void PumpController::needToFillUp(uint8_t waterTankStatus) {
    if(!ignore) {
        switch (waterTankStatus) {
        case EMPTY:
            emptyChecks++; // How many times the water tank has been detected as empty
            fullChecks = 0;
            // failChecks++;
            waterTankStatus = FINE;
            if (emptyChecks == 3) {
                confirmation = true;
                emptyChecks = 0;
            }
            break;
        case FULL:
            fullChecks++; // How many times the water tank has been detected as full
            emptyChecks = 0;
            // failChecks++;
            waterTankStatus = FINE;
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
        confirmation = true;
    }
}

/*
  // Ignore controller
    if (digitalRead(CTRLOMITTER) == HIGH) {
    ignore = true; // controller must be omited
    } else {
    ignore = false; // controller must be working
    }

// Controller
    if(ignore) {
        confirmation = true; // Pump is ON always
    } else {
    }

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