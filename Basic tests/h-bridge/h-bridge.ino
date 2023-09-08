const int ENPIN = 9;
const int APIN1 = 2;
const int APIN2 = 3;

const int POT = A0;



void setup() {
  // put your setup code here, to run once:
  pinMode(APIN1, OUTPUT);
  pinMode(APIN2, OUTPUT);
  pinMode(ENPIN, OUTPUT);

  Serial.begin(115200);
}


void forward(int rate) {
  digitalWrite(ENPIN, LOW);
  
  digitalWrite(APIN1, HIGH);
  digitalWrite(APIN2, LOW);

  analogWrite(ENPIN, rate);
  
}


void backward(int rate) {
  digitalWrite(ENPIN, LOW);
  
  digitalWrite(APIN1, LOW);
  digitalWrite(APIN2, HIGH);

  analogWrite(ENPIN, rate);
  
}


void stop(int rate) {
  digitalWrite(ENPIN, LOW);
  
  digitalWrite(APIN1, HIGH);
  digitalWrite(APIN2, LOW);

  analogWrite(ENPIN, rate);
  
}


void loop() {
  // put your main code here, to run repeatedly:
  int speed = analogRead(POT);
  int Speed;

  Serial.println(speed);
  
  if (Speed > 562) {
    Speed = map(speed, 563, 1023, 0, 255);
    forward(Speed);
  }
  else if (Speed < 462) {
    Speed = map(speed, 461, 0, 0, 255);
    backward(Speed);
  }
  else {
    stop(Speed); 
  }
  
  delay(200);
  Serial.println(POT);
}
