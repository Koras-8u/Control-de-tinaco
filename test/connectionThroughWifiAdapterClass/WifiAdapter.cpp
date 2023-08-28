#include "WifiAdapter.h"

// --------------------------------------------------
//                    CONSTRUCTORS                    
// --------------------------------------------------
WifiAdapter::WifiAdapter(const char* ssid, const char* pass, const char* mqtt_server, PubSubClient& client) 
    : ssid(ssid), pass(pass), mqtt_server(mqtt_server), client_ref(client) {}

WifiAdapter::~WifiAdapter() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void WifiAdapter::connect() {
    WiFi.begin(ssid, pass);
    if (WiFi.status() != WL_CONNECTED) {
        int attempts = 0;
        int limit = 100;
        Serial.print("|\t-Conectando a: ");
        Serial.println(ssid);
        while (WiFi.status() != WL_CONNECTED && attempts < limit) {
            Serial.print(".");
            attempts++;
            delay(200);
        }
        //Serial.println("");
        if (attempts < limit) {  // Conexión exitosa
            Serial.print("|\t-WiFi conectado. IP address: ");
            Serial.println(WiFi.localIP());
            connected = true;
        } else {  // Conexión fallida
            Serial.println("|\t-ERROR AL CONECTAR");
            connected = false;
        }
    }
}

void WifiAdapter::setupMqttClient(void (*callback)(char* topic, byte* payload, unsigned int length)) {
    client_ref.setServer(mqtt_server, 1883);
    client_ref.setCallback(*callback);
}

// --------------------------------------------------
//                 GETTERS & SETTERS
// --------------------------------------------------
void WifiAdapter::setPubSubClient(PubSubClient& client) {
    client_ref = client;
}

void WifiAdapter::setSSID(const char* ssid) {
    this->ssid = ssid;
}

void WifiAdapter::setPASS(const char* pass) {
    this->pass = pass;
}

const char* WifiAdapter::getSSID() {
    return ssid;
}

const char* WifiAdapter::getPASS() {
    return pass;
}

bool WifiAdapter::Connected() {
    return connected;
}