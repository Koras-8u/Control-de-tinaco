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
    void publish(const char *, double);

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