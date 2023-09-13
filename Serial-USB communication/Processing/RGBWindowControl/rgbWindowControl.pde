// Import and initialise serial library

import processing.serial.*;
PImage img;    // create image variable and set type to PImage
Serial port;


void setup() {
 size(640, 256);
 img = loadImage("hsv.jpg");    // Storing image in variable
 port = new Serial (this, "COM5", 115200);
}

void draw() {
  background(0);    // Black background
  image(img, 0, 0);    // Overlay image
}

void mousePressed() {
  color c = get(mouseX, mouseY);    // Get colour of pixel mouse pressed (in csv of RGB values)
  String colors = int(red(c)) + "," + int(green(c)) + "," + int(blue(c)) + "\n";    // Extract values from colour
  print(colors);
  
  port.write(colors);
}
