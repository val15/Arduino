
//**moteur M0
const int sortieControleVitesseM0=3;
const int commandeSens1M0=2;
const int commandeSens2M0=4;

//**moteur M1
const int sortieControleVitesseM1=11;
const int commandeSens1M1=12;
const int commandeSens2M1=13;


//**la vitesse
int vitesse=0;
//**pour la lecture du port serie
int const tailletableau=1000;
String strRecu;
char mot[tailletableau]; //le mot lu sur la voie sÃ©rie

//**pour le retour
boolean activerRetour=false;
int dirrectionRetour=0;


int valeurDentrR;
int sens=0;
boolean eta,etatSens1,etatSens2; 


void setup()
{
  Serial.begin(9600);
    //on dÃÂÃÂ©clare les broches en sorties
    //**configuration
    pinMode(sortieControleVitesseM0, OUTPUT);
    pinMode(sortieControleVitesseM1, OUTPUT);
    
    pinMode(commandeSens1M0, OUTPUT);
    pinMode(commandeSens2M0, OUTPUT);
    pinMode(commandeSens1M1, OUTPUT);
    pinMode(commandeSens2M1, OUTPUT);
    vitesse=1023;
    metreVitesseM1(1023);
    
 
    

   
   
  }
 
void loop()
{
 // Serial.println(sens);
    
  /*  valeurDentrR = analogRead(entreControleVitesse);
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
    //Serial.println(valeurDentrR);*/
   // definirSensM0(0);
    //metreVitesseM0(100);
    //lireVoiSerie();
   // metreVitesseM0(1000);
    definirSensM0(2);
    metreVitesseM0(1000);
    
    
    //retourDirrection(1);   
}
void retourDirrection(int sens )
{

      if(activerRetour)
      {
        definirSensM1(sens);
        delay(30);
      }
      activerRetour=false;
      definirSensM1(0);
}

void lireVoiSerie(void)
{
    int i = 0; //variable locale pour l'incrÃ©mentation des donnÃ©es du tableau
    
    //on lit les caractÃ¨res tant qu'il y en a
    //OU si jamais le nombre de caractÃ¨res lus atteint 19 (limite du tableau stockant le mot Â­ 1 ca
    while(Serial.available() > 0 && i <= tailletableau-1)
    {
        //on enregistre le caractÃ¨re lu
        mot[i] = Serial.read();
        //laisse un peu de temps entre chaque accÃ¨s a la mÃ©moire
        delay(10);
        //on passe Ã  l'indice suivant
        i++;
    }
    //on supprime le caractÃ¨re '\n' et on le remplace par celui de fin de chaine '\0'
    mot[i] = '\0';
    
    
    strRecu=mot;
    
    String type=strRecu.substring(0,strRecu.indexOf("="));
   if(type.compareTo("v")==0)//fd pour faire defiler
    {
      vitesse=strRecu.substring(strRecu.indexOf("=")+1,strRecu.length()).toInt();
     // Serial.println("aa"); 
    }
    if(type.compareTo("a")==0)//fd pour faire defiler
    {
      definirSensM0(2);
    }
    if(type.compareTo("r")==0)//fd pour faire defiler
    {
      definirSensM0(1);
    //  vitesse=100;
    }
    if(type.compareTo("g")==0)//fd pour faire defiler
    {
      activerRetour=true;
      dirrectionRetour=1;
       definirSensM1(2);
    }
    if(type.compareTo("d")==0)//fd pour faire defiler
    {
      activerRetour=true;
      dirrectionRetour=2;
      definirSensM1(1);
      
    }
    
    if(type.compareTo("s")==0)//fd pour faire defiler
    {
      definirSensM0(0);
    }
    if(type.compareTo("l")==0)//fd pour faire defiler
    {
      
      retourDirrection(dirrectionRetour);
      definirSensM1(0);
    }
}

void definirSensM0(int sens)//1 ou 2 ou 0
{
  if(sens==1)
  {
    digitalWrite(commandeSens1M0,0);
    digitalWrite(commandeSens2M0,1);
  }
  if(sens==2)
  {
    digitalWrite(commandeSens1M0,1);
    digitalWrite(commandeSens2M0,0);
  }
  if(sens==0)
  {
    digitalWrite(commandeSens1M0,0);
    digitalWrite(commandeSens2M0,0);
  }
  
}

void definirSensM1(int sens)//1 ou 2 ou 0
{
  if(sens==1)
  {
    digitalWrite(commandeSens1M1,0);
    digitalWrite(commandeSens2M1,1);
  }
  if(sens==2)
  {
    digitalWrite(commandeSens1M1,1);
    digitalWrite(commandeSens2M1,0);
  }
  if(sens==0)
  {
    digitalWrite(commandeSens1M1,0);
    digitalWrite(commandeSens2M1,0);
  }
  
}

void metreVitesseM0(int v)//min =0 , max = 255
{
  analogWrite(sortieControleVitesseM0,v);
}

void metreVitesseM1(int v)
{
  analogWrite(sortieControleVitesseM1,v);
}



