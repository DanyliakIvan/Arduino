
int analogPin = 0;

int ledPin = 13;


void setup() 
{
  Serial.begin(9600);
  pinMode(analogPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{  
  int dataFromAnalogPin = analogRead(analogPin);
  Serial.println(dataFromAnalogPin);
  if(dataFromAnalogPin < 150)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  delay(1000);
}