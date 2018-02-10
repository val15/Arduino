const int sortieControleVitesse=3;
const int entreControleVitesse=A0;
const int commandeSens1=2;
const int commandeSens2=4;
const int bouttonCommandeSens1=11;
const int bouttonCommandeSens2=12;
int valeurDentrR;
int sens=0;
boolean eta,etatSens1,etatSens2; 

void setup()
{
  Serial.begin(9600);
    //on dÃÂ©clare les broches en sorties
    pinMode(sortieControleVitesse, OUTPUT);
    
    pinMode(commandeSens1, OUTPUT);
    pinMode(commandeSens2, OUTPUT);
 
    //on met le bouton en entrée
    pinMode(bouttonCommandeSens1, INPUT);
    //on active la résistance de pull-up en mettant la broche à l'état haut (mais cela reste toujours une entrée)
    digitalWrite(bouttonCommandeSens1, HIGH);
        //on met le bouton en entrée
    pinMode(bouttonCommandeSens2, INPUT);
    //on active la résistance de pull-up en mettant la broche à l'état haut (mais cela reste toujours une entrée)
    digitalWrite(bouttonCommandeSens2, HIGH);
   
   
  }
 
void loop()
{
  //Serial.println(sens);
    
    valeurDentrR = analogRead(entreControleVitesse);
    valeurDentrR=valeurDentrR*255.0/1024;
    //lecture des sens
    eta = digitalRead(bouttonCommandeSens1);
    if((eta!=etatSens1) && eta==0)
      {
        definirSens(0);
        //delay(500);
          sens=1;
      }
      etatSens1=eta;
      
    eta = digitalRead(bouttonCommandeSens2);
    if((eta!=etatSens2) && eta==0)
      {
         definirSens(0);
          //delay(500);
          sens=2;
      }
      etatSens2=eta;
      
      
    definirSens(sens);
    metreVitesseA(valeurDentrR);
    //Serial.println(valeurDentrR);
    
    
}

void definirSens(int sens)
{
  if(sens==1)
  {
    digitalWrite(commandeSens1,0);
    digitalWrite(commandeSens2,1);
  }
  if(sens==2)
  {
    digitalWrite(commandeSens1,1);
    digitalWrite(commandeSens2,0);
  }
  if(sens==0)
  {
    digitalWrite(commandeSens1,0);
    digitalWrite(commandeSens2,0);
  }
  
}

void metreVitesseA(int v)
{
  analogWrite(sortieControleVitesse,v);
}
