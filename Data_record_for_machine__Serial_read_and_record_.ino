#include <dht.h>
  dht DHT;
  #define DHT11_PIN 2
int fan=12; // fan
int humidifier=11; //humidifier 

void setup(){
Serial.begin(9600);
Serial.println("CLEARDATA");
Serial.println("LABEL,Time,Temperature,Humidity");
Serial.println("RESETTIMER");
}

void loop(){

int chk = DHT.read11(DHT11_PIN);

Serial.print("DATA,TIME,");
Serial.print(DHT.temperature);
Serial.print(",");
Serial.println(DHT.humidity);
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
