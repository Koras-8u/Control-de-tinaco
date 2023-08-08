#ifndef WifiAdapter_h
#define WifiAdapter_h

#include "WiFi.h"
#include "mDash.h"
#include "ArduinoJson.h"

class WifiAdapter {
    public:
        WifiAdapter();
        ~WifiAdapter();
        void connect2Wifi(void);
        bool updateFirmware(const char *);
    private:
        // Inputs
            // Connection
            bool connection = false;
            const char* ssid = "";
            const char* pass = "";

            // mDash
            bool updateEnabler = true;
            char* deviceKey = "";
        
        // Operation

        // Outputs
};

#endif