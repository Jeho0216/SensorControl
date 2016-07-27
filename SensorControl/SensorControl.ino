#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
//RS, E, D4, D5, D6, D7

const int POT = 0;
const int BTN = 14;
const int MIN_LIGHT = 10;   //가장 어두울 때의 값
const int MAX_LIGHT = 720;  //가장 밝을 때의 값

int val = A0;
boolean lastBTN = LOW;
boolean currentBTN = LOW;


void printBrightness(void){   //밝기값을 출력하는 함수
  val = analogRead(POT);
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);   //8비트 값으로 맵핑
  val = constrain(val, 0, 255);
}

void print

char valueList[3][12] ={
   "brightness:",
   "temp:",
   "humidity:"
  };

boolean debounce(boolean last){
    boolean current = digitalRead(BTN);   //버튼 값 읽기
    if(last != current){
        delay(5);
        current = digitalRead(BTN);
      }
      return current;
  }

void setup() {
  // put your setup code here, to run once:
  boolean screen = 0;    //화면 번호
  Serial.begin(9600);
  pinMode(BTN, INPUT); //화면 전환 버튼
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentBTN = debounce(lastBTN);
}
