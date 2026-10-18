#include <Arduino.h>

#define LED 3
#define BTN 4
#define POT A0
#define LDR A1

#define DELAY_MIN 100
#define DELAY_MAX 1000

enum Mode { MODE_NONE, MODE_POT, MODE_LDR, MODE_PUSH, MODE_TOGGLE };

Mode mode = MODE_NONE;
bool toggleState = false;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(POT, INPUT);
    pinMode(LDR, INPUT);
    pinMode(BTN, INPUT_PULLUP);
    Serial.begin(9600);
    Serial.println("Send 1 (pot), 2 (ldr), 3 (push), 4 (toggle)");
}

void potMode() {
    int read = analogRead(POT);
    int delayTime = map(read, 0, 1023, DELAY_MIN, DELAY_MAX);

    Serial.print("Potentiometer value: ");
    Serial.println(read);
    Serial.print("Delay time: ");
    Serial.println(delayTime);

    digitalWrite(LED, HIGH);
    delay(delayTime/2);
    digitalWrite(LED, LOW);
    delay(delayTime/2);
}

void ldrMode() {
    int read = analogRead(LDR);
    int level = map(read, 0, 1023, 0, 255);
    analogWrite(LED, level);

    Serial.print("LDR value: ");
    Serial.println(read);
    Serial.print("LED level: ");
    Serial.println(level);
    delay(100);  // keeps the serial output readable
}

void pushMode() {
    digitalWrite(LED, digitalRead(BTN) == LOW ? HIGH : LOW);
}

void toggleMode() {
    static bool lastPressed = false;
    bool pressed = (digitalRead(BTN) == LOW);

    if (pressed && !lastPressed) {      // only act on the press itself
        toggleState = !toggleState;
        digitalWrite(LED, toggleState ? HIGH : LOW);
        delay(50);                      // debounce
    }
    lastPressed = pressed;
}

void readCommand() {
    if (Serial.available() <= 0) return;

    char c = Serial.read();
    Mode newMode = mode;

    switch (c) {
        case '1': newMode = MODE_POT;    break;
        case '2': newMode = MODE_LDR;    break;
        case '3': newMode = MODE_PUSH;   break;
        case '4': newMode = MODE_TOGGLE; break;
        case '\n':
        case '\r':
        case ' ':
            return;                      // ignore whitespace, keep current mode
        default:
            Serial.println("Unknown command");
            return;                      // invalid input never changes the mode
    }

    if (newMode != mode) {
        mode = newMode;
        digitalWrite(LED, LOW);          // clean slate when switching modes
        toggleState = false;
        Serial.print("Mode: ");
        Serial.println(c);
    }
}

void loop() {
    readCommand();

    switch (mode) {
        case MODE_POT:    potMode();    break;
        case MODE_LDR:    ldrMode();    break;
        case MODE_PUSH:   pushMode();   break;
        case MODE_TOGGLE: toggleMode(); break;
        case MODE_NONE:   break;
    }
}