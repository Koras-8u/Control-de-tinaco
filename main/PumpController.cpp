#include "PumpController.h"

// --------------------------------------------------
//                    CONSTRUCTORS
// --------------------------------------------------

PumpController::PumpController() {}

PumpController::~PumpController() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void PumpController::init(int water_level)
{
    this->water_level = water_level;
    last_water_level = water_level;
}

void PumpController::validate(int water_level)
{
    Delta();
    if (delta >= 0)
    {
        validation = true;
    }
    else
    {
        validation = false;
    }
}

void PumpController::validate(uint8_t water_tank_status)
{
    switch (water_tank_status)
    {
    case EMPTY:
        empty_checks++; // How many times the water tank has been detected as empty
        full_checks = 0;
        // failChecks++;
        water_tank_status = FINE;
        if (empty_checks == 3)
        {
            validation = true;
            empty_checks = 0;
        }
        break;
    case FULL:
        full_checks++; // How many times the water tank has been detected as full
        empty_checks = 0;
        // failChecks++;
        water_tank_status = FINE;
        if (full_checks == 3)
        {
            validation = false;
            full_checks = 0;
        }
        break;
    default:
        // empty_checks = 0;
        // full_checks = 0;
        break;
    }
}

void PumpController::validate(uint8_t water_tank_status, bool ignore)
{
    if (ignore) validation = true;
    else validate(water_tank_status);
}

void PumpController::Delta()
{
    delta = water_level - last_water_level;
    last_water_level = water_level;
    Serial.println("|\t-Delta: " + String(delta));
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
void PumpController::setWaterLevel(int water_level)
{
    this->water_level = water_level;
}

bool PumpController::getValidation()
{
    return validation;
}