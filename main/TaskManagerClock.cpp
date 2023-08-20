#include "TaskManagerClock.h"

// --------------------------------------------------
//                    CONSTRUCTORS                   
// --------------------------------------------------
TaskManagerClock::TaskManagerClock() {}

TaskManagerClock::~TaskManagerClock() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void TaskManagerClock::start() {
    last_check = millis();
    timer = millis() - last_check;
}

void TaskManagerClock::checksEvery(unsigned long timer_interval, void(*callback)()) {
    timer = millis() - last_check;
    if (timer >= timer_interval) {
        last_check = millis();
        timer = 0;
        (*callback)();
    }
}