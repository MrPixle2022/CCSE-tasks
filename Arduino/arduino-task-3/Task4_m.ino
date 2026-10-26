#include <LiquidCrystal.h>

int RS = 12, EN = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2;
LiquidCrystal LCD(RS, EN, D4, D5, D6, D7);

int LDR = A0;

void setup() {
  pinMode(LDR, INPUT);
  LCD.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  LCD.setCursor(0, 0);
  int Brightness = analogRead(LDR);
  
  if (Brightness > 600) {
    LCD.print("Bright");
    Serial.print("Bright");
  }
  else {
    LCD.print("Dark");
    Serial.print("Dark");
  }

  LCD.setCursor(0, 1);
  LCD.print("Brightness: ");
  LCD.print(Brightness);

  Serial.print("Brightness: ");
  Serial.println(Brightness);
}