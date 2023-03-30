
int pause = 10;
int ledPin = 13;
int photoresistorPin = 0;

void setup() 
{
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(photoresistorPin, INPUT);
}

void loop() 
{  
  int photoresistorData = analogRead(photoresistorPin);

  photoresistorData = constrain(photoresistorData, 100, 700);
  photoresistorData = map(photoresistorData, 100, 700, 150, 2);

  if(photoresistorData > 5)
  digitalWrite(ledPin, HIGH);
  else
  digitalWrite(ledPin, LOW);
  
  Serial.println(photoresistorData);

  pause = photoresistorData * 0.3;

  if(pause < 3) pause = 3;

  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(pause);

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(pause);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(pause);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(pause);
}