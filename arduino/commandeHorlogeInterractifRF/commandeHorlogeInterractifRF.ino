



//pour le recepteur RF
#include <Wire.h>
#define PIN_D2_INT      0
#define R06A_VT 2    // used for INT0
#define R06A_D3 3
#define R06A_D2 4
#define R06A_D1 5
#define R06A_D0 6
int r06a_0, r06a_1, r06a_2, r06a_3 = 0; // storage for data states
int dirty = 0;   

//pour la communiqtion avec le port série
int const tailletableau = 1000;
char chainneRecus[tailletableau];
String strRecu;
char mot[tailletableau]; //le mot lu sur la voie série

 
//déclaration des sortie en tant que sortie
int rl3=11;
int rl4=12;

//pour le capteur de lumiére
const int capteurLumiR = 0;
int valeurLumieire;


//pour le piezo
const int piezo = 13;
boolean autorisationBuper = true;
boolean alarme = false;
boolean activerCapteurBip = false;


//uatres varibles
bool allumageAuto;
bool priseActivE=!false;
bool lumiereAllumE=!false;

void pinD2ISR()
{
    // Provide a visual clue of the interrupt
  //  digitalWrite(13, !digitalRead(13));  // Toggle LED on pin 13
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
  
  tone(piezo, 600, 500);

}

void loop() 
{
  if(dirty)
        {
               
                if(r06a_0)//"a" sur le telecommande
                {
               
                    Serial.println("a");
                    allumageAuto=false;
                     lumiereAllumE=!false;
                    
                }
               if(r06a_1)//"b" sur le telecommand
               {
                  Serial.println("b");
               }
               if(r06a_2)//"c" sur le telecommand
               {
                  Serial.println("c");
                  lumiereAllumE=!lumiereAllumE;
               }
              if(r06a_3)//"d" sur le telecommand
              {
                  Serial.println("d");
                  priseActivE=!priseActivE;
               }  
               dirty = 0;              // clear interrupt occurance flag
        }

        
          digitalWrite(rl4, priseActivE);
        digitalWrite(rl3, lumiereAllumE);

        
        capterLumiere();

  
   if (Serial.available())
    {
      
      lireVoieSerie();

    }
    
    if (alarme)
      biper(1000, 1000);

   


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
    if(strRecu.compareTo("toutEtindre")==0)
      toutEtindre();
      
   
      
        //pour l'alarme et le bip
     if(strRecu.compareTo("bip") == 0 && activerCapteurBip)
     {
       Serial.println("bip");
       tone(piezo, 600, 500); //une bipe
     }
           
     if(strRecu.compareTo("alarm") == 0)
     {
       Serial.println("alarm");
       alarme = true; //une bipe
     }  
     
     
     if(strRecu.compareTo("finAl") == 0)//pour desactiver l'alarm
     {
         Serial.println("finAl");
        alarme = false; //une bipe
     }

     

  
  // Serial.println(strRecu);
  if (strRecu.compareTo("check") == 0)
  {
    Serial.println("connection reussit");
   // tone(piezo, 600, 500);
  }
    
    
   

  
}


void capterLumiere()
{
  valeurLumieire = analogRead(capteurLumiR);
  //Serial.println(valeurLumieire);

 if(valeurLumieire<90 && allumageAuto)
  lumiereAllumE=!true;//car activer par false
  
  
  if(valeurLumieire>20)
    activerCapteurBip = true;
  else
    activerCapteurBip = false;
    
}

void toutEtindre()
{
  priseActivE=!false;
  lumiereAllumE=!false;
}

void toutAllumer()
{
  priseActivE=false;
  lumiereAllumE=false;
}

void biper(int fr, int intervale) //fait biber le piezo et clignoter la led
{
 
  if (millis() % intervale == 0)
  {
    if (autorisationBuper)
    {
      tone(piezo, fr, intervale);
    }
  }
}


