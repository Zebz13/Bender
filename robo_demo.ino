/*demo code for 1 finger with servo without torque control. Need to add pid*/

#include <Servo.h> 
#define piezoinp A0
#define feedbackvib 7 
Servo myservo;

void setup() 
{ 
  pinMode(piezoinp,INPUT);
  pinMode(feedbackvib,OUTPUT);
  myservo.attach(9);
}


void loop() {
  // put your main code here, to run repeatedly:
  int a=analogRead(piezoinp);
  int b=map(a,0,1023,0,180);
  if(a>500)
  {
    digitalWrite(feedbackvib,1);
    myservo.write(b-200);
  }
  else
  {
    digitalWrite(feedbackvib,0);
    myservo.write(b);
  }

}
