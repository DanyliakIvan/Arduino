#include <Servo.h> 

Servo TestServo;

int servoPin = 9; 
                                  
void setup() 
{ 
  TestServo.attach(servoPin);
}
void loop() 
{ 
  for(int i = 0; i <= 180; i+=20)
  {
    TestServo.write(i);
    delay(1000);
  }
}