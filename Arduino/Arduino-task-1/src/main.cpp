#include<Arduino.h>

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

bool isPressed(int btnPin){
  Serial.print("btn @pin  ");
  Serial.print(btnPin);
  Serial.print(" is checked: ");
  Serial.println(digitalRead(btnPin) == LOW? "pressed" : "nope");
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