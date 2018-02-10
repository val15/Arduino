int c;
boolean eta,etaAvent,eta3,etaAvent3;
    c=10;
    etaAvent=1;
    etaAvent3=1;
void setup()
{
    //on met le bouton en entrÃ©e
    pinMode(2, INPUT);
       //on active la rÃ©sistance de pullÂ­up en mettant la broche Ã  l'Ã©tat haut (mais cela reste toujou
   // digitalWrite(2, HIGH);
    pinMode(3, INPUT);
       //on active la rÃ©sistance de pullÂ­up en mettant la broche Ã  l'Ã©tat haut (mais cela reste toujou
    //digitalWrite(3, HIGH);
    
    pinMode(10, OUTPUT);
    digitalWrite(10,HIGH);
    pinMode(11, OUTPUT);
    digitalWrite(11,HIGH);
    pinMode(12, OUTPUT);
    digitalWrite(12,HIGH);
    pinMode(13, OUTPUT);
    digitalWrite(13,HIGH);

}
 
void loop()
{
    //votre programme
    
        eta = digitalRead(2); //Rappel : bouton = 2;
        eta3 = digitalRead(3);
 
    if((eta!=etaAvent) && eta==0)
      {
        allumer(c);
        if(c<=13)
        {
          c++;
        } 
      }
      etaAvent=eta;
      
      
      if(eta3!=etaAvent3 && eta3==0 )
      {
         etindre(c);
        if(c>=10)
        {
          c--;
        } 
      }
      etaAvent3=eta3;  
}

void allumer(int n)
{
  digitalWrite(n,0);
}

void etindre(int n)
{
  digitalWrite(n,1);
}




