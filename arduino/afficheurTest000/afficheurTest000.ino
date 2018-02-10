#include "LiquidCrystal.h" //ajout de la librairie
 
//Vérifier les broches !
//LiquidCrystal lcd(11,10,9,8,7,6,5,4,3,2); //liaison 8 bits de données
LiquidCrystal lcd(11,10,5,4,3,2); //liaison 4 bits de données
//LiquidCrystal lcd(7, 12, 5, 4, 8, 2); //liaison 4 bits de donnÃ©es
 
void setup()
{
  analogWrite(6                                                         , 70); 
   lcd.begin(16,2); //utilisation d'un écran 16 colonnes et 2 lignes
 //  lcd.write("5!"); //petit test pour vérifier que tout marche
     lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("LA FOUINE");
    lcd.setCursor(0, 1);
    lcd.print("LA FOUINE");
}
 
void loop() {}
