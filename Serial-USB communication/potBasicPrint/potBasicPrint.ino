const int POT = A0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  int value = analogRead(POT);
  int per = map(value, 0, 1023, 0, 100.0);
  
  Serial.print("Analog reading: ");
  Serial.print(value);

  Serial.print("  Percentage: ");
  Serial.print(per);
  Serial.println("%");

  delay(1000);
}
