int etat2;
boolean permissionAllumerSuivant,permissionEtindrePrecedent;
void setup()
{
    //on met le bouton en entrÃ©e
    pinMode(2, INPUT);
    
    
    for(int i=10;i<=12;i++)
    {
      pinMode(i, OUTPUT);
      digitalWrite(i, 1);
    }
}
 
void loop()
{
    //votre programme
        etat2 = digitalRead(2); //Rappel : bouton = 2);
 
      if(etat2)
      {
        digitalWrite(10, 0);
        digitalWrite(11, 1);
        digitalWrite(12, 0);
        delay(250);
        digitalWrite(10, 1);
        digitalWrite(11, 0);
        delay(250);
        
      }
      else
      {
        /**/
         digitalWrite(10, 1);
        digitalWrite(11, 1);
        digitalWrite(12, 0);
      } 
}



