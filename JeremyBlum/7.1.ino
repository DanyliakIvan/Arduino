#include <dht.h>

dht  DHT;

int dataPin = 8;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int readData = DHT.read11(dataPin);

  float temp = DHT.temperature;
  float humi = DHT.humidity;

  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print(" ");
  Serial.println("C ");
  Serial.print("Humidity = ");
  Serial.print(humi);
  Serial.println(" % ");
  Serial.println("");

  delay(2000);
}