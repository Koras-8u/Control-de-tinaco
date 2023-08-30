#ifndef WifiAdapter_h
#define WifiAdapter_h

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class WifiAdapter
{
public:
    WifiAdapter(const char *, const char *, PubSubClient &);
    ~WifiAdapter();

    // Functions
    void connect2Wifi(void);
    void connect2Broker(void);

    // Setters and getters
    void setPubSubClient(PubSubClient &);
    void setSSID(const char *);
    void setPASS(const char *);
    const char *getSSID();
    const char *getPASS();
    bool isConnected();

private:
    // Components

    // Inputs
    PubSubClient &client_ref;
    // Credentials
    const char *ssid = "";
    const char *pass = "";

    // Operation

    // Outputs
    bool connected = false;
};

// --------------------------------------------------
//                 EXTERNAL FUNCTIONS
// --------------------------------------------------
// void callback(char* topic, byte* payload, unsigned int length) {
//     Serial.print("Mensaje recibido [");
//     Serial.print(topic);
//     Serial.print("] ");
//     for (int i = 0; i < length; i++) {
//         Serial.print((char)payload[i]);
//     }
//     Serial.println();
// }

#endif