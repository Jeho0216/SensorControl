#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
//RS, E, D4, D5, D6, D7

const int POT = 0;
const int MIN_LIGHT = 10;   //가장 어두울 때의 값
const int MAX_LIGHT = 720;  //가장 밝을 때의 값
int val = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.print("Test");
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(POT);
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);   //8비트 값으로 맵핑
  val = constrain(val, 0, 255);
  Serial.println(val);
  delay(500);
}
