// Import and initialise serial library

import processing.serial.*;
Serial port;    // initialise instance

float brightness = 0;

void setup() {
 size(500,500);    // Create window of 500 by 500 pixels
 port = new Serial (this, "COM5", 115200);    // Information about serial port
 port.bufferUntil('\n');    // Define when to do something with input.
 
 // Calls SerialEvent now
}

void draw() {
  background(brightness, 0, brightness);    // Assigns brightness value to background of window
}

void serialEvent (Serial port) {
 brightness = float(port.readStringUntil('\n'));    // Reads serial data, changes type from string to float and assigns it to brightness
 
 // Calls draw now
}
