char data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {   // Check for incoming bytes
    data = Serial.read();   // Read data in buffer
    Serial.print(data);
  }
}
