
int switchPin = 8;
int ledPin = 9;
bool previousButton = LOW;
bool currentButton = LOW;
int ledLevel = 0;


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
   ledLevel += 51;
  }

  previousButton = currentButton;

  if(ledLevel > 255) 
  ledLevel = 0;

  analogWrite(ledPin, ledLevel);
}