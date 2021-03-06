// 수정전
#include <SoftwareSerial.h>
#include <AFMotor.h>


//Motor
AF_DCMotor Lfmotor(2);
AF_DCMotor Rfmotor(1);
AF_DCMotor Lbmotor(3);
AF_DCMotor Rbmotor(4);


void setup()
{
  Serial3.begin(9600);
 //Motor 
  Lfmotor.setSpeed(200);
  Lfmotor.run(RELEASE);
  Lbmotor.setSpeed(200);
  Lbmotor.run(RELEASE);
  
  Rfmotor.setSpeed(200);
  Rfmotor.run(RELEASE);
  Rbmotor.setSpeed(200);
  Rbmotor.run(RELEASE);
  
}

void loop()
{
  
        
  if (Serial3.available()) 
  {
    char c = Serial3.read();
   

    //회전 방향 제어
    switch (c)
    {
      case 'a': // left
        Lfmotor.run(RELEASE);
        Rfmotor.run(FORWARD);
        Lbmotor.run(RELEASE);
        Rbmotor.run(FORWARD);
        break
      case 'b': // forword
        Lfmotor.run(FORWARD);
        Rfmotor.run(FORWARD);
        Lbmotor.run(FORWARD);
        Rbmotor.run(FORWARD);
        break;
      case 'c': //right
        Lfmotor.run(FORWARD);
        Rfmotor.run(RELEASE);
        Lbmotor.run(FORWARD);
        Rbmotor.run(RELEASE);
        break;
        
      case 'e':// back
        Lfmotor.run(BACKWARD);
        Rfmotor.run(BACKWARD);
        Lbmotor.run(BACKWARD);
        Rbmotor.run(BACKWARD);
        break;
      case 'g': // stop
        Lfmotor.run(RELEASE);
        Rfmotor.run(RELEASE);
        Lbmotor.run(RELEASE);
        Rbmotor.run(RELEASE);
      case '\r':  break;
      case '\n':  break;
//      default:  //이도저도 아니면
//        Lmotor.run(RELEASE);
//        Rmotor.run(RELEASE);
//        break;
    }
  }
}
