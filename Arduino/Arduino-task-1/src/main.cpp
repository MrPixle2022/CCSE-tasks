#include <Arduino.h>
#define LED 2
#define BTN 9


void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  Serial.begin(9600);
}
void loop(){
  if(digitalRead(BTN) == HIGH){
    digitalWrite(LED, HIGH);
  }
  delay(500);
  digitalWrite(LED, LOW);
}