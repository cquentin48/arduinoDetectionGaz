
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#define USE_SERIAL Serial
ESP8266WiFiMulti WiFiMulti;
const char* ssid = "Ma Wifi :)";
const char* password = "0a233e60b8b1";
// get this from the wia dashboard. it should start with `d_sk`
const char* device_secret_key = "your-device-secret-key";
void setup() {
    USE_SERIAL.begin(115200);
    //USE_SERIAL.setDebugOutput(true);
    WiFi.mode(WIFI_STA);
    WiFiMulti.addAP(ssid, password);
}
void loop() {
    // wait for WiFi connection
    if((WiFiMulti.run() == WL_CONNECTED)) {
        HTTPClient http;
        USE_SERIAL.print("[HTTP] begin...\n");
        // configure wia rest api
        http.begin("http://api.wia.io/v1/events");
        USE_SERIAL.print("[HTTP] POST...\n");
        // set content-type to json
        http.addHeader("Content-Type", "application/json");
        // start connection and send HTTP headers. replace name and data values with your own.
        int httpCode = http.POST("{\"name\":\"temperature\",\"data\":21.5}");
        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] POST... code: %d\n", httpCode);
            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                USE_SERIAL.println(payload);
            }
        } else {
            USE_SERIAL.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        http.end();
    }
    delay(10000);
}
