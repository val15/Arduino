#include <Servo.h>
//servo
int angleH=90;
Servo monServo;
int valeurDentrR;
int entreControleVitesse=A0;

int const tailletableau = 1000;
char chainneRecus[tailletableau];
String strRecu;
char mot[tailletableau]; //le mot lu sur la voie série


//commande RF

#include <Wire.h>
#define PIN_D2_INT      0
 
#define R06A_VT 2    // used for INT0
#define R06A_D3 3
#define R06A_D2 4
#define R06A_D1 5
#define R06A_D0 6
 
int r06a_0, r06a_1, r06a_2, r06a_3 = 0; // storage for data states
int dirty = 0;   


//definition des rortie
int rl1=9;
int rl2=10;
int rl3=11;
int rl4=12;

const int capteurLumiR = 0;
int valeurLumieire;
bool allumageAuto;





bool priseActivE=!false;
bool lumiereAllumE=!false;

// interrupt has occurred flag
 
// Interrupt Service Routine attached to INT0 vector
void pinD2ISR()
{
    // Provide a visual clue of the interrupt
    digitalWrite(13, !digitalRead(13));  // Toggle LED on pin 13
    // Grab the data states
    r06a_0 = digitalRead(R06A_D0);      // Grab data for later consumption in loop()
    r06a_1 = digitalRead(R06A_D1);
    r06a_2 = digitalRead(R06A_D2);
    r06a_3 = digitalRead(R06A_D3);
    dirty = 1;                          // flag interrupt occurance
}
 


void setup() 
{
  // put your setup code here, to run once:
   Serial.begin(9600);
 
    monServo.attach(8, 500, 2500);
    monServo.write(90);
    valeurLumieire = analogRead(capteurLumiR);//o-1024
  allumageAuto=false;

  attachInterrupt(PIN_D2_INT, pinD2ISR, RISING);        // Set D2 interrupt
 
  // setup the R06A decoder connections
  pinMode(R06A_D0, INPUT);
  pinMode(R06A_D1, INPUT);
  pinMode(R06A_D2, INPUT);
  pinMode(R06A_D3, INPUT);

  //definition des relai en tant que sortie!!
  pinMode(rl3, OUTPUT);
  pinMode(rl4, OUTPUT);
  digitalWrite(rl3, 1);
  digitalWrite(rl4, 1);

}

void loop() 
{
  if(dirty)
        {
                dirty = 0;              // clear interrupt occurance flag
             /*   lcd.setCursor (15,3);     // go to LCD col 15 of line 4
                lcd.print(r06a_0 ? "HIGH": "LOW ");
                lcd.setCursor (10,3);     // go to LCD col 10 of line 4
                lcd.print(r06a_1 ? "HIGH": "LOW ");
                lcd.setCursor (5,3);      // go to LCD col 5 of line 4
                lcd.print(r06a_2 ? "HIGH": "LOW ");
                lcd.setCursor (0,3);      // go to LCD col 0 of line 4
                lcd.print(r06a_3 ? "HIGH": "LOW ");*/
               // Serial.println("donner reçu");
                if(r06a_0)//"a" sur le telecommande
                {
                 // Serial.println("r06a_0=A");
                  //digitalWrite(rl1, !digitalRead(rl1));  // Toggle LED on pin 13
                    //toutAllumer(); 
                    //Serial.println("a");
                    allumageAuto=false;
                     lumiereAllumE=!false;
                    
                }
               if(r06a_1)//"b" sur le telecommand
               {
                  //Serial.println("r06a_1=B");   
                  //toutEtindre();
                //  Serial.println("b");
               }
               if(r06a_2)//"c" sur le telecommand
               {
                 // Serial.println("r06a_2=C");
                  
                  lumiereAllumE=!lumiereAllumE;
                //  Serial.println("p");
                  
                  
               }
              if(r06a_3)//"d" sur le telecommand
              {
                  priseActivE=!priseActivE;
              //    Serial.println("l");
               }  
        }

        
          digitalWrite(rl4, priseActivE);
        digitalWrite(rl3, lumiereAllumE);

        
        capterLumiere();

  
   if (Serial.available())
    {
      
      lireVoieSerie();

    }

   
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


   if(strRecu.compareTo("activerAllumAuto")==0)
    allumageAuto=true;

   if(strRecu.compareTo("desactiverAllumAuto")==0)
    allumageAuto=false;

    if(strRecu.compareTo("desactiverPrise")==0)
      priseActivE=!false;//car actiV par false
   if(strRecu.compareTo("activerPrise")==0)
      priseActivE=!true;

    if(strRecu.compareTo("eteindreLumiere")==0)
      lumiereAllumE=!false;
    if(strRecu.compareTo("allumerLumiere")==0)
      lumiereAllumE=!true;

  
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


void capterLumiere()
{
  valeurLumieire = analogRead(capteurLumiR);
  //Serial.println(valeurLumieire);

 if(valeurLumieire<90 && allumageAuto)
  lumiereAllumE=!true;//car activer par false
}

void toutEtindre()
{
  digitalWrite(rl3, 1);
  digitalWrite(rl4, 1); 
}

void toutAllumer()
{
  digitalWrite(rl3, 0);
  digitalWrite(rl4, 0); 
}


