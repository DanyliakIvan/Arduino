#include <dht.h>
#include <Wire.h>

dht  DHT;

byte dataPin = 8;
byte permission = 0;
byte temp = 0;
byte humi = 0;

void setup() 
{
  Serial.begin(9600);
  Wire.begin(8);
  Wire.onReceive(receiveEvent);  
}

void loop() 
{
  if(permission)
  {
    Serial.print("Temperature = ");
    Serial.print(temp);
    Serial.print(" ");
    Serial.println("C ");
    Serial.print("Humidity = ");
    Serial.print(humi);
    Serial.println(" % ");
    Serial.println("");
	
	permission = 0;
  }
}

void receiveEvent(int howMany)
{
  temp = Wire.read();
  humi = Wire.read();
  permission = 1;
}