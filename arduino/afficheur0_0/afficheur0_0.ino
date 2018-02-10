#include <LiquidCrystal.h>

//#include "LiquidCrystal.h" //ajout de la librairie

//Vérifier les broches !
//LiquidCrystal lcd(11,10,9,8,7,6,5,4,3,2); //liaison 8 bits de données
LiquidCrystal lcd(7,10,5,4,3,2); //liaison 4 bits de données
int contraste=9;
int luminositer=6;

//notre nouveau caractère
    //caractere
    byte smiley[8] = {
    B00000,
    B10001,
    B00000,
    B00000,
    B10001,
    B01110,
    B00000,
    B00000
    };
    byte faC[8] = {
    B00000,
    B10001,
    B00000,
    B00000,
    B01110,
    B10001,
    B00000,
    B00000
    };
    byte ceur[8] = {
    B01010,
    B10101,
    B10001,
    B10001,
    B01010,
    B00100,
    B00000,
    B00000
    };
    
 
void setup()
{
   lcd.begin(16,2); //utilisation d'un écran 16 colonnes et 2 lignes
   //lcd.write("Salut :) val15 !"); //petit test pour vérifier que tout marche
   analogWrite(contraste,50);//0 valeur max
   analogWrite(luminositer,50);//0 valeur min
   /* int nbA = 3;
    int nbB = 5;
    lcd.print(nbA+nbB);
    char cnt=contraste;
    lcd.print(contraste);*/
    lcd.setCursor(0,0);        //place le curseur aux coordonnées (2,1)//texte centré sur la ligne 2
    lcd.write("hello world");
    //lcd.clear(); //efface l'ecran
    /*lcd.cursor();   //affiche le curseur
    lcd.blink();       //et le fait clignoter
    lcd.print("clignotant"); //texte centré sur la ligne 2*/
    //lcd.scrollDisplayLeft(); //on va à gauche !
    //lcd.scrollDisplayRight(); //on va à droite
    
  //afficher le caractere
 lcd.createChar(0, smiley); //apprend le caractère à l'écran LCD
////   // lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.write((uint8_t) 0); //affiche le caractère de l'adresse 0
lcd.setCursor(1,1); 
lcd.createChar(1, ceur);
////    //lcd.begin(16,2);
////    lcd.setCursor(15,1);
////    lcd.write((uint8_t) 1);
//    
   

  
}
 
void loop() 
{
   /* lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(500);*/

    // lcd.write("hello world");

}

