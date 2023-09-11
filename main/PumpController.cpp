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
    last_water_level = water_level;
}

void PumpController::validate(int water_level, uint8_t water_tank_status)
{
    Delta(water_level);
    checkStatus(water_level, water_tank_status);
    countChecks();
    clockValidation();
}

void PumpController::validate(int water_level, uint8_t water_tank_status, bool ignore)
{
    if (ignore)
    {
        last_ignore =  ignore;
        validation = true;
    }
    else
    {   
        if(last_ignore && !ignore)
        {
            last_ignore = ignore;
            validation = false;
        }
        validate(water_level, water_tank_status);
    }

}

void PumpController::Delta(int water_level)
{
    delta = abs(water_level - last_water_level);
    last_water_level = water_level;
    Serial.println("|\t|\t-Delta: " + String(delta));
}

void PumpController::checkStatus(int water_level, uint8_t water_tank_status)
{
    if (delta >= threshold)
    {
        empty_checks = 0;
        full_checks = 0;
        fail_checks++;
    }
    else if (delta < threshold && water_tank_status == EMPTY)
    {
        empty_checks++;
        full_checks = 0;
        fail_checks = 0;
    }
    else if (delta < threshold && water_tank_status == FULL)
    {
        full_checks++;
        empty_checks = 0;
        fail_checks = 0;
    }
    else if (delta < threshold && water_tank_status == FINE)
    {
        empty_checks = 0;
        full_checks = 0;
        fail_checks = 0;
    }
}

void PumpController::countChecks()
{
    if (fail_checks >= 10)
    {
        validation = false;
        fail_checks = 0;
        Serial.println("-SENSOR EXCEPTION: Sensor is not working properly!");
    }
    else if (empty_checks >= 3)
    {
        validation = true;
        empty_checks = 0;
    }
    else if (full_checks >= 3)
    {
        validation = false;
        full_checks = 0;
    }
    else
    {
        validation = validation;
    }
}

void PumpController::clockValidation()
{
    bool running = clock.runUntil(20 /*minutes*/, MIN, validation);
    if (running)
        validation = true;
    else
        validation = false;
}

// --------------------------------------------------
//                 GETTERS & SETTERS
// --------------------------------------------------
void PumpController::setWaterLevel(int water_level)
{
    last_water_level = water_level;
}

bool PumpController::getValidation()
{
    return validation;
}

double PumpController::getTimer()
{
    return clock.getTimer();
}