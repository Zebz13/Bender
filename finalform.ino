#include <Servo.h>

#define manual 11
#define feedback 4

#define thumb A0
#define index A1
#define middle A2
#define ring A3
#define pinky A4

Servo servo_thumb;
Servo servo_index;
Servo servo_middle;
Servo servo_ring;
Servo servo_pinky;
//#define thumbO 3
//#define indexO 5
//#define middleO 6
//#define ringO 9
//#define pinkyO 10

void setup()
{
  // put your setup code here, to run once:
  pinMode(thumb,INPUT);
  pinMode(index,INPUT);
  pinMode(middle,INPUT);
  pinMode(ring,INPUT);
  pinMode(pinky,INPUT);

  pinMode(manual,INPUT);
  pinMode(feedback,OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
  int a,b,c,d,e = read();
  int ret[5];
  int zero[5]={0,0,0,0,0};
  int master=digitalRead(manual);
  atch();
  logic(a,b,c,d,e,ret);
  if(master==1)
  {
    rotate(zero);
    digitalWrite(feedback,0);
  }
  else if(a+b+c+d+e>50)
    rotate(ret);
  else
    digitalWrite(feedback,0);
  detch();
  
}

int read()
{
  return analogRead(thumb),analogRead(index),analogRead(middle),analogRead(ring),analogRead(pinky);
}

void atch()
{
  servo_thumb.attach(3);
  servo_index.attach(5);
  servo_middle.attach(6);
  servo_ring.attach(9);
  servo_pinky.attach(10);
  delay(10);
}

void detch()
{
  servo_thumb.detach();
  servo_index.detach();
  servo_middle.detach();
  servo_ring.detach();
  servo_pinky.detach();
  delay(10);
}

void rotate(int a[])
{
  servo_thumb.write(a[0]);
  servo_index.write(a[1]);
  servo_middle.write(a[2]);
  servo_ring.write(a[3]);
  servo_pinky.write(a[4]);
}

int logic(int a, int b, int c, int d, int e,int ret[])
{
  int arr[5]={a,b,c,d,e};
  int out[5];
  for(int i=0;i<5;i++)
  {
    out[i]=map(arr[i],10,1000,10,175);
    if(out[i]>10 && out[i]<120)
      ret[i]=out[i];
      
    else if(out[i]>120)
      ret[i]=120;
  }
  digitalWrite(feedback,1);
  return ret;
}
