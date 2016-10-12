/*il circuito :
 * 
* Un sensore TMP rileva la temperatura ambientale:
* 
  * i piedini esterni vanno SX 5V e DX a massa 
  * il piedino centrsle collegato al pin A0


* Un Led a che si accende una volta superata una certa temperatura:
* 
  * Anodo . sul pin 2 
  * Katodo  con resistenza 220 Ω collegato a GND
  
* Uno schermo LCD per visualizzare i dati :
* 
 * pin RS collegato al pin digitale 12 
 * pin E (Enable) collegato al pin digitale 11 
 * pin D4 collegato al pin digitale 5 
 * pin D5 collegato al pin digitale 4 
 * pin D6 collegato al pin digitale 3 
 * pin D7 collegato al pin digitale 2 
 * pin R/W collegato al GND 
 * pin 1 e pin 5 collegati a GND 
 * pin 2 collegato a +Vcc 
 * pin 3 collegato al Pin centrale del Potenziometro/Trimmer 
 * 
* Un Potenziometro/Trimmer per regolare il constrato del LCD:
*
  * i piedini esterini vanno collegati SX massa DX 5V
  * quello centrale va collegato al Pin 3 del LCD
* 
* 
 
*/



#include <LiquidCrystal.h>  
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

const int L = 7; // pin led
float temperaturec=0;
void setup() {
 
 pinMode(L,OUTPUT); 
// Serial.begin(9600);
 lcd.begin(6,2); 
 lcd.print("Help2Grow");
 delay(3000);
}

void loop() {
 
  lcd.clear();
 
  lcd.setCursor(0,0);  
  //lcd.print(millis()/1000);

  int reading = analogRead(0);
 //converting that reading to voltage, for 3.3v arduino use 3.3
float voltage = reading * 5.0;
voltage /= 1024.0; 
// now print out the temperature
 temperaturec = (voltage - 0.5) * 100; 
  lcd.println("Temperatura:    \n");
  lcd.setCursor(1,1); 
  lcd.print(temperaturec + 0.7 );
  lcd.print(" C" );
  delay(7000);
  
  
if(temperaturec > 20){
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);

 digitalWrite(L,HIGH);
 }else digitalWrite(L, LOW);
 
}         





