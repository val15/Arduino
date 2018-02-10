
#include <AFMotor.h>
#include <Servo.h>
#define SERVO1_PWM 9
#define SERVO2_PWM 10

Servo servo_1;
Servo servo_2;


int const tailletableau = 1000;
char chainneRecus[tailletableau];
String strRecu;
char mot[tailletableau]; //le mot lu sur la voie série
void setup() 
{
    Serial.begin(9600);      
    servo_1.attach(SERVO1_PWM);//attachent du servor à la broche 9
    servo_2.attach(SERVO2_PWM);//attachent du servor à la broche 9
  

}

void loop() 
{
   if (Serial.available())
    {
      //alors on va lire le contenu de la réception
      lireVoieSerie();

    }
}

    void lireVoieSerie(void)
{
  int i = 0; //variable locale pour l'incrémentation des données du tableau

  //on lit les caractères tant qu'il y en a
  //OU si jamais le nombre de caractères lus atteint 19 (limite du tableau stockant le mot ­ 1 ca
  while (Serial.available() > 0 && i <= tailletableau - 1)
  {
    //on enregistre le caractère lu
    mot[i] = Serial.read();
    //laisse un peu de temps entre chaque accès a la mémoire
    delay(10);//tres important
    //on passe à l'indice suivant
    i++;
  }
  //on supprime le caractère '\n' et on le remplace par celui de fin de chaine '\0'
  mot[i] = '\0';


  strRecu = mot;
  // Serial.println(strRecu);
  if (strRecu.compareTo("h90") == 0)
  {
    servo_1.write(90);
  }
  if (strRecu.compareTo("v90") == 0)
  {
    servo_2.write(90);
  }
  if (strRecu.compareTo("h0") == 0)
  {
    servo_1.write(0);
  }
  if (strRecu.compareTo("v0") == 0)
  {
    servo_2.write(0);
  }
}

