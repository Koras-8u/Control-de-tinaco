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
    Serial.println("|\t|\t-Timer started at: " + String(last_check) + " ms");
}

void TaskManagerClock::stop()
{
    last_check = millis();
    timer = 0;
    running = false;
    Serial.println("|\t|\t-Timer stopped at: " + String(last_check) + " ms");
}

void TaskManagerClock::checksEvery(unsigned long timer_interval, void (*callback)())
{
    timer = millis() - last_check;
    if (timer >= timer_interval)
    {
        stop();
        (*callback)();
    }
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

bool TaskManagerClock::runUntil(unsigned long timer_interval, bool enable)
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
        //Serial.print("|\t|\t-Running: " + String(timer) + " ms");
        if (timer >= timer_interval) stop();
    }

    return running;
}