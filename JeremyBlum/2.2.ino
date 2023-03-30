
int switchPin = 8;
int ledPin = 13;
bool previousButton = LOW;
bool currentButton = LOW;
bool ledOn = false;


void setup() 
{
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

bool debounceButton (bool last)
{
  bool current = digitalRead(switchPin);
  if(last != current)
  {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void loop() 
{
  currentButton = debounceButton(previousButton);
  if(currentButton == HIGH && previousButton == LOW)
  {
   ledOn = !ledOn;
  }
  previousButton = currentButton;
  digitalWrite(ledPin, ledOn); 
}