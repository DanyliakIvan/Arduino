#include <SPI.h>

int SS_PIN = 10;
int trigPin = 5;
int echoPin = 4;

void setup() 
{
  SPI.begin();
  
  pinMode(SS_PIN, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  digitalWrite(SS_PIN, HIGH);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delay(5);	
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  
  int duration = pulseIn(echoPin, HIGH);
  
  int cm = (duration / 2) / 29.1;
  
  byte msg = constrain(cm, 5, 254);
  
  digitalWrite(SS_PIN, LOW); 
  SPI.transfer(msg);
  delay(10);
  digitalWrite(SS_PIN, HIGH);
  
  delay(1000);
}