//dÃ©finition de la broche 2 de la carte en tant que variable
int durree=50;
 int i=0,j=0;
 int temps=0;
 boolean etat_led;
 int valeurLue;
 
const int tabLED[6] = {3,5,6,9,10,11};
//fonction d'initialisation de la carte
void setup()
{
    //initialisation de la broche 2 comme Ã©tant une sortie
    
    for(int c=0;c<7;c++)
    {
      pinMode(tabLED[c], OUTPUT);
      
     
    }
    toutEtindre();
    //v=255;
   // i=5;
   // p=0;
    //i=1;
    
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
  if(j==6)
  {
    j=0;
  }
   //v=42;
   //i=0;
    
  allumerProgress(j);  
    
  delay(durree);
  j++;
  //p=0;
  //toutEtindre();
  
  
  
}

void allumerProgress(int i)
{
  int v=255;
  for(int p=0;p<7;p++)
    {
     /* if(i==7)
      {
        i=0;
      }
      else
      {
        i++;
      }*/
      analogWrite(tabLED[i],v);
      v=v-24;
      if(i==6)
      {
        i=0;
      }
      else
      {
        i++;
      }
    }

  
}

void toutEtindre()
{
  for(int c=0;c<=7;c++)
    {
      digitalWrite(tabLED[c],1);
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



