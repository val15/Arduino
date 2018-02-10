#include <Servo.h>
 
int angle=90;
Servo monServo;
int valeurDentrR;
int entreControleVitesse=A0;
 
void setup()
{
  Serial.begin(9600);
   // monServo.attach(2);
    monServo.attach(2, 1000, 2000);
    monServo.write(angle);
    
}
 
void loop()
{
   /*   valeurDentrR = analogRead(entreControleVitesse);
    //angle=valeurDentrR*180./1023;
    //ou
    angle=map(valeurDentrR, 0, 1023, 0, 180);
  
  
    monServo.write(angle);*/
    
   /* c=c+10;
    if(c>=90)
      c=0;
      
    delay(500);*/

    /*
    Serial.println(angle);
    delay(15);*/
}
