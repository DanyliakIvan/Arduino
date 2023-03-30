#include <SPI.h> 
#include <MFRC522.h>

MFRC522 RFID(10, 9);
MFRC522::MIFARE_Key key;

byte data[5];
byte ledAllow = 8;
byte ledDisallow = 7;
byte allowedID[4] = {0xB3, 0xB0, 0xE3, 0x12};
                                  
void setup() 
{ 
  SPI.begin();
  Serial.begin(9600);
  RFID.PCD_Init();

  for(byte i = 0; i < 6; i++)
    key.keyByte[i] = 0xFF;

  pinMode(ledAllow, OUTPUT);
  pinMode(ledDisallow, OUTPUT);
}
void loop() 
{ 
  if(!RFID.PICC_IsNewCardPresent())
    return;

  if(RFID.PICC_ReadCardSerial())
    return;
  
  MFRC522::PICC_Type piccType = RFID.PICC_GetType(RFID.uid.sak);

  if(piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K)
    return;

  String str;
  for (int i = 0; i < 4; i++)
    data[i] = RFID.uid.uidByte[i];

  if(checkID(RFID.uid.uidByte, RFID.uid.size))
  {
    digitalWrite(ledAllow, HIGH);
    delay(1000);
    digitalWrite(ledAllow, LOW);
  }
  else
  {
    digitalWrite(ledDisallow, HIGH);
    delay(1000);
    digitalWrite(ledDisallow, LOW);
  }
    
  printHex(RFID.uid.uidByte, RFID.uid.size);

  RFID.PICC_HaltA();

  RFID.PCD_StopCrypto1();
}   

bool checkID(byte * arr, byte size)
{
  bool check = true;
  for(byte i = 0; i < size; i++)
  {
    if(arr[i] != allowedID[i])
    {
      check = false;
      return check;
    }
  }
}

void printHex(byte * arr, byte size)
{
  for(byte i = 0; i < size; i++)
  {
    Serial.print(arr[i] < 0x10 ? "0" : "");
    Serial.print(arr[i], HEX);
  }
  Serial.println("");
}



