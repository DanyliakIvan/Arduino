#define SS_PIN 10
#define MOSI_PIN 11
#define MISO_PIN 12
#define SCK_PIN 13

void setup() 
{
  SPCR = B00000000;
  SPCR = (1 << SPE);
  Serial.begin(9600);
  pinMode(SS_PIN, INPUT);
  pinMode(MOSI_PIN, INPUT);
  pinMode(MISO_PIN, OUTPUT);
  pinMode(SCK_PIN, INPUT);
}

byte spi_receive()
{
  while (!(SPSR & (1 << SPIF))) {};
  return SPDR;
}

void loop() 
{
  Serial.print("cm = " );
  Serial.println(receiveStr());
}

int receiveStr()
{
  byte cm = 0;
  int i = 0;
  while (i == 0)
  {
    if (digitalRead(SS_PIN) == LOW)
    {
      cm = spi_receive();
      delay(10);
    }
  }
  
  return cm;
}