#include <Arduino.h>

void setup() {
    Serial.begin(9600);
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
                Serial.println("Unknown command");
        }
    }
}