//définition de la broche 2 de la carte en tant que variable
int durree=100;
int temps=0;
 int i=10;
//fonction d'initialisation de la carte
void setup()
{
    //initialisation de la broche 2 comme étant une sortie
    for(int c=10;c<14;c++)
    {
      pinMode(c, OUTPUT);
      digitalWrite(c,HIGH);
    }
}
 
//fonction principale, elle se répète (s’exécute) à l'infini
void loop()
{
  //digitalWrite(5, LOW);
  /*if(i>14)//imitalisation
  {
    i=10;
    for(int c=10;c<14;c++)
    {
      digitalWrite(c,HIGH);
    }
    
  }*/
  clignoter(10,200);
  
}

void clignoter(int num,int durree)
{
  
  if(millis() - temps > durree)
  {
    digitalWrite(num,!digitalRead(num));
    temps=millis();
  }
}

