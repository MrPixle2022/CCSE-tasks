#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define LDR A3
#define TITLE_DELAY 1000

/*LCD connection
VCC ->  5V
GND ->  GND
SDA ->  A4
SCL ->  A5
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