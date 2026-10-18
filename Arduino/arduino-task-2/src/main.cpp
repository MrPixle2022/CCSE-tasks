#include <Arduino.h>

#define LED 3
#define POT A0
#define LDR A1

#define DELAY_MIN 200
#define DELAY_MAX 1000

/*
#define BTN 3
*/

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(POT, INPUT);
    Serial.begin(9600);
}

void potMode(){
    int read = analogRead(POT);
    Serial.print("Potentiometer value: ");
    Serial.println(read);

    int delayTime = map(read, 0, 1023, DELAY_MIN, DELAY_MAX);
    Serial.print("Delay time: ");
    Serial.println(delayTime);
    digitalWrite(LED, HIGH);
    delay(delayTime);
    digitalWrite(LED, LOW);
    delay(delayTime);
}

void ldrMode(){
    int read = analogRead(LDR);
    Serial.print("LDR value: ");
    Serial.println(read);

    int level = map(read, 0, 1023, 0, 255);
    analogWrite(LED, level);
    Serial.print("LED level: ");
    Serial.println(level);
}

void loop(){
    if(Serial.available() > 0){
        char command = Serial.read();
        switch(command){
            case '1':
                Serial.println("Command 1 received");
                break;
            case '2':
                Serial.println("Command 2 received");
                break;
            case '3':
                Serial.println("Command 3 received");
                break;
            default:
                digitalWrite(LED, LOW);
                Serial.println("Unknown command");
        }
    }

    delay(100);
}