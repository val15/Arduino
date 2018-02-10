//définition de la broche 2 de la carte en tant que variable
int durree=100;
 int i=2;
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
  if(i==14)
  {
    i=10;
  }
  allumerTempo(i,durree);
  i++;
}


void allumerTempo(int numero,int temp)
{
 // int difTemp=0;
  

  
  digitalWrite(numero, LOW);
  delay(temp);
  digitalWrite(numero, HIGH);
}

