
int analogPin = 0;


void setup() 
{
  Serial.begin(9600);
  pinMode(analogPin, INPUT);
}

void loop() 
{
  Serial.println(analogRead(analogPin));
  delay(1000);
}