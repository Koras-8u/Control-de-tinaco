#ifndef WifiManager_h
#define WifiManager_h

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class WifiManager
{
public:
    WifiManager(const char *, const char *, PubSubClient &);
    ~WifiManager();

    // Functions
    void begin(void);
    void connect2Wifi(void);
    void connect2Broker(void);
    void publish(const char *, double);
    void publish(const char *, const char *);

    // Setters and getters
    void setPubSubClient(PubSubClient &);
    void setSSID(const char *);
    void setPASS(const char *);
    const char *getSSID();
    const char *getPASS();
    bool getWifiStatus();
    bool getBrokerStatus();

private:
    // Components

    // Inputs
    PubSubClient &client_ref;
    const char *ssid = "";
    const char *pass = "";

    // Operation

    // Outputs
    bool wifiStatus = false;
    bool brokerStatus = false;
};

#endif