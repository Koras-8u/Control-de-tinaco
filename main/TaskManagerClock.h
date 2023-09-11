#ifndef TaskManagerClock_h
#define TaskManagerClock_h

#include <Arduino.h>

#define MSEC 1
#define SEC 1000
#define MIN 60000
#define HR 3600000

class TaskManagerClock {
    public:
        TaskManagerClock();
        ~TaskManagerClock();

        // Functions
        void start();
        void stop();
        void reset();
        void checksEvery(double, uint32_t, void(*)());
        void checksEvery(double, void(*)());
        void runWhile(void(*)(), unsigned long, uint32_t, bool);
        void runWhile(void(*)(), unsigned long, bool);
        bool runUntil(double, uint32_t, bool);
        bool runUntil(double, bool);

        // Setters and getters
        double getTimer();


    private:
        // Operators
        unsigned long timer = 0; // ms
        unsigned long last_check = 0; // ms

        // Output
        double decimal_timer = 0.0;
        bool running = false;
};

#endif