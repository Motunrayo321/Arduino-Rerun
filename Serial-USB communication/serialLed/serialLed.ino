const int LED = 9;

char data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 if (Serial.available() > 0) {
  data = Serial.read();
  
  if (data == '1') {
    digitalWrite(LED, HIGH);
    Serial.println("On");
    // delay(1000);   // in case of else instead of else if
  }
  else if (data == '0') {   // To make Serial.read() not recognise '\n' at the end as a character
    digitalWrite(LED, LOW);
    Serial.println("Off");
  }
  
 }
}
