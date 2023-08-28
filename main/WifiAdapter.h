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
        void setSSID(const char*);
        void setPASS(const char*);


    private:
        // Components
        WiFiClient client_ref;
        PubSubClient client_ref;

        // Inputs
            // Connection
            const char* ssid = "";
            const char* pass = "";
        
        // Operation

        // Outputs
        bool connected = false;
};

#endif