const int POT = 0;
const int MIN_LIGHT = 10;   //가장 어두울 때의 값
const int MAX_LIGHT = 720;  //가장 밝을 때의 값
int val = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(POT);
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);   //8비트 값으로 맵핑
  val = constrain(val, 0, 255);
  Serial.println(val);
  delay(500);
}
