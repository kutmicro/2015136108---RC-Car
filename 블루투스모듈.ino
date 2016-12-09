/*#include <SoftwareSerial.h>

void setup()  
{  
  Serial.begin(9600);
  Serial3.begin(9600);
}
void loop()
{  
  if(Serial3.available())
    Serial.write(Serial3.read());
  
  if(Serial.available())
    Serial3.write(Serial.read());  
}*/




#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출

String myString=""; //받는 문자열
 
void setup() {
  Serial.begin(9600);   //시리얼모니터 
  Serial3.begin(9600); //블루투스 시리얼 개방
 
}
 
void loop() {
  while(Serial3.available())  //mySerial에 전송된 값이 있으면
  {
    char myChar = (char)Serial3.read();  //mySerial int 값을 char 형식으로 변환
    Serial3+=myChar;   //수신되는 문자를 myString에 모두 붙임 (1바이트씩 전송되는 것을 연결)
    delay(5);           //수신 문자열 끊김 방지
  }
  if(!myString.equals(""))  //myString 값이 있다면
  {
    myString="";  //myString 변수값 초기화
  }
}

