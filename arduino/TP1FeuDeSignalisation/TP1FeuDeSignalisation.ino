
 int i=2;
//fonction d'initialisation de la carte
void setup()
{
    //initialisation de la broche 2 comme Ã©tant une sortie
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    for(int c=2;c<8;c++)
   {
     digitalWrite(c, HIGH);
   }
}
 
//fonction principale, elle se rÃ©pÃ¨te (sâexÃ©cute) Ã  l'infini
void loop()
{
  if(i==4)
  {
    i=2;
  }
  
  allumerEtParallement(2,7,3000);
  allumerEtParallement(3,6,1000);
  allumerEtParallement(4,5,3000);
  

  
    
}


void allumerTempo(int numero,int temp)
{
  digitalWrite(numero, LOW);
  delay(temp);
  digitalWrite(numero, HIGH);
}

void allumerEtParallement(int numeroPremier,int numeroDeusieme,int temp)
{
  digitalWrite(numeroPremier, LOW);
  digitalWrite(numeroDeusieme, LOW);
  delay(temp);
  digitalWrite(numeroPremier, HIGH);
  digitalWrite(numeroDeusieme, HIGH);
}


