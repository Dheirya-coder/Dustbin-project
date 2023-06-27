
int Duration;
int Distance;
#include <Servo.h>
Servo myservo;

void setup() 
{
 pinMode(5,INPUT);
 pinMode(6,OUTPUT);
 Serial.begin(9600);
 myservo.attach(9);
 myservo.write(0);

}

void loop()
{
  digitalWrite(6,LOW);
  delayMicroseconds(2);
  digitalWrite(6,HIGH);
  delayMicroseconds(10);
  digitalWrite(6,LOW);
  Duration = pulseIn(5,HIGH);
  delay(10);
  Distance = Duration*0.034/2;
  Serial.println(Distance);


  if(Distance<20)
  {
    myservo.write(100);
    delay(3000);


    for(int a = 100;a<=0;a--)
    {
      myservo.write(a);
      delay(15);
    }
  }
  else
  {
    myservo.write(0);
  }
}
