#include "WifiAdapter.h"

// --------------------------------------------------
//                    CONSTRUCTORS
// --------------------------------------------------
WifiAdapter::WifiAdapter(const char *ssid, const char *pass, PubSubClient &client)
    : ssid(ssid), pass(pass), client_ref(client) {}

WifiAdapter::~WifiAdapter() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void WifiAdapter::connect2Wifi()
{
    WiFi.begin(ssid, pass);
    if (WiFi.status() != WL_CONNECTED)
    {
        int attempts = 0;
        int limit = 100;
        Serial.print("|\t-Conectando a: ");
        Serial.println(ssid);
        while (WiFi.status() != WL_CONNECTED && attempts < limit)
        {
            Serial.print(".");
            attempts++;
            delay(200);
        }
        // Serial.println("");
        if (attempts < limit)
        { // Successful connection
            Serial.print("|\t-WiFi conectado. IP address: ");
            Serial.println(WiFi.localIP());
            connected = true;
        }
        else
        { // Failed connection
            Serial.println("|\t-ERROR AL CONECTAR");
            connected = false;
        }
    }
}

void WifiAdapter::connect2Broker()
{
    if (!client_ref.connected())
    {
        // Attempt to connect
        Serial.print("|\t-Estableciendo conexión MQTT...");
        String client_id = "ESP8266Client-";
        client_id += String(WiFi.macAddress());
        if (client_ref.connect("3NxlmThFyY"))
        {
            Serial.println("|\t|\t-Conectado");
            // Once connected, publish an announcement...
            client_ref.publish("water-tank/ad", "Hello from ESP8266");
            // ... and resubscribe
            client_ref.subscribe("water-tank/ignorer");
        }
        else
        {
            Serial.print("|\t|\t-Conexión fallida, rc=");
            Serial.print(client_ref.state());
        }
    }
}

// --------------------------------------------------
//                 GETTERS & SETTERS
// --------------------------------------------------
void WifiAdapter::setPubSubClient(PubSubClient &client)
{
    client_ref = client;
}

void WifiAdapter::setSSID(const char *ssid)
{
    this->ssid = ssid;
}

void WifiAdapter::setPASS(const char *pass)
{
    this->pass = pass;
}

const char *WifiAdapter::getSSID()
{
    return ssid;
}

const char *WifiAdapter::getPASS()
{
    return pass;
}

bool WifiAdapter::Connected()
{
    return connected;
}