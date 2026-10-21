short LDR = A0, pot = A1, button = 2, led = 3;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(LDR, INPUT);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

char cmd;
void loop() {
  if (Serial.available()  ) {
    cmd = Serial.read();
    Serial.print("cmd: ");
    Serial.println(cmd);
  }
  switch (cmd) {
      case '1':
        analogWrite(led, map(analogRead(pot), 0, 1023, 0, 255));
        break;
      case '2':
        analogWrite(led, map(analogRead(LDR), 0, 1023, 0, 255));
        break;
      case '3':
        digitalWrite(led, !digitalRead(button));
        break;
      case '4':
        int DELAY = map(analogRead(pot), 0, 1023, 25, 250);
        digitalWrite(led, HIGH);
        delay(DELAY);
        digitalWrite(led, LOW);
        delay(DELAY);
        break;
  }
}