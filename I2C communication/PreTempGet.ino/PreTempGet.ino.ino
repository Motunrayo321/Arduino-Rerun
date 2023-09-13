// Only thing different from tempGet is end character of serial prints

#include <Wire.h>   // Include Wire (I2C) library

const int address = 72;   // (1000 100 in decimal (for TC74); try B1000100 when code works)


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Wire.begin();   // Initialise protocol

}

void loop() {
  // put your main code here, to run repeatedly:

  Wire.beginTransmission(address);    // Send device address in write mode (for device)
  Wire.write(0);    // Indicate read request -> 0
  Wire.endTransmission();   // Close write mode


  Wire.requestFrom(address, 1);    // Get 1 byte (8 bits) from device in read mode

  while (Wire.available() == 0);   // Wait until data is available (device is ready for transfer) and do nothing

  int value = Wire.read();   // Read data from device and store in variable


  int fValue = round(value*9.0/5.0 + 32.0);    // Convert data to farenheit

  Serial.print(value); Serial.print("C, ");   // To make it easier to parse for processing 
  Serial.print(fValue); Serial.print("F.");   // Look for ',' instead of carriage return
}
