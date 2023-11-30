
#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // establishing LCD
const int motorPin1 = 7; // setting pins to arduino
const int motorPin2 = 8;  // setting pins to arduino
void setup() {
  dht.begin();
  lcd.backlight();
  lcd.init();
  lcd.clear(); // turning on and clearing LCD screen
  pinMode(motorPin1, OUTPUT); // establishing pins
  pinMode(motorPin2, OUTPUT);// establishing pins
}
void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);// setting the cursor for the LCD screen
  lcd.print("Temp = ");
  float tempC = dht.readTemperature(); // saving data from DHT sensor
  float tempF = tempC * 9 / 5 + 32; // converting celsius to fahrenheit
  lcd.print(tempF); // displaying temperature on LCD display
  lcd.print("F");
  if (tempF > 78) { //if statement for barrier temperature
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW); // changing polarity of motor
    lcd.setCursor(0, 1);
    lcd.print("Direction: IN");
  } else {      
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH); // changing polarity of motor
    lcd.setCursor(0, 1);
    lcd.print("Direction: OUT");
  }
  delay(500);
  lcd.clear();
}
