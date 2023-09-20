#include <LiquidCrystal.h>


LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int tim = 0;


byte p20[8] = {
  B10000, 
  B10000, 
  B10000, 
  B10000, 
  B10000, 
  B10000, 
  B10000, 
  B10000, 
  };

byte p40[] = {
  B11000, 
  B11000, 
  B11000, 
  B11000, 
  B11000, 
  B11000, 
  B11000, 
  B11000, 
  };

byte p60[] = {
  B11100, 
  B11100, 
  B11100, 
  B11100, 
  B11100, 
  B11100, 
  B11100, 
  B11100, 
  };

byte p80[] = {
  B11110, 
  B11110, 
  B11110, 
  B11110, 
  B11110, 
  B11110, 
  B11110, 
  B11110, 
  };

byte p100[] = {
  B11111, 
  B11111, 
  B11111, 
  B11111, 
  B11111, 
  B11111, 
  B11111, 
  B11111, 
};


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Loading...");
  delay(1000);

  lcd.createChar(0, p20);
  lcd.createChar(1, p40);
  lcd.createChar(2, p60);
  lcd.createChar(3, p80);
  lcd.createChar(4, p100);

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 1);
  lcd.print("                ");

  for (int i=0; i<16; i++) {

    for (int j=0; j<5; j++) {
      lcd.setCursor(i, 1);
      lcd.write(j);
      
      delay(50);
    }
  }
}
