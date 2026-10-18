#include <Arduino.h>
#define LED 2
#define BTN 9


void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  Serial.begin(9600);
}
void loop(){

  //emergency > Normal = ALT > Warn > OFF
  if(isPressed(BTN_4)){
    digitalWrite(R_LED, HIGH);
    delay(500);
    digitalWrite(Y_LED, LOW);
    digitalWrite(G_LED, LOW);
  }
  else if(isPressed(BTN_1)){
    //warn
    if(!isPressed(BTN_2)){
      //on yellow
      digitalWrite(R_LED, LOW);
      digitalWrite(Y_LED, HIGH);
      delay(1000);
      digitalWrite(G_LED, LOW);
    }
    else{
      //on green
      digitalWrite(R_LED, LOW);
      digitalWrite(Y_LED, LOW);
      digitalWrite(G_LED, HIGH);
      delay(500);
    }
  }
  else if(isPressed(BTN_3)){
    //warn
    if(!isPressed(BTN_2)){
      //on yellow
      digitalWrite(R_LED, LOW);
      digitalWrite(Y_LED, HIGH);
      delay(1000);
      digitalWrite(G_LED, LOW);
    }
    else{
      //on green
      digitalWrite(R_LED, LOW);
      digitalWrite(Y_LED, LOW);
      digitalWrite(G_LED, HIGH);
    }
  }
  else{
    digitalWrite(R_LED, LOW);
    digitalWrite(Y_LED, LOW);
    digitalWrite(G_LED, LOW);
  }
  delay(100);
}