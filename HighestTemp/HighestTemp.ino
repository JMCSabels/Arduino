<<<<<<< HEAD

//Coffee maker heating coil check, prints the highest temp experienced. 200F is the target.
=======
//Coffee maker heating coil check, prints the highest temp experienced. 200F is the target.

>>>>>>> origin/master
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h> 

#define ONE_WIRE_BUS A0
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);

#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

long highestTemp = 0;

//temp SENSOR VARIABLES, model #DS18B20

void setup() {

  sensors.begin();
  
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Temp(F):");
}

void loop() {

  sensors.requestTemperatures();
  lcd.setCursor(0, 1); //row 0, slot 1

  // input for thermometer
  long tempValue = sensors.getTempCByIndex(0);
  tempValue = tempValue*1.8 + 32;

  if(tempValue > highestTemp)
  {
    highestTemp = tempValue;
  }

  Serial.print("IR Sensor Value: ");
  Serial.println(tempValue);
  delay(100);
  lcd.print(highestTemp);
}
