import processing.serial.*;
Serial port;

String temp = "";
String humi = "";
String data = "";
int index = 0;
PFont font;

void setup()
{
  size(200, 200);
  port = new Serial(this, "COM3", 9600);
  port.bufferUntil('.');
  font = loadFont("AgencyFB-Bold-100.vlw");
  textFont(font, 100);
}

void draw()
{
  background(0, 0, 0);
  fill(170, 0, 0);
  text(temp, 30, 90);
  fill(170, 0, 0);
  text(humi, 30, 190);
}

void serialEvent(Serial port)
{
  data = port.readStringUntil('.');
  data = data.substring(0, data.length() - 1);
  index = data.indexOf(',');
  temp = data.substring(0, index);
  humi = data.substring(index + 1, data.length());
}
