#include <Arduino.h>

#define R_LED 2
#define Y_LED 3
#define G_LED 4

#define BTN_1 6
#define BTN_2 7
#define BTN_3 8
#define BTN_4 9

<<<<<<< HEAD
enum Status { OFF, ACCESS, WARNING, EMERGENCY };

bool isPressed(int pin) {
  return digitalRead(pin) == LOW;
}

void setLeds(bool r, bool y, bool g) {
  digitalWrite(R_LED, r);
  digitalWrite(Y_LED, y);
  digitalWrite(G_LED, g);
}

void setup() {
=======

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
>>>>>>> a23dc25 (should work just fine)
  pinMode(R_LED, OUTPUT);
  pinMode(Y_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);
  pinMode(BTN_4, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  Status status = OFF;

  if (isPressed(BTN_4)) {
    status = EMERGENCY;
  } else if (isPressed(BTN_1) || isPressed(BTN_3)) {
    status = isPressed(BTN_2) ? ACCESS : WARNING;
  }

  switch (status) {
    case EMERGENCY: setLeds(HIGH, LOW,  LOW);  break;
    case ACCESS:    setLeds(LOW,  LOW,  HIGH); break;
    case WARNING:   setLeds(LOW,  HIGH, LOW);  break;
    default:        setLeds(LOW,  LOW,  LOW);  break;
  }

  delay(20);  // small delay, enough for basic debouncing
}