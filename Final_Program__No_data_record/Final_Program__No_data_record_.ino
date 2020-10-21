#include <LiquidCrystal.h>
  const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include <dht.h>
  dht DHT;
  #define DHT11_PIN A2
int fan=12; // fan
int humidifier=11; //humidifier 

 
void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
}
void loop(){

int chk = DHT.read11(DHT11_PIN);

  lcd.setCursor(1, 1);
    lcd.print("HUM: ");
      lcd.print(DHT.humidity);
        lcd.print(" %");
  lcd.setCursor(0, 0);
      lcd.print("TEMP: ");
        lcd.print(DHT.temperature);
          lcd.print(" C");

  delay(1500);
    
  if (DHT.humidity<=38) {
    analogWrite(humidifier, 255);
      delay(2000);
    analogWrite(humidifier, 0);
    analogWrite(fan, 255);
      delay(3000);
    analogWrite(fan, 0);
  }
  if (DHT.humidity>40) {
    analogWrite(fan, 255);
  }
  if (DHT.humidity<=40) {
    analogWrite(fan, 0);
 }
}
