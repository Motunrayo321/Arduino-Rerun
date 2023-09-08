const int BLUE_LED = 9;
int button = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode(BLUE_LED, OUTPUT);
  // pinMode(button, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(button) == HIGH) {
    digitalWrite(BLUE_LED, HIGH);
  }
  else {
    digitalWrite(BLUE_LED, LOW);
  }
}
