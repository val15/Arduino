
/*
** Test of R06A RF decoder e/w SC2272-T4
**
** This example uses a SainSmart I2C LCD2004 adapter for HD44780 LCD screens
**
** LCD2004 Address pins 0,1 & 2 are all permenantly tied high so the address
** is fixed at 0x27
**
** Written for and tested with Arduino 1.0
** This example uses F Malpartida's NewLiquidCrystal library. Obtain from:
** https://bitbucket.org/fmalpartida/new-liquidcrystal
**
** Edward Comer
** LICENSE: GNU General Public License, version 3 (GPL-3.0)
**
** NOTE: Tested on Arduino NANO whose I2C pins are A4==SDA, A5==SCL
**       INT0 is on D2
** Wiring for Nano: A4->SDA, A5->SCL
*/
#include <Wire.h>
 
// These pins are on the PCF8574 I/O expander for I2C-bus, not the nano
/*#define I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7*/
 /*
#define  LED_OFF  0
#define  LED_ON  1
 */
#define PIN_D2_INT      0
 
// R06A defines - wired to Digital Arduino pins
// Wire the R06A per this assignment
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

int const tailletableau = 1000;//pour la lecture de la voie serie
String strRecu;
char mot[tailletableau]; //le mot lu sur la voie série



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

  
  Serial.begin(9600);
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
                Serial.println("donner reçu");
                if(r06a_0)
                {
                 // Serial.println("r06a_0=A");
                  //digitalWrite(rl1, !digitalRead(rl1));  // Toggle LED on pin 13
                    //toutAllumer(); 
                    Serial.println("a");
                    allumageAuto=false;
                     lumiereAllumE=!false;
                    
                }
               if(r06a_1)
               {
                  //Serial.println("r06a_1=B");   
                  //toutEtindre();
                  Serial.println("b");
               }
               if(r06a_2)
               {
                 // Serial.println("r06a_2=C");
                  priseActivE=!priseActivE;
                //  Serial.println("p");
                  
                  
               }
              if(r06a_3)
              {
                  lumiereAllumE=!lumiereAllumE;
              //    Serial.println("l");
               }  
        }

        
          digitalWrite(rl3, priseActivE);
        digitalWrite(rl4, lumiereAllumE);

        
        capterLumiere();

    if (Serial.available())
    {
      lireVoieSerie();
    }
}

void lireVoieSerie()
{
    int i = 0; //variable locale pour l'incrémentation des données du tableau
  while (Serial.available() > 0 && i <= tailletableau - 1)
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


  strRecu = mot;
 //  Serial.println(strRecu);

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

