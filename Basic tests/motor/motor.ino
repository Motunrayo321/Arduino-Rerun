const int MOTOR = 9;
const int POT = A0;


void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  int potValue = analogRead(POT);
  Serial.println(potValue);
  int motorSpeed = map(potValue, 0, 1023, 0, 255);

  analogWrite(MOTOR, motorSpeed);

  
}
