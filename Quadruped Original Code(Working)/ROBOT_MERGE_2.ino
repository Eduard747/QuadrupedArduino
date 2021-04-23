#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  0 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  500 // this is the 'maximum' pulse length count (out of 4096)
#include <Ultrasonic.h>

int trig = 10;
int echo = 9;
long dur;
int dis;
int nr;
uint8_t s1 = 1;
uint8_t s2 = 2;
uint8_t s3 = 3;
uint8_t s4 = 4;
uint8_t s5 = 5;
uint8_t s6 = 6;
uint8_t s7 = 7;
uint8_t s8 = 8;
unsigned char Bluetooth_val;       //defining variable val

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  delay(10);
 
     pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
     pwm.setPWM(s5,5,290);//initial
 pwm.setPWM(s1,1,270); //initial
 pwm.setPWM(s6,6,420);//tibia in jos
     pwm.setPWM(s2,2,460);//tibia in jos
       pwm.setPWM(s4,4,410);//tibia in jos
    pwm.setPWM(s8,8,440);//tibia in jos
        pwm.setPWM(s3,3,290);//initiala
    pwm.setPWM(s7,7,290);//initiala
    delay(100);
}
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  pulselength = 1000000/(60*4096);   // 1,000,000 us per second
  pulse *= 100;  // convert to us
  pulse /= pulselength;
  pwm.setPWM(n, 0, pulse); 
}
void cal() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  dur = pulseIn(echo, HIGH);
  dis = dur * 0.034 / 2;
}
void mers()
{ pwm.setPWM(s6,6,520);//se ridica tibia  
 pwm.setPWM(s5,5,320);//in spate
    pwm.setPWM(s2,2,560);//se ridica tibia    
    pwm.setPWM(s1,1,320);//in spate
  delay(60);
  pwm.setPWM(s5,5,230);//in fata
      pwm.setPWM(s1,1,210);//in fata
       delay(60);
      pwm.setPWM(s6,6,410);//tibia in jos
     pwm.setPWM(s2,2,420);//tibia in jos
    delay(60);
    pwm.setPWM(s5,5,280);//initial
    pwm.setPWM(s1,1,290); //initial
    pwm.setPWM(s4,4,525);//tibia se ridica
    pwm.setPWM(s3,3,320); //in spate 
    pwm.setPWM(s8,8,520);//tibia se ridica 
    pwm.setPWM(s7,7,320);//in spate
  delay(60);
      pwm.setPWM(s3,3,250);//in fata
    pwm.setPWM(s7,7,250);// in fata
    delay(60);
   pwm.setPWM(s4,4,410);//tibia in jos
    pwm.setPWM(s8,8,410);//tibia in jos
    delay(60);
    pwm.setPWM(s3,3,280);//initiala
    pwm.setPWM(s7,7,280);//initiala
  delay(60);
}
void stanga()
{
  pwm.setPWM(s6,6,520);//se ridica tibia  
 pwm.setPWM(s5,5,360);//in spate
    pwm.setPWM(s2,2,560);//se ridica tibia    
    pwm.setPWM(s1,1,300);//in spate
  delay(70);
  pwm.setPWM(s5,5,230);//in fata
      pwm.setPWM(s1,1,210);//in fata
       delay(70);
      pwm.setPWM(s6,6,420);//tibia in jos
     pwm.setPWM(s2,2,460);//tibia in jos
    delay(70);
    pwm.setPWM(s5,5,280);//initial
    pwm.setPWM(s1,1,260); //initial
    pwm.setPWM(s4,4,525);//tibia se ridica
    pwm.setPWM(s3,3,360); //in spate 
    pwm.setPWM(s8,8,520);//tibia se ridica 
    pwm.setPWM(s7,7,300);//in spate
  delay(70);
      pwm.setPWM(s3,3,250);//in fata
    pwm.setPWM(s7,7,250);// in fata
    delay(70);
   pwm.setPWM(s4,4,410);//tibia in jos
    pwm.setPWM(s8,8,410);//tibia in jos
    delay(70);
    pwm.setPWM(s3,3,280);//initiala
    pwm.setPWM(s7,7,280);//initiala
  delay(70);
  }
  void dreapta()
  {
      pwm.setPWM(s6,6,520);//se ridica tibia  
 pwm.setPWM(s5,5,300);//in spate
    pwm.setPWM(s2,2,560);//se ridica tibia    
    pwm.setPWM(s1,1,360);//in spate
  delay(70);
  pwm.setPWM(s5,5,230);//in fata
      pwm.setPWM(s1,1,210);//in fata
       delay(70);
      pwm.setPWM(s6,6,420);//tibia in jos
     pwm.setPWM(s2,2,460);//tibia in jos
    delay(70);
    pwm.setPWM(s5,5,280);//initial
    pwm.setPWM(s1,1,260); //initial
    pwm.setPWM(s4,4,525);//tibia se ridica
    pwm.setPWM(s3,3,300); //in spate 
    pwm.setPWM(s8,8,520);//tibia se ridica 
    pwm.setPWM(s7,7,360);//in spate
  delay(70);
      pwm.setPWM(s3,3,250);//in fata
    pwm.setPWM(s7,7,250);// in fata
    delay(70);
   pwm.setPWM(s4,4,410);//tibia in jos
    pwm.setPWM(s8,8,410);//tibia in jos
    delay(70);
    pwm.setPWM(s3,3,280);//initiala
    pwm.setPWM(s7,7,280);//initiala
  delay(70);
  }
  void stationare()
  {
        pwm.setPWM(s5,5,290);//initial
 pwm.setPWM(s1,1,280); //initial
 pwm.setPWM(s6,6,420);//tibia in jos
     pwm.setPWM(s2,2,460);//tibia in jos
       pwm.setPWM(s4,4,410);//tibia in jos
    pwm.setPWM(s8,8,410);//tibia in jos
        pwm.setPWM(s3,3,290);//initiala
    pwm.setPWM(s7,7,290);//initiala
  }
void loop () 
 { 
  if(nr<3)
{
   if(Serial.available())
    {
     Bluetooth_val=Serial.read();  
    switch(Bluetooth_val)
     {
       case 'U':mers(); //UP
       nr=0;
       break;
       case 'L':stanga(); //Left
       nr=0;
       break;
       case 'R':dreapta();  //Right
       nr=0;
       break;   
       case 'D': stationare(); //back
       nr=0;
       break; 
       case 'S':   //stop
       nr++;
       break;
       
     }
    }
} 
    else {  
      cal();
 if(dis>=46)
 {
  mers();
  return;
 }
  if(dis<=45)
  {
    stanga();
    return;
  }
  }
}
