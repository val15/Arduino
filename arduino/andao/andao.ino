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

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);


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
 //   Serial.println("HMC5883 Magnetometer Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!mag.begin())
  {
    /* There was a problem detecting the HMC5883 ... check your connections */
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while(1);
  }
  
  /* Display some basic information on this sensor */
 // displaySensorDetails();

  
  
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
    sensors_event_t event; 
  mag.getEvent(&event);
 
  /* Display the results (magnetic vector values are in micro-Tesla (uT)) */
  Serial.print("X: "); Serial.print(event.magnetic.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.magnetic.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.magnetic.z); Serial.print("  ");Serial.println("uT");

  // Hold the module so that Z is pointing 'up' and you can measure the heading with x&y
  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  float heading = atan2(event.magnetic.y, event.magnetic.x);
  
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: -13* 2' W, which is ~13 Degrees, or (which we need) 0.22 radians
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = 0.22;
  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
    
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
   
  // Convert radians to degrees for readability.
  float headingDegrees = heading * 180/M_PI; 
  
  Serial.print("Heading (degrees): "); Serial.println(headingDegrees);
}


void displaySensorDetails(void)
{
  sensor_t sensor;
  mag.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" uT");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" uT");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" uT");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}




