#ifndef TaskManagerClock_h
#define TaskManagerClock_h

#include <Arduino.h>

class TaskManagerClock {
    public:
        TaskManagerClock();
        ~TaskManagerClock();

        // Functions
        void start();
        void stop();
        void reset();
        void checksEvery(unsigned long, void(*)());

        // Setters and getters

    private:
        // Config
        unsigned long timer = 0; // ms

        // Operators
        unsigned long last_check = 0; // ms
};

#endif