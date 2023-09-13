const int DATA = 8;
const int LATCH = 9;
const int CLOCK = 10;

int values[14] = {1, 2, 4, 8, 16, 32, 64, 128, 64, 32, 16, 8, 4, 2};;

void setup() {
  // put your setup code here, to run once:

  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 14; i++) {
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, values[i]);
    digitalWrite(LATCH, HIGH);
    delay(100);

    Serial.println(values[i]);
  }
}
