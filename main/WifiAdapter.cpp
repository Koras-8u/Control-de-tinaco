#include "WifiAdapter.h"

// --------------------------------------------------
//                    CONSTRUCTORS                    
// --------------------------------------------------
WifiAdapter::WifiAdapter() {}

WifiAdapter::~WifiAdapter() {}

// --------------------------------------------------
//                     FUNCTIONS
// --------------------------------------------------
void WifiAdapter::connect2Wifi() {
//     WiFi.begin(ssid, pass);
//     if (WiFi.status() != WL_CONNECTED) {
//         int attempts = 0;
//         int limit = 100;
//         Serial.print("Conectando a: ");
//         Serial.println(ssid);
//         while (WiFi.status() != WL_CONNECTED && attempts < limit) {
//             Serial.print(".");
//             attempts++;
//             vTaskDelay(200);
//         }
//         //Serial.println("");
//         if (attempts < limit) {  // Conexión exitosa
//             Serial.print("\nWiFi conectado. IP address: ");
//             Serial.println(WiFi.localIP());      
//             if (updateEnabler) {  //SI ESTA EN MODO REPROGRAMACIÓN INCIALIZA MDASH
//                 mDashBegin(deviceKey);
//             }
//             connection = true;
//         } else {  // Conexión fallida
//             Serial.println("\nERROR AL CONECTAR");
//             connection = false;
//         }
//     }
}


bool WifiAdapter::updateFirmware(const char * payload) {
//     DynamicJsonDocument doc(1200);
//     //Serial.println("EMPIEZA A DESERALIZAR");
//     DeserializationError error = deserializeJson(doc, payload);
//     if (error) return;

//     //CONFIGURA MDASH
//     bool update_enabler = doc["actualizacion_firmware"];
//     char* device_key = doc["key_contador"];
//     if (device_key != "null") {
//         if (update_enabler != updateEnabler || device_key != deviceKey) {
//             updateEnabler = update_enabler;
//             deviceKey = device_key;
//             //USB.println("REINCIANDO ESP32. INCIA MODO REPROGRAMACION");
//             vTaskDelay(1000);
//             ESP.restart();
//         }
//     }
    return true;
}