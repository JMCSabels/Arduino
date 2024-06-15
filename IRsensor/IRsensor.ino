#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//IR SENSOR VARIABLES, model # hw-201
const int irSensorPin = A0;
int irValue = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("penis!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);

  // print the number of seconds since reset:         READING IN IR VALUE, for the 
  irValue = analogRead(irSensorPin);

  Serial.print("IR Sensor Value: ");
  Serial.println(irValue);
  delay(100);
  lcd.print(irValue);
}