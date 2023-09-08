const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;
const int BUTTON = 2;

bool ledState = LOW;

bool previous = LOW;
bool current = LOW;

bool previousBut = LOW;
bool currentBut = LOW;

int ledCount = 1;


void setup() {
  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  Serial.begin(112500);
  
}


boolean debounce(bool previous) {
  
  current = digitalRead(BUTTON);

  if (previous != current) {
    delay(5);
    
    current = digitalRead(BUTTON);
  }
  return current;
}


void colour(int count) {
  char colours[] = {RED, BLUE, GREEN};

  // Off
  if (count == 0) {
    digitalWrite(RED, LOW);
    Serial.println(colours[0]);
    digitalWrite(colours[1], LOW);
    digitalWrite(colours[2], LOW);
  }
  
  // Red
  else if (count == 1) {
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }

  // Green
  else if (count == 2) {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  }

  // Blue
  else if (count == 3) {
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
  }

  // Teal
  else if (count == 4) {
    analogWrite(RED, 0);
    analogWrite(GREEN, 127);
    analogWrite(BLUE, 127);
  }

  // Orange
  else if (count == 5) {
    analogWrite(RED, 127);
    analogWrite(GREEN, 127);
    analogWrite(BLUE, 0);
  }

  // Purple
  else if (count == 6) {
    analogWrite(RED, 127);
    analogWrite(GREEN, 0);
    analogWrite(BLUE, 127);
  }

  // White
  else if (count == 7) {
    analogWrite(RED, 85);
    analogWrite(GREEN, 85);
    analogWrite(BLUE, 85);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  currentBut = debounce(previousBut);

  if (previousBut == LOW && currentBut ==HIGH) {

    Serial.print(ledCount);
    colour(ledCount);
    ledCount ++;
  }

  if (ledCount == 8) {
      ledCount = 0;
  }
  previousBut = currentBut;
}
