#include "TaskManagerClock.h"

// --------------------------------------------------
//                    CONSTRUCTORS
// --------------------------------------------------
TaskManagerClock::TaskManagerClock() {}

TaskManagerClock::~TaskManagerClock() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void TaskManagerClock::start()
{
    last_check = millis();
    timer = millis() - last_check;
    running = true;
    //Serial.println("|\t|\t-Timer started at: " + String(last_check) + " ms");
}

void TaskManagerClock::stop()
{
    last_check = millis();
    timer = 0;
    running = false;
    //Serial.println("|\t|\t-Timer stopped at: " + String(last_check) + " ms");
}

void TaskManagerClock::checksEvery(double timer_interval, uint32_t unit, void (*callback)())
{
    timer = millis() - last_check;
    decimal_timer = double(timer)/unit;
    if (decimal_timer >= timer_interval)
    {
        stop();
        (*callback)();
    }
}

void TaskManagerClock::checksEvery(double timer_interval, void (*callback)())
{
    checksEvery(timer_interval, SEC, callback);
}

void TaskManagerClock::runWhile(void (*callback)(), unsigned long timer_interval, bool enable)
{
    if (enable && !running)
    {
        start();
    }

    if (running)
    {
        timer = millis() - last_check;
        if (timer < timer_interval) (*callback)();
        else stop();
    }
}
bool TaskManagerClock::runUntil(double timer_interval, uint32_t unit, bool enable)
{
    if (enable && !running)
    {
        start();
    }
    else if (!enable && running)
    {
        stop();
    }

    if (running)
    {
        timer = millis() - last_check;
        decimal_timer = double(timer)/unit;
        if (decimal_timer >= timer_interval) stop();
    }

    return running;
}

bool TaskManagerClock::runUntil(double timer_interval, bool enable)
{
    runUntil(timer_interval, SEC, enable);
}

// --------------------------------------------------
//                 GETTERS & SETTERS
// --------------------------------------------------
double TaskManagerClock::getTimer()
{
    return decimal_timer;
}