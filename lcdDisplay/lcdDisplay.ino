#include <LiquidCrystal.h>


LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

int tim = 0;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);

  lcd.print("Hello");
  lcd.print("World");

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Hello");
  lcd.print(" World");

  lcd.setCursor(0, 1);
  lcd.print(tim);

  delay(1000);
  tim++;

}
