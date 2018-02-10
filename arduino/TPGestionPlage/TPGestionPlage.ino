int const ledRouge =12;
int const ledOrange =11;
int const ledVert =10;
int bouttonAlerte = 3;
int bouttonAnnulerAlerte = 2;
int temp=0;
int etabouttonAlerte,etabouttonAnnulerAlerte,eta;
int d=0;
int c=0;
boolean r;
char niveau;
char niveauAvent;
char chainneRecus[20];
int i=0,l,b;
String strRecu;

void setup()
{
    //on dÃ©marre la liaison en la rÃ©glant Ã  une vitesse de 9600 bits par seconde.
    Serial.begin(9600);

    niveau='v';
    
 /* Serial.println(toMinuscule('Z'));
  Serial.println(toMaguscule('x'));*/
  etabouttonAlerte=1;
  etabouttonAnnulerAlerte=1;
  r=0;
   pinMode(2, INPUT);
    pinMode(3, INPUT);
    
    for(int c=10;c<13;c++)
    {
      pinMode(c, OUTPUT);
      digitalWrite(c,HIGH);
    }
    c=0;
    
   /* attachInterrupt(bouttonAlerte, lancerAlerte, FALLING);
    attachInterrupt(bouttonAnnulerAlerte, stoperAlerte, FALLING); */
}


void loop()
{
    //votre programme
    
   // if(L==
    //char carlu = 0; //variable contenant le caractÃ¨re Ã  lire
    int cardispo = 0; //variable contenant le nombre de caractÃ¨re disponibles dans le buffer

    
    cardispo = Serial.available();
    
    while(cardispo > 0) //tant qu'il y a des caractÃ¨res Ã  lire
    {
        chainneRecus[c] = Serial.read(); //on lit le caractÃ¨re
        
        Serial.println(chainneRecus[1]);
        cardispo = Serial.available(); //on relit le nombre de caractÃ¨res dispo
        c++;
        
    }
    
    cardispo = Serial.available();
    if(Serial.read()==-1)
    {
        strRecu=chainneRecus;
        strRecu=strRecu.substring(0,c);
        Serial.println(strRecu);
        if(strRecu.compareTo("vague")==0)
        {
          niveau='o';
        }
        
         if(strRecu.compareTo("calme")==0 || strRecu.compareTo("surveillant")==0)
        {
          niveau='v';
        }
        
        if(strRecu.compareTo("meduse")==0  || strRecu.compareTo("tempete")==0 ||  strRecu.compareTo("requin")==0)
        {
          niveau='r';
        }
        
      c=0;
    }
   // allumerLed(ledRouge);
   // clignoter(ledRouge,100);
   //clignoter(ledRouge,100);
   eta = digitalRead(bouttonAlerte);
    if((eta!=etabouttonAlerte) && eta==0)
      {
        b=1;
         niveauAvent=niveau;
         niveau=' ';
      }
      etabouttonAlerte=eta;
      
    eta = digitalRead(bouttonAnnulerAlerte);
    if((eta!=bouttonAnnulerAlerte) && eta==0)
      {
        b=2;
        niveau=niveauAvent;
        
        
      }
      etabouttonAnnulerAlerte=eta;
     
     
     
     
      
     if(b==1)
       allerter();
      if(b==2)
        stoperAlerte();  
        
        
    if(niveau=='v')
    {
      etindreLeb(ledRouge);
      etindreLeb(ledOrange);
      allumerLed(ledVert);
    }
    if(niveau=='o')
    {
      etindreLeb(ledRouge);
      etindreLeb(ledVert);
      allumerLed(ledOrange);
    }
    if(niveau=='r')
    {
      etindreLeb(ledVert);
      etindreLeb(ledOrange);
      allumerLed(ledRouge);
    }
     
}
void allerter()
{
  etindreLeb(ledVert);
  etindreLeb(ledOrange);
  clignoter(ledRouge,100);
  
}

void allumerLed(int I)
{
   digitalWrite(I,0);
}

void etindreLeb(int I)
{
  digitalWrite(I,1);
}

void clignoter(int num,int durree)
{
  if(millis() - temp > durree)
  {
    if(r==0)
    {
      digitalWrite(num,0);
      r=1-r;
    }
    else
    {
      digitalWrite(num,1);
      r=1-r;
    }
    temp=millis();
  }
}

void stoperAlerte()
{
  etindreLeb(ledRouge);
  //pinMode(12, 0);
}




