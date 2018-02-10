#include <Servo.h>
 
int angleH=90;
Servo monServo;
int valeurDentrR;
int entreControleVitesse=A0;




int const tailletableau = 1000;
char chainneRecus[tailletableau];
String strRecu;
char mot[tailletableau]; //le mot lu sur la voie série



void setup() 
{
  // put your setup code here, to run once:
  
    Serial.begin(9600);
   // monServo.attach(2);
    monServo.attach(8, 500, 2500);
    monServo.write(90);
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
    if (Serial.available())
    {
      //alors on va lire le contenu de la réception
      lireVoieSerie();

    }

   // servo_1.write(angleH);
   // servo_2.write(angleV);
   monServo.write(angleH);
   

    

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
  if (strRecu.compareTo("check") == 0)
  {
    Serial.println("connection reussit");
  }

  String type = strRecu.substring(0, strRecu.indexOf("="));
 /* if (type.compareTo("v") == 0)
  {  
    String angle = strRecu.substring(strRecu.indexOf("=") + 1, strRecu.length());
    //angleV=anglev.toInt();
    int a=angle.toInt();
    if(a >=60 && a<=120)
      servo_V.write(a);//70-110
  }*/
  if (type.compareTo("h") == 0)
  {  
    String angle = strRecu.substring(strRecu.indexOf("=") + 1, strRecu.length());
    //angleV=anglev.toInt();
     int a=angle.toInt();
    if(a >=0 && a<=180)
      angleH=a;
   // servo_2.write(angle.toInt());//20-160
  }

  
}
