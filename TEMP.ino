#include <LiquidCrystal.h>  
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

const int L = 7; // pin led
float temperaturec=0;
void setup() {
 
 pinMode(L,OUTPUT); 
// Serial.begin(9600);
 lcd.begin(6,2); 
 lcd.print("Help2Grow");
}

void loop() {
  lcd.setCursor(0, 1);  
  //lcd.print(millis()/1000);

  lcd.setCursor(1,2);
  int reading = analogRead(0);
 //converting that reading to voltage, for 3.3v arduino use 3.3
float voltage = reading * 5.0;
voltage /= 1024.0; 
// now print out the temperature
 temperaturec = (voltage - 0.5) * 100; 
  lcd.print(temperaturec );
  lcd.print(" C" );
  delay(4000);
  
  
if(temperaturec > 19){
lcd.setCursor(1,2);
  lcd.print("Fun Mode On");
 delay(500);
 digitalWrite(L,HIGH);
 }else digitalWrite(L, LOW);
 
}         





