#include <Arduino.h>
#include "Wifi.h"

#define WIFI_NETWORK "G-Home"
#define WIFI_PASSWORD "nop"
#define WIFI_TIMEOUT_MS 20000

void connectToWifi(){
    Serial.print("Connecting to Wifi");
    Wifi.mode(WIFI_STA);
    Wifi.begin(WIFI_NETWORK, WIFI_PASSWORD);

    unsigned long startAttemptTime = milis();

    while(Wifi.status() != WL_CONNECTED && milis() - startAttemptNow < WIFI_TIMEOUT){
        Serial.print(".");
        delay(100);
    }

    if(Wifi.status() != WL_CONNECTED){
        Serial.println("Failed :(");
    } else{
        Serial.print("Connected!");
        Serial.println(Wifi.localIP());
    }
}

void setup(){
    Serial.begin(9600);
    connectToWifi();
}

void loop(){

}