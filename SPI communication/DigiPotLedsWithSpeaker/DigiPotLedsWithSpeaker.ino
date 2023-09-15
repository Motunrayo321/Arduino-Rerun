#include <SPI.h>    // Include SPI library

const int SS1 = 10;   // Chip select pin 1
const int SS2 = 9;    // Chip select pin 1

const byte REG0 = B00000000;    // Write address for POT 1 (address, write command, first 00 bits since value cannot be > 128)
const byte REG1 = B00010000;    // Write address for POT 2

const int SPEAKER = 8;

int freq = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(SS1, OUTPUT);
  pinMode(SS2, OUTPUT);

  SPI.begin();    // Initialise SPI
}

void setValue(int SS, int reg, int value) {
  digitalWrite(SS, LOW);    // Activate chip by puling low
  SPI.transfer(reg);    // Transfer write address
  SPI.transfer(value);    // Transfer led value
  digitalWrite(SS, HIGH);   // Release pin
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(SPEAKER, freq);

  for (int i = 0; i <= 128; i++) {
    setValue(SS1, REG0, i);   // First pot of first pin
    setValue(SS1, REG1, i);   // Second pot of first pin
    setValue(SS2, REG0, i);   // First pot of second pin
    setValue(SS2, REG1, i);   // Second pot of second pin
    delay(10);
  }
  delay(300);

  for (int i = 127; i >= 0; i--) {
    setValue(SS1, REG0, i);
    setValue(SS1, REG1, i);
    setValue(SS2, REG0, i);
    setValue(SS2, REG1, i);
    delay(10);
  }
  delay(300);

  freq = freq + 100;
  if (freq == 2000) freq = 100;
}
