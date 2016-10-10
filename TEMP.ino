#include <LiquidCrystal.h>  
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

const int L = 6; // pin led
float temperatureC;
void setup() {
 lcd.begin(16, 2); 
 lcd.print("Help2Grow"); 
 pinMode(L,OUTPUT); 
 Serial.begin(9600);
}

void loop() {


  int reading = analogRead(0);
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 // print out the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // now print out the temperature
 temperatureC = (voltage - 0.5) * 100; 
  lcd.setCursor(0, 1);  
  lcd.print(temperatureC);  
  lcd.print("°C");  

 Serial.print(temperatureC); 
 Serial.println(" °C");
 delay(500);

 if(temperatureC > 21){
 digitalWrite(L,HIGH);
 }else digitalWrite(L, LOW);
}         







