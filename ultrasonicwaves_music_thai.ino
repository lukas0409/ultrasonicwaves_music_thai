/*
  HC-SR04 초음파센서와 피에조 버저를 활용해서
  초음파 센서의 값을 음계로 바꾸어 버저에서 출력해 주는 코드
*/

#define TRIG 8 // 초음파발생 핀
#define ECHO 9 // 거리 읽어오는 핀
#define BUZZER 10 // 버저

int us;
int cm; // 초음파 값

void setup() {
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT); 
  pinMode(ECHO,INPUT);
  pinMode(BUZZER,OUTPUT);
}

 

void loop() {
  digitalWrite(TRIG,HIGH); // 10마이크로초 펄스 전송
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW); 

  us = pulseIn(ECHO,HIGH,50000); // 반환값 불러오기
  cm = us/58;
  int buzzercm = cm*4; // 버저용 변수

  // 시리얼모니터, 버저 출력
  tone(BUZZER, buzzercm);
  Serial.print("cm : ");
  Serial.print(cm);
  Serial.print("\n");
  delay(60);
  noTone(buzzercm); // 음소거
}