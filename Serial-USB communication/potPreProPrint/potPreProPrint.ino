const int POT = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int val = map(analogRead(POT), 0, 1023, 0, 255);
  Serial.println(val);

  delay(50);
}
