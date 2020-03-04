#include "SoftwareSerial.h"

SoftwareSerial bluetooth(1, 0);

const int ledPin = 13;
int incomingByte;

void setup() {
  bluetooth.begin(9600);

  pinMode(ledPin, OUTPUT);
}

void loop() {
  if(bluetooth.available()> 0){
    incomingByte = bluetooth.read();
    if (incomingByte == 'H'){
      digitalWrite(ledPin, LOW);
      bluetooth.println("LED: LIGADO");
    }
      
    if (incomingByte == 'L'){
      digitalWrite(ledPin, HIGH);
      bluetooth.println("LED: DESLIGADO");
    }
  }
 }
