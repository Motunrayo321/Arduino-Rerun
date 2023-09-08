const int LED = 9;
int button = 2;

boolean previous = LOW;
boolean current = LOW;

boolean ledState = LOW;

boolean previousBut = LOW;
boolean currentBut = LOW;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);

}


boolean debounce(boolean previous) {

  current = digitalRead(button);
  if (current != previous) {
    delay(5);

    current = digitalRead(button);
  }

  return current;
}


void loop() {
  // put your main code here, to run repeatedly:

  
  currentBut = debounce(previousBut);

  if (previousBut == LOW && currentBut == HIGH) {
    
    ledState = !ledState;
    digitalWrite(LED, ledState);
  }

  previousBut = currentBut;
}
