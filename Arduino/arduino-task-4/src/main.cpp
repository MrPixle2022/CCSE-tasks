#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns
// define the cymbols on the buttons of the keypads

// char op;
// last row does not work :p
char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', '_'},
    {'4', '5', '6', '_'},
    {'7', '8', '9', '_'},
    {'*', '0', '/', '_'}};
byte rowPins[ROWS] = {9, 8, 7, 6}; // connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; // connect to the column pinouts of the keypad

// initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
/*LCD connection (I2C)
VCC ->  5V
GND ->  GND
SDA ->  A4
SCL ->  A5
*/
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.init();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.backlight();
}

String buffer = "";
String n1 = "";
char op = 0;
bool isFirstInput = true;

void loop()
{
  char btn = customKeypad.getKey();
  if (!btn)
    return;

  if (btn == '*' || btn == '/')
  {
    if (buffer.length() == 0)
      return; // ignore operator with no number typed

    if (isFirstInput)
    {
      n1 = buffer;
      op = btn;
      isFirstInput = false;
      buffer = "";
      lcd.print(btn); // show the operator on screen
    }
    else
    {
      // second operator press acts as "equals"
      long num1 = n1.toInt();
      long num2 = buffer.toInt();

      lcd.clear();
      if (op == '/' && num2 == 0)
      {
        lcd.print("Error: Div by 0");
      }
      else
      {
        lcd.print("Result: ");
        lcd.print(op == '*' ? num1 * num2 : num1 / num2);
      }
      delay(2000);
      lcd.clear();

      buffer = "";
      isFirstInput = true;
    }
  }
  else
  {
    buffer += btn;
    lcd.print(btn);
  }
}