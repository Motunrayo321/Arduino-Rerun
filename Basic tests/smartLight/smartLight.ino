const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

const int pRes = A0;

int resMax = 1000;
int resMin = 200;

int ledMax = 255;
int ledMin = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  Serial.begin(115200);

}


void loop() {
  // put your main code here, to run repeatedly:
  
  int resValue = analogRead(pRes);
  Serial.println(resValue);

  int ledValue = map(resValue, resMin, resMax, ledMin, ledMax);
  ledValue = constrain(ledValue, 0, 255);

  analogWrite(RED, ledValue);
  analogWrite(GREEN, ledValue);
  analogWrite(GREEN, ledValue);
  delay(500);

}
