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
        void runWhile(void(*)(), unsigned long, bool);
        bool runUntil(unsigned long, bool);

        // Setters and getters

    private:
        // Config
        unsigned long timer = 0; // ms

        // Operators
        unsigned long last_check = 0; // ms

        // Output
        bool running = false;
};

#endif