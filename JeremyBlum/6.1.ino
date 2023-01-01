int ledPin = 13;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  int k = 0;
  
  while(Serial.available() == 0); 
  k = Serial.read();
  
  delay(10);
  
  while(Serial.available() > 0) Serial.read();
  
  k-=48;
  
  if(k % 2 != 0)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("The led is on");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("The led is off");
  }
}