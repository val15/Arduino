//dÃ©finition de la broche 2 de la carte en tant que variable
int durree=100;
 int c=10,i=10;
 boolean autorisationMarche;
//fonction d'initialisation de la carte
void setup()
{
  autorisationMarche=false;
    //initialisation de la broche 2 comme Ã©tant une sortie
    //on met le bouton en entrÃ©e
    pinMode(2, INPUT);
    //on active la rÃ©sistance de pullÂ­up en mettant la broche Ã  l'Ã©tat haut (mais cela reste toujou
    digitalWrite(2, HIGH);
    pinMode(3, INPUT);
    //on active la rÃ©sistance de pullÂ­up en mettant la broche Ã  l'Ã©tat haut (mais cela reste toujou
    digitalWrite(3, HIGH);
    
    
    for(i=10;i<=13;i++)
    {
      pinMode(i, OUTPUT);
      digitalWrite(i, 1);
    }
    
    //declaration de l'iterruption
    attachInterrupt(0, stoperOuLancer, FALLING);
    
}

//fonction qui est appeller lor de l'interruption
void stoperOuLancer()
{ 
  autorisationMarche=!autorisationMarche;
}
 
 
//fonction principale, elle se rÃ©pÃ¨te (sâexÃ©cute) Ã  l'infini
void loop()
{
  if(autorisationMarche)
  {
    if(c==14)
    {
      c=10;
    }
    allumerTempo(c,durree);
    c++;
  }
}


void allumerTempo(int numero,int temp)
{
  digitalWrite(numero, LOW);
  delay(temp);
  digitalWrite(numero, HIGH);
}
