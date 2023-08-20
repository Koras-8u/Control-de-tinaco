#ifndef WifiAdapter_h
#define WifiAdapter_h

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class WifiAdapter {
    public:
        WifiAdapter();
        ~WifiAdapter();
        void connect(void);

        // Setters and getters
        void setSsid(const char*);
        void setPass(const char*);


    private:
        // Components
        WiFiClient espClient;
        PubSubClient client;

        // Inputs
            // Connection
            const char* ssid = "";
            const char* pass = "";
        
        // Operation

        // Outputs
        bool connection = false;
};

#endif