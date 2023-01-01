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
    String message = "";
    message += temp;
    message += "C,";
    message += humi;
    message += "%.";
    
    Serial.print(message);

	  permission = 0;
  }
}

void receiveEvent(int howMany)
{
  temp = Wire.read();
  humi = Wire.read();
  permission = 1;
}