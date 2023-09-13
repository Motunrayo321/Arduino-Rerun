const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

int rVal = 0;
int gVal = 0;
int bVal = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    rVal = Serial.parseInt();   // assign first value in csv input
    gVal = Serial.parseInt();   // assign second value in csv input
    bVal = Serial.parseInt();   // assign third value in csv input
  }

  if (Serial.read() == '\n') {
    analogWrite(RED, rVal);
    analogWrite(GREEN, gVal);
    analogWrite(BLUE, bVal);

    // Serial.println(rVal, gVal, bVal);
  }
}
