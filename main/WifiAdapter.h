#ifndef WifiAdapter_h
#define WifiAdapter_h

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

class WifiAdapter {
    public:
        WifiAdapter();
        ~WifiAdapter();
        void connect2Wifi(void);

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