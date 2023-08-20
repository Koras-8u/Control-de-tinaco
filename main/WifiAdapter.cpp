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