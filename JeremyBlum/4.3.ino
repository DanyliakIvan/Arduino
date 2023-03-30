
int analogPin = 0;

int ledPin = 9;


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

  dataFromAnalogPin = constrain(dataFromAnalogPin, 100, 200);
  int levLevel = map(dataFromAnalogPin, 100, 200, 255, 0);

  analogWrite(ledPin, levLevel);
  delay(50);
}