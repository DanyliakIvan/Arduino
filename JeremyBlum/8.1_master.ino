#include <SPI.h>

void setup() 
{
  SPI.begin();
  
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  
  String congratulations = "HelloWorld!";
  digitalWrite(10, LOW);
  for(int i = 0; i < congratulations.length(); i++)
  {
	SPI.transfer(congratulations[i]);
	delay(10);
  }
  digitalWrite(10, HIGH);
}

void loop() 
{
	
}