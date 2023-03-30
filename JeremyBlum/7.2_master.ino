#include <dht.h>
#include <Wire.h>

dht DHT;

byte dataPin = 8;
byte SLAVE_ID = 8;

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
}

void loop() 
{
  int readData = DHT.read11(dataPin);

  float temp = DHT.temperature;
  float humi = DHT.humidity;

  byte responce[2];
  responce[0] = (char)temp;
  responce[1] = (char)humi;
  
  Wire.beginTransmission(SLAVE_ID);
  Wire.write(responce, 2);
  Wire.endTransmission();

  delay(2000);
}