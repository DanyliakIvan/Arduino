
byte microphonePin = 8;
byte relay = 12;
bool priviousState = false;

void setup() 
{
  Serial.begin(9600);
  pinMode(microphonePin, INPUT);
  pinMode(relay, OUTPUT);

}

void loop() 
{
  int microData = digitalRead(microphonePin);

  if(microData == HIGH)
  {
    if(!priviousState)
    {
      digitalWrite(relay, HIGH);
      priviousState = true;
      delay(1000);
    }
    else
    {
      digitalWrite(relay, LOW);
      priviousState = false;
      delay(200);
    }
  }
  delay (100);
}
