int etat2,etat3,c,temp;
boolean permissionAllumerSuivant,permissionEtindrePrecedent;
void setup()
{
    //on met le bouton en entrée
    pinMode(2, INPUT);
    //on active la résistance de pull­up en mettant la broche à l'état haut (mais cela reste toujou
    //digitalWrite(2, HIGH);
    pinMode(3, INPUT);
    //on active la résistance de pull­up en mettant la broche à l'état haut (mais cela reste toujou
   // digitalWrite(3, HIGH);
    
    pinMode(10, OUTPUT);
    digitalWrite(10,HIGH);
    pinMode(11, OUTPUT);
    digitalWrite(11,HIGH);
    pinMode(12, OUTPUT);
    digitalWrite(12,HIGH);
    pinMode(13, OUTPUT);
    digitalWrite(13,HIGH);
    c=9;
    temp=500;
    permissionAllumerSuivant=true;
    permissionEtindrePrecedent=true;
}
 
void loop()
{
    //votre programme
    
        etat2 = digitalRead(2); //Rappel : bouton = 2
        etat3 = digitalRead(3);
 
      if(etat2 == 0)
      {
        actionAppuiSur(2);
      }
      else
      {
        relacher(2);
      }
        
     if(etat3 == 0)
     {
       actionAppuiSur(3);
     }
     else
     {
       relacher(3);
     }   
  
}

void actionAppuiSur(int numeroBouton)
{
  
   
    if(numeroBouton==2)
    {
       if(permissionAllumerSuivant)
        {
          if(c<=13)
          {
              c++;
              allumer(c);
             
          }
          permissionAllumerSuivant=false;
        }
    }
          
    
    if(numeroBouton==3)
    {
       if(permissionEtindrePrecedent)
        {
          if(c>=10)
          {
              
              etindre(c); 
              c--;
          }
          permissionEtindrePrecedent=false;
        }
    }
  
  
  
}

void relacher(int numeroBouton)
{
  if(numeroBouton==2)
  {
    permissionAllumerSuivant=true;
  }
  if(numeroBouton==3)
  {
    permissionEtindrePrecedent=true;
  }
  //c=9;
}




void allumer(int nomeroPort)
{
  digitalWrite(nomeroPort,0);
}

void etindre(int nomeroPort)
{
  digitalWrite(nomeroPort,1);
}

