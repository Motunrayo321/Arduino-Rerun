#include <Servo.h>

const int POT = A0;
const int SERVO = 9;

Servo servo;

int angle;


void setup() {
  servo.attach(SERVO);
  
}

void loop() {
  angle = analogRead(POT);
  angle = map(angle, 0, 1023, 0, 179);

  servo.write(angle);
  delay(15);
}
