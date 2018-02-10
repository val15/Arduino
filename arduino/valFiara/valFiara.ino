#include <AFMotor.h>



AF_DCMotor motor1(1); // Créer le moteur #2, PWM à 64KHz
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
int vitesse=200;
char carlu = 0;
int cardispo = 0;

int const tailletableau=1000;
String strRecu;
char mot[tailletableau]; //le mot lu sur la voie série

void setup() {
  Serial.begin(9600);           // Initialiser la communication série à 9600 bauds
  //Serial.println("Test Moteur!");
  
  motor1.setSpeed(vitesse);     // Mettre la vitesse à 200 (max 255)
  motor2.setSpeed(vitesse); 
  motor3.setSpeed(vitesse+55); 
  motor4.setSpeed(vitesse); 
  //arreter();
}

void loop() 
{

 /*  motor1.run(FORWARD);      // mettre en marche avant (forward)
   motor2.run(FORWARD);
   motor3.run(FORWARD);
   motor4.run(FORWARD);*/
 /* Serial.print("tick");
  
  motor1.run(FORWARD);      // mettre en marche avant (forward)
   motor2.run(FORWARD);
    motor3.run(FORWARD);
     motor4.run(FORWARD);
  delay(1000);

  Serial.print("tock");
  motor1.run(BACKWARD);  
  motor2.run(BACKWARD);// Dans l'autre sens
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(1000);
  
  Serial.print("tack");
  motor1.run(RELEASE);      // Arrêt
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(1000);*/
 //avancer();
 // gauche();
// motor1.run(FORWARD);
//motor3.run(BACKWARD);
if(Serial.available())
    {
        //alors on va lire le contenu de la réception
        lireVoieSeriMot();
        //on entre dans une variable la valeur retournée par la fonction comparerMot()
       // etat = comparerMot(mot);
    }
 
}


void serialEvent()
{
 /* while (Serial.available())
     {*/
    // Serial.println();
      cardispo = Serial.available();
      
    
    
      
        carlu = Serial.read(); //on lit le caractÃ¨re
        
        Serial.println(carlu);
        if(carlu=='a')
        {
          avancer();
          Serial.println("avancer");
        }
        if(carlu=='s')
        {
          arreter();
          Serial.println("arreter");
        }
        if(carlu=='r')
        {
          reculer();
          Serial.println("reculer");
        }
         if(carlu=='g')
        {
          gauche();
          Serial.println("gauche");
        }
         if(carlu=='d')
        {
          groite();
          Serial.println("droite");
        }

        
}

void lireVoieSeriMot()
{
   
        int i=0;
        while(Serial.available() > 0 && i <= tailletableau-1)
        {
            //on enregistre le caractère lu
            mot[i] = Serial.read();
            //laisse un peu de temps entre chaque accès a la mémoire
            delay(10);
            //on passe à l'indice suivant
            i++;
        }
    //on supprime le caractère '\n' et on le remplace par celui de fin de chaine '\0'
        mot[i] = '\0';
    
    
    strRecu=mot;
    Serial.println(strRecu);

    String type=strRecu.substring(0,strRecu.indexOf("="));
    if(type.compareTo("v")==0)
    {
      String vitesse=strRecu.substring(strRecu.indexOf("=")+1,strRecu.length());
      Serial.println("vitesse = "+vitesse);
    }
        
       /* cardispo = Serial.available(); //on relit le nombre de caractÃ¨res dispo
        Serial.println(mot);*/

   
}
     


void reculer()
{
   motor1.run(FORWARD);      // mettre en marche avant (forward)
   motor4.run(FORWARD);
   motor3.run(FORWARD);
   motor2.run(FORWARD); 
}


void avancer()
{
   
  motor3.run(BACKWARD);
   motor4.run(BACKWARD); 
   motor1.run(BACKWARD);      // mettre en marche avant (forward)
  motor2.run(BACKWARD);
}

void gauche()
{
    motor1.run(BACKWARD);      // mettre en marche avant (forward)
   motor4.run(BACKWARD);
   motor3.run(FORWARD);
   motor2.run(FORWARD); 
}

void  groite()
{
    motor1.run(FORWARD);      // mettre en marche avant (forward)
   motor4.run(FORWARD);
   motor3.run(BACKWARD);
   motor2.run(BACKWARD); 
}

void arreter()
{
   motor1.run(RELEASE);  
    motor2.run(RELEASE);  
     motor3.run(RELEASE);  
      motor4.run(RELEASE);  
  
}

