import processing.serial.*
Serial Port

String cValue = "";
String fValue = "";
String data = "";

int index = 0;

PFont font;

void setup() {
 size(400, 400);
 port = new Serial(this, "COM5", 9600);
 port.bufferUntil('.');
 
 font = loadFont("Arial-BoldMT-200.vlw");
 textFont(font, 200);
 
void draw() {
 background(0, 0, 0);
 
 fill(46, 209, 2);
 text(cValue, 70, 175);
 
 fill(0, 102, 153);
 text(fValue, 70, 370);
}
 
void serialEvent(Serial port) {
  data = port.readStringUntil('.');
  data = data.substring(0, data.length() - 1);
  
  index = data.indexOf(',');
  cValue = data.substring(0, index);
  fValue = data.substring(index + 1, data.length());
}
