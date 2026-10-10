#include <Arduino.h>

#define R_LED 2
#define Y_LED 3
#define G_LED 4

#define BTN_1 6
#define BTN_2 7
#define BTN_3 8
#define BTN_4 9


enum Status {
  ACCESS,
  ALT,
  WARNING,
  EMERGENCY,
  OFF,
};

bool isPressed(uint8_t btnPin){
  return digitalRead(btnPin) == LOW;
}


Status status = OFF;

void setup(){
  //setting the I/O signal to output
  pinMode(R_LED, OUTPUT);
  pinMode(Y_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);

  //PULLUP for buttons
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);
  pinMode(BTN_4, INPUT_PULLUP);
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
    digitalWrite(Y_LED, HIGH);
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
      digitalWrite(R_LED, HIGH);
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
}