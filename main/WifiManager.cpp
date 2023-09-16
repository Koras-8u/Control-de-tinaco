#include "WifiManager.h"

// --------------------------------------------------
//                    CONSTRUCTORS
// --------------------------------------------------
WifiManager::WifiManager(const char *ssid, const char *pass, PubSubClient &client)
    : ssid(ssid), pass(pass), client_ref(client) {}

WifiManager::~WifiManager() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void WifiManager::begin()
{
    WiFi.begin(ssid, pass);
    connect2Wifi();
    connect2Broker();
}

void WifiManager::connect2Wifi()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        uint8_t attempts = 0;
        uint8_t limit = 100;
        Serial.print("|\t-Conectando a: ");
        Serial.println(ssid);
        while (WiFi.status() != WL_CONNECTED && attempts < limit)
        {
            Serial.print(".");
            attempts++;
            delay(200);
        }
        if (attempts < limit)
        { // Successful connection
            Serial.print("\n|\t-WiFi conectado. IP address: ");
            Serial.println(WiFi.localIP());
            wifiStatus = true;
        }
        else
        { // Failed connection
            Serial.println("\n|\t-ERROR AL CONECTAR");
            wifiStatus = false;
        }
    }
}

void WifiManager::connect2Broker()
{
    if (!client_ref.connected() && wifiStatus)
    {
        // Attempt to connect
        Serial.println("|\t-Estableciendo conexión MQTT...");
        String client_id = "ESP8266Client-";
        client_id += String(WiFi.macAddress());
        if (client_ref.connect(client_id.c_str()))
        {
            Serial.println("|\t|\t-Conectado");
            // Once connected, publish an announcement...
            client_ref.publish("water-tank/ad", "Hello from ESP8266");
            // ... and resubscribe
            client_ref.subscribe("water-tank/ignorer");
            brokerStatus = true;
        }
        else
        {
            Serial.print("\n|\t|\t-Conexión fallida, rc=");
            Serial.println(client_ref.state());
            brokerStatus = false;
        }
    }
}

void WifiManager::publish(const char * topic, double payload)
{
    if (client_ref.connected())
    {
        char levelStr[8];
        snprintf(levelStr, sizeof(levelStr), "%.2f", payload);
        client_ref.publish(topic, levelStr);
    }
}

void WifiManager::publish(const char * topic, const char * payload)
{
    if (client_ref.connected())
    {
        client_ref.publish(topic, payload);
    }
}

// --------------------------------------------------
//                 GETTERS & SETTERS
// --------------------------------------------------
void WifiManager::setPubSubClient(PubSubClient &client)
{
    client_ref = client;
}

void WifiManager::setSSID(const char *ssid)
{
    this->ssid = ssid;
}

void WifiManager::setPASS(const char *pass)
{
    this->pass = pass;
}

const char *WifiManager::getSSID()
{
    return ssid;
}

const char *WifiManager::getPASS()
{
    return pass;
}

bool WifiManager::getWifiStatus()
{
    return wifiStatus;
}

bool WifiManager::getBrokerStatus()
{
    return brokerStatus;
}