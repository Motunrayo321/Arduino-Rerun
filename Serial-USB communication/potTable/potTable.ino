const int POT = A0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("\nAnalog Pin\tRaw Value\tPercentage");
  Serial.println("------------------------------------------");
  
  for (int i = 0; i < 10; i++) {
    int val = analogRead(POT);
    int per = map(val, 0, 1023, 0, 100);

    Serial.print("A0\t\t");
    
    Serial.print(val, BIN);
    Serial.print("\t\t");

    Serial.print(per);
    Serial.println("%");

    delay(1000);
  }

  delay(1000);
}
