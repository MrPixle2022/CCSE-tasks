#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define LDR A3
#define TITLE_DELAY 1000

/*LCD connection (I2C)
VCC ->  5V
GND ->  GND
SDA ->  A4
SCL ->  A5
--------
LCD connection (no I2C)
VSS ->  GND
VDD ->  5V
VO -> (a leg of a 10K potentiometer || GND)
RW ->  GND
E ->  11
D0-D3 ->  leave
D4 ->  5
D5 ->  4
D6 ->  3
D7 ->  2

use the following

#include <LiquidCrystal.h>

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
*/
LiquidCrystal_I2C lcd(0x27, 16, 2);

void printName(String first, String last){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(first);
    lcd.setCursor(0, 1);
    lcd.print(last);
    delay(TITLE_DELAY);
}

void writeToLcd(String msg, int read){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(msg + String(read));
}

void setup(){
    Serial.begin(9600);
    pinMode(LDR, INPUT);

    //basic lcd configuration
    lcd.init();
    lcd.backlight();
    //extra magic
    printName("Amr", "Yasser");
    printName("Omar", "Ayman");
    printName("Abdelrahman", "Zakzouk");
    printName("Moamen", "Mahmoud");
}

void loop(){
    int read = map(analogRead(LDR), 0, 1023, 0, 100);
    Serial.println("read: " + String(read));

    switch (read)
    {
    case 0 ... 50:
        writeToLcd("Dark ", read);
        break;
        default:
        writeToLcd("Bright ", read);
        break;
    }

    delay(100);
}