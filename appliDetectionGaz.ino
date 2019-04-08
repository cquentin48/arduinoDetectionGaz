#include <ESP8266WiFi.h>
#define IO_USERNAME  "Caesar01"
#define IO_KEY       "b9ceade1feae46299a5cd1d0e97007e9"

const char* ssid = "Wifi";
const char* password = "0a233e60b8b1";

#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, ssid, password);
 
const char* host = "wifitest.adafruit.com";

int ledPinRed = 15;
int ledPinGreen = 16;
int gazPort = A0;
int portBuzzer = 12;
int sensorLow = 0;
int sensorHigh = 1023;
AdafruitIO_Feed *RemoteButtons = io.feed("remote-buttons");

void setup() {
  // start the serial connection
  Serial.begin(115200);
 
  // wait for serial monitor to open
  while(! Serial);

  connection();
 
  // we are connected
  Serial.println();
  Serial.println(io.statusText());
}

void connection(){
  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();
 
  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
}
 
int value = 0;

void loop() {
  io.run();
  int val = getGazSensorValue();
  Serial.println(val,DEC);
  displayLed(ledPinGreen);
  int32_t value = val;
  displayResultData(value);
  sendData(value);
}

int getGazSensorValue(){
  return analogRead(gazPort);
}

void displayResultData(int value){
  if(value >= 1000){
      alert();
      displayRedLed(ledPinRed);
  }else{
    displayRedLed(ledPinGreen);
  }
}

void sendData(int inputValue){
  Serial.print("Sending RemoteButtons Value: ");
  Serial.print(inputValue);
  Serial.print("...");
 
  RemoteButtons->save(value);
  delay(3000);
}

void displayRedLed(int ledPin){
  for(int i = 0;i<10;i++){
    displayLed(ledPin);
  }
}

void displayLed(int ledPin){
    pinMode(ledPin, OUTPUT);
    delay(500);
    digitalWrite(ledPin,HIGH);
    delay(500);
    digitalWrite(ledPin,LOW);
}

void alert(){
  int pitch = map(value, 0, 1023, 50, 4000);
  tone(portBuzzer,pitch,500);
  delay(1000);
  tone(portBuzzer,pitch,500);
}
