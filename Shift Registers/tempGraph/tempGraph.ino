const int DATA = 8;
const int LATCH = 9;
const int CLOCK = 10;

const int TEMP = A0;

int temps[] = {0, 1, 7, 15, 31, 63, 127, 255};


void setup() {
  // put your setup code here, to run once:
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int tempValue = digitalRead(TEMP);
  int graph = map(tempValue, 24, 31, 0, 7);
  graph = constrain(graph, 0, 7);


  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, temps[graph]);
  digitalWrite(LATCH, HIGH);
  delay(1000);


}
