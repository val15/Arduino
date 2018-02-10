#include <AFMotor.h>
#include <Servo.h>
#define SERVO1_PWM 9
#define SERVO2_PWM 10

Servo servo_1;
Servo servo_2;



AF_DCMotor motor1(4); // Créer le moteur #2, PWM à 64KHz
AF_DCMotor motor2(3);
AF_DCMotor motor3(1);
AF_DCMotor motor4(2);
int Vitesse=200;
int avance=0;
char carlu = 0;
int cardispo = 0;



int angleCam=0;
bool faireMonTCam=false;
bool faireDescCam=false;


//pour capter les tace au sol
/*int capteurG=A9;
int capteurM=A8;
int capteurD=A10;

int capteur3=A11;
int capteur2=A12;
int capteur1=A13;
int capteur0=A14;//0 le plus à gauche

int ledCapteurG=25;
int ledCapteurM=27;
int ledCapteurD=29;
*/
int vlimit=800;



bool avanC=false;
//variable de commande


//utilisation de la detection par front
bool noirDetecTM=false;
bool etatAvantM=false;

bool noirDetecTG=false;
bool etatAvantG=false;

bool noirDetecTD=false;
bool etatAvantD=false;




//pour la localisation
#include <Wire.h>   //Librairie Wire pour la communication I2C
#define HMC5803L_Address 0x1E  //Adresse I2C du module

#define X 3  //Adresses de registres pour les données X Y et Z
#define Y 7
#define Z 5
double Xmagnetic;
double Ymagnetic;
double Zmagnetic;
double Module_magnetic;
double angle;

/*
int const tailletableau=1000;
String strRecu;
char mot[tailletableau]; //le mot lu sur la voie série
*/
void setup() 
{
  Serial.begin(9600);           // Initialiser la communication série à 9600 bauds
  //Serial.println("Test Moteur!");
  
  motor1.setSpeed(Vitesse+15);     // Mettre la vitesse à 200 (max 255)
   motor2.setSpeed(Vitesse+15);
  motor3.setSpeed(Vitesse); 
  motor4.setSpeed(Vitesse+15);



  servo_1.attach(SERVO1_PWM);//attachent du servor à la broche 9
  servo_2.attach(SERVO2_PWM);//attachent du servor à la broche 9
  
  //delay(5000);
 // servo_2.write(180);
  
//  avancer();


  //pour capter les traces au sol
/* pinMode(ledCapteurM, OUTPUT);
  pinMode(ledCapteurD, OUTPUT);
  pinMode(ledCapteurG, OUTPUT);
  digitalWrite(ledCapteurG,0);
  digitalWrite(ledCapteurD,0);
  digitalWrite(ledCapteurG,0);
*/

  //pour la localisation
    Wire.begin();         //Initialisation de la livrairie Wire
    Init_HMC5803L();    //Initialiser le module boussole

  
  
}

void loop() 
{
 /* servo_1.write(0);
  //lireLigneAuSol();
  delay(1000);
  servo_2.write(90);
 delay(1000); 
   servo_1.write(90);
  //lireLigneAuSol();
  delay(1000);
  servo_2.write(0);
 delay(1000);
*/
  /*
  if(faireDescCam)
  {
      descendreCamera();
  }
  if(faireMonTCam)
  {
    monterCamera();
  }

*/

  //teste de la detection par front
   /*   if((noirDetecTM!=etatAvantM) && noirDetecTM==true)
      {
        avancer();
        
        noirDetecTD=false;
        noirDetecTG=false;
      }
      etatAvantM=noirDetecTM;

      if((noirDetecTG!=etatAvantG) && noirDetecTG==true)
      {
        arreter();
        gauche();
        
        noirDetecTM=false;
                noirDetecTD=false;
      }
      etatAvantG=noirDetecTG;

      if((noirDetecTD!=etatAvantD) && noirDetecTD==true)
      {
        arreter();
        droite();
        
        
        noirDetecTM=false;
                noirDetecTG=false;
      }
      etatAvantD=noirDetecTD;
*/
      
      

  
}


void lireLigneAuSol()
{
  /* Serial.print( analogRead(capteurG));
  Serial.print("\t");
 Serial.print( analogRead(capteurM));
  Serial.print("\t");
  Serial.print( analogRead(capteurD));
  Serial.print("\t");
  Serial.println();
*/
  
 /* if(capteurD>100)
    Serial.print( analogRead(capteurD-100));
  else
    Serial.print( analogRead(capteurD));*/
  //Serial.println();
  //Serial.println( analogRead(capteurD));

 /*Serial.print( analogRead(capteur0));
  Serial.print("\t");
   Serial.print( analogRead(capteur1));
  Serial.print("\t");
   Serial.print( analogRead(capteur2));
 Serial.print("\t");
    Serial.print( analogRead(capteur3));
  Serial.print("\t");
  Serial.println();*/

   //delay(50);
   /*avancer();
    delay(50);
    arreter();*/
 /* Vitesse=100;
   if(analogRead(capteur0)>600 )
   {
      droite();
   }
   else if(analogRead(capteur3)>600)
   {
      
      gauche();
   }*/



      
    /*  
      if(analogRead(capteurG) >900)
      noirDetecTG=true;
   if(analogRead(capteurD) >900)
      noirDetecTD=true;
    if(analogRead(capteurM) >900)
      noirDetecTM=true;

*/
   
   
     
   
  
  }
    

void serialEvent()
{
  while (Serial.available())
     {
    // Serial.println();

    
      cardispo = Serial.available();
      
    
    
      
        carlu = Serial.read(); //on lit le caractÃ¨re
        
   //     Serial.println(carlu);
        if(carlu=='l')
        {
//          lireLigneAuSol();
        }
        if(carlu=='m')
        {
          arreter();
        }
        
        if(carlu=='a')
        {
          avancer();
        //  Serial.println("avancer");
        }
        if(carlu=='s')
        {
          arreter();
         // Serial.println("arreter");
          localisation();
        }
        if(carlu=='r')
        {
          reculer();
       //   Serial.println("reculer");
        }
         if(carlu=='g')
        {
          gauche();
       //   Serial.println("gauche");
        }
         if(carlu=='d')
        {
          droite();
     //     Serial.println("droite");
        }

      //  gestion du vetesse
      if(carlu=='5')
        {
         Vitesse=255-15;
           setVitesse();
     //     Serial.println("vitesse = 255");
        }
         if(carlu=='4')
        {
         Vitesse=200;
           setVitesse();
        //  Serial.println("vitesse = 200");
        }
         if(carlu=='3')
        {
          Vitesse=150;
           setVitesse();
       //   Serial.println("vitesse = 150");
        }
         if(carlu=='2')
        {
          Vitesse=100;
           setVitesse();
       //   Serial.println("vitesse = 100");
        }
         if(carlu=='1')
        {
           Vitesse=50;
           setVitesse();
     //     Serial.println("vitesse = 50");
        }


        //controle du servo moteur
         if(carlu=='w')
        {
          angleCam=45;
          servo_2.write(angleCam);
        }
        if(carlu=='x')
        {
          angleCam=90+45;
          servo_2.write(angleCam);
        }
        if(carlu=='c')
        {
           angleCam=90;
          servo_2.write(angleCam);
        }

        if(carlu=='v')
        {
          //bougerCamera=true;
          //monterCamera();
         // Serial.println("monter");
            faireMonTCam=true;
           faireDescCam=false;
          
        }
        if(carlu=='b')
        {
         // bougerCamera=true;
          faireDescCam=true;
          faireMonTCam=false;
        }
        if(carlu=='n')
        {
           faireMonTCam=false;
           faireDescCam=false;
        }
        

}

   
}
   


void avancer()
{
  setVitesse();
    motor3.run(BACKWARD);
   motor4.run(BACKWARD); 
   motor1.run(BACKWARD);      // mettre en marche avant (forward)
  motor2.run(BACKWARD);
}


void reculer()
{
  setVitesse();
  motor1.run(FORWARD);      // mettre en marche avant (forward)
   motor4.run(FORWARD);
   motor3.run(FORWARD);
   motor2.run(FORWARD); 
}
void  gauche()
{
  setVitesseVirrage();
   motor1.run(FORWARD);      // mettre en marche avant (forward)
   motor3.run(FORWARD);
   motor4.run(BACKWARD);
   motor2.run(BACKWARD); 
}

void  droite()
{
  setVitesseVirrage();
    motor1.run(BACKWARD);      // mettre en marche avant (forward)
   motor3.run(BACKWARD);
   motor4.run(FORWARD);
   motor2.run(FORWARD); 
}

void arreter()
{
 

   motor1.run(RELEASE);  
    motor2.run(RELEASE);  
     motor3.run(RELEASE);  
      motor4.run(RELEASE);  
}

void setVitesse()
{
    
  motor1.setSpeed(Vitesse+15);     // Mettre la vitesse à 200 (max 255)
   motor2.setSpeed(Vitesse+15);
  motor3.setSpeed(Vitesse); 
  motor4.setSpeed(Vitesse+15);
}

void setVitesseVirrage()
{
    motor1.setSpeed(255);     // Mettre la vitesse à 200 (max 255)
   motor2.setSpeed(255);
  motor3.setSpeed(255); 
  motor4.setSpeed(255);
 /* motor1.setSpeed(100);     // Mettre la vitesse à 200 (max 255)
   motor2.setSpeed(100);
  motor3.setSpeed(100); 
  motor4.setSpeed(100);*/
  
}

void monterCamera()
{
   
  
    
    if(millis()%100==0)
    {
      if(angleCam >=45)
      {
        angleCam--;
        servo_2.write(angleCam);
      }
      
    }

}

void descendreCamera()
{
  
    if(millis()%100==0)
    {
      if(angleCam <=135)
      {
        angleCam++;
        servo_2.write(angleCam);
      }
      
    }
}

void localisation()
{
    Xmagnetic = HMC5803L_Read(X);  //lecture sur 3 axes et sortie sur le port sériel
  Ymagnetic = HMC5803L_Read(Y);
  Zmagnetic = HMC5803L_Read(Z);
  Serial.print("x=");
  Serial.print (Xmagnetic);
  Serial.print(" y=");
  Serial.print (Ymagnetic);
  Serial.print(" z=");
  Serial.print (Zmagnetic);

   //Module du champ
  Module_magnetic = Xmagnetic * Xmagnetic + Ymagnetic * Ymagnetic + Zmagnetic * Zmagnetic;
  Module_magnetic = sqrt(Module_magnetic);
  Serial.print(" M= ");
  Serial.print(Module_magnetic);
  
  //Calculer l'angle de la boussole à partir de X et Y (à plat)
  angleCam= atan2(Ymagnetic,Xmagnetic) * (180 / 3.14159265); // angle en degres
  if (angleCam<0) {angleCam=angleCam+360;}
  Serial.print("  ");  
  Serial.print("Angle  ");  //en degres
  Serial.println(angleCam);
}

// === Fonction qui initialise le module boussole (à lancer une seule fois)
void Init_HMC5803L(void)
{
  /* Set the module to 8x averaging and 15Hz measurement rate */
  Wire.beginTransmission(HMC5803L_Address);
  Wire.write(0x00);
  Wire.write(0x70);
         
  Wire.write(0x01);
  Wire.write(0xA0);   //Règle un gain de 5
  Wire.endTransmission();
}

// === Fonction qui lit le module boussole (registre d'un des 3 axes, retourne 16 bits)
int HMC5803L_Read(byte Axis)
{
  int Result;
   /* Initiate a single measurement */
  Wire.beginTransmission(HMC5803L_Address);
  Wire.write(0x02);
  Wire.write(0x01);
  Wire.endTransmission();
  delay(6);
  
  /* Move modules the resiger pointer to one of the axis data registers */
  Wire.beginTransmission(HMC5803L_Address);
  Wire.write(Axis);
  Wire.endTransmission();
   
  /* Read the data from registers (there are two 8 bit registers for each axis) */  
  Wire.requestFrom(HMC5803L_Address, 2);
  Result = Wire.read() << 8;
  Result |= Wire.read();

  return Result;
}




