short buttons[4] = {2, 3, 4, 5}, leds[3] = {6, 7, 8}; // green, yellow, red
void setup() {
  for (short i = 0; i < 4; i++)
    pinMode(buttons[i], INPUT_PULLUP);
  for (short i = 0; i < 3; i++)
    pinMode(leds[i], OUTPUT);
}

void loop() {
  if (digitalRead(buttons[3]) == LOW) {  // emergency
    digitalWrite(leds[0], LOW);
    digitalWrite(leds[1], LOW);
    digitalWrite(leds[2], HIGH);
  }
  else if ((digitalRead(buttons[0]) == LOW && digitalRead(buttons[1]) == LOW) || (digitalRead(buttons[1]) == LOW && digitalRead(buttons[2]) == LOW)) { // normal access
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], LOW);
    digitalWrite(leds[2], LOW);
  }
  else if ((digitalRead(buttons[0]) == LOW && digitalRead(buttons[1]) == HIGH) || (digitalRead(buttons[1]) == HIGH && digitalRead(buttons[2]) == LOW)) { // alterantive access
    digitalWrite(leds[0], LOW);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], LOW);
  }
  else {
    for (short i = 0; i < 3; i++)
      digitalWrite(leds[i], LOW);
  }
}