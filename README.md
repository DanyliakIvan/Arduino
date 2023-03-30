# Arduino

https://www.youtube.com/playlist?list=PLA567CE235D39FA84


Short description:

1 - getting acquainted.
2 - buttons, PWN and functions.
3 - electrical engineering bacics.
4 - analog inputs.
5 - motors and transistors.
6 - serial communication and processing.
7 - I2C HW i-face.
8 - SPI HW i-face.
9 - It must have been XBEE (wireless communication), but I do not have anyone.
10 - I do not have Shmmit's trigger.
11 - I do not have a SD-card module.
12 - RFID.
13 - to be continued...


More details:


1.1:

led turns on and off every 1s.


2.1:

if the button is pressed, the led will turn on.
if the button isn't pressed, the led won't turn on.

2.2:

first pressed - the led turns on.
second - off.
third - on.
...

2.3:

every pressed changes the brightness by 51. after 255 the brightness will be set to 0.



3.1:

connected the potentiometer. we can see numbers from 0 to 1023 in output using Serial PORT.



4.1:

output value from photoresistor (voltage divider) 

4.2: 

the same that in 4.1 and added LED (simple hightlight)

4.3:

the same that in 4.2, but it's smart hightlight (change brightness)


5.1:

controlling the step motor Arduino. stable speed.

5.2:

the motor speed depends on brightness in the room (using photoresistor)

5.3: 

turn the servo from 0 to 180 in increments of 20 degrees


6.1:

receiving character from computer using Serial port (UART). 
not even numbers turn the led off and even numbers turn the led on.
the program accepts only first number. the rest of numbers will be rejected.

6.2:

created the window using processing and changing the color of window using potentiometer.
it needs two files to use this lesson: 6.2.ino and 6.2.pde.


7.1:

output temperature and humidity using DHT11 sensor

7.2:

the same that in 7.1 and added I2C. (Arduino2 -> DHT11 -> Arduino2 -> Arduino1 -> Serial)

7.3:

the same that in 7.2 and added processing.


8.1:
													  (SPI)   (UART)
tried SPI HW i-face. just send congtatulations (Master -> Slave -> PC)

8.2:

just added HC-SR04. Master receive data from distance sensor and send it to Slave. Then Slave sent it to PC.


9:

10:

11:

12:

was used RFID card reading. if it's a right card, blue led will turn on, wait 1s and turn off. if is not right - red led will turn on; 


...







Own:

1:

use 8-bit shift register

2: