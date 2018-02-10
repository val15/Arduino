#include <LiquidCrystal.h>

//#include "LiquidCrystal.h" //ajout de la librairie

//Vérifier les broches !
//LiquidCrystal lcd(11,10,9,8,7,6,5,4,3,2); //liaison 8 bits de données
LiquidCrystal lcd(11,10,5,4,3,2); //liaison 4 bits de données
int contraste=9;
int luminositer=6;
int s=0;
int m=0;
int h=0;
 
void setup()
{
   lcd.begin(16,2); //utilisation d'un écran 16 colonnes et 2 lignes
   //lcd.write("Salut :) val15 !"); //petit test pour vérifier que tout marche
   analogWrite(contraste,50);//0 valeur max
   analogWrite(luminositer,50);//0 valeur min
    /*int mavariable = 42;
    lcd.print(mavariable);*/
   /* char message[16] = "";
    sprintf(message,"J'ai 42 ans");
   /*     char message[16] = "";
    int nbA = 3;
    int nbB = 5;
    lcd.print(nbA+nbB);*/
    

}
 
void loop() 
{
  lcd.home();
  lcd.print(h);lcd.print(":" );lcd.print(m);lcd.print(":" );lcd.print(s); 
  if(s==60)
  {
    s=0;
    m++;
  }
  if(m==60)
  {
      m=0;
      h++;
  }
  if(h==24)
  {
    h=0;
  }
  delay(1000);
  s++;
  
}
