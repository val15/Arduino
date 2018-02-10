//dÃ©finition de la broche 2 de la carte en tant que variable
int durree=50;
 int i=7;
 int temps=0;
 boolean etat_led;
 int valeurLue;
//fonction d'initialisation de la carte
void setup()
{
    //initialisation de la broche 2 comme Ã©tant une sortie
    for(int c=7;c<=12;c++)
    {
      pinMode(c, OUTPUT);
      digitalWrite(c,1);
    }
    
    
}
 
//fonction principale, elle se rÃ©pÃ¨te (sâexÃ©cute) Ã  l'infini
void loop()
{
  /*digitalWrite(5, LOW);
  if(i==14)
  {
    i=10;
  }
  allumerTempo(i,durree);
  i++;*/
  valeurLue = analogRead(0);
  durree=1024-valeurLue;
  if(i==13)
    i=7;
 /* if(millis() - temps < durree)
  {
            //on inverse l'état de la LED
            //etat_led = !etat_led;
            digitalWrite(i,0); //on allume ou éteint
            
  }
  else
  {
    digitalWrite(i,1);
    temps = millis(); //on stocke la nouvelle heure
    i++;
  }*/
  //digitalWrite(7,0);
  digitalWrite(i,0);
  delay(durree);
  i++;
  toutEtindre();
  
  
  
}

void toutEtindre()
{
  for(int c=7;c<=12;c++)
    {
      digitalWrite(c,1);
    }
}

void allumerTempo(int num,int durree)
{
  if(millis() - temps > durree)
  {
            //on inverse l'état de la LED
            digitalWrite(num,!num); //on allume ou éteint
            temps = millis(); //on stocke la nouvelle heure
  }
}



