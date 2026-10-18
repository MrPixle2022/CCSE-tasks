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
  if(isPressed(BTN_4))
    status = EMERGENCY;
  // Normal
  else if(isPressed(BTN_1)){
    //warn
    if(isPressed(BTN_2) == false)
      status = WARNING;
    else
      status = ACCESS;
  }
  // ALT
  else if(isPressed(BTN_3)){
    //warn
    if(isPressed(BTN_2) == false)
      status = WARNING;
    else
      status = ALT;
  }
  // OFF
  else
    status = OFF;

  switch(status){
    case ACCESS:
      //on green
      digitalWrite(R_LED, LOW);
      digitalWrite(Y_LED, LOW);
      digitalWrite(G_LED, HIGH);
      break;
    case ALT:
    //on green + yellow
    digitalWrite(R_LED, LOW);
    digitalWrite(Y_LED, LOW);
    digitalWrite(G_LED, HIGH);
      break;
    case WARNING:
      //on yellow
      digitalWrite(R_LED, LOW);
      digitalWrite(Y_LED, HIGH);
      digitalWrite(G_LED, LOW);
      break;
    // on green + red
    case EMERGENCY:
      digitalWrite(R_LED, LOW);
      digitalWrite(Y_LED, LOW);
      digitalWrite(G_LED, HIGH);
      break;
    // only red
    case OFF:
    default:
      digitalWrite(R_LED, HIGH);
      digitalWrite(Y_LED, LOW);
      digitalWrite(G_LED, LOW);
  }

  delay(100);
}