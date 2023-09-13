const int DATA = 8;
const int LATCH = 9;
const int CLOCK = 10;


void setup() {
  // put your setup code here, to run once:
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, 100);
  // shiftOut(DATA, CLOCK, MSBFIRST, B11111111);
  digitalWrite(LATCH, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

}
