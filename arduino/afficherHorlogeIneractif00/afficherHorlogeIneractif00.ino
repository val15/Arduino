



#include <LiquidCrystal.h>
#include <IRremote.h>

LiquidCrystal lcd(7,10,5,4,3,2); //liaison 4 bits de donnÃ©es
int contraste=9;
int luminositer=6;
int n=0;
int const tailletableau=1000;


//pour lr capteur IR
int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);

decode_results results;





int q=0;
int c=0;
char chainneRecus[tailletableau];
String type;
String dateTime;
String strRecu;
char mot[tailletableau]; //le mot lu sur la voie série



const int capteurLumiR=1;
const int capteurTemperature=2;
const int piezo=11;
const int led=8;
int valeurLumieire;
float valeurTemperature;

boolean autorisationBuper=true;
boolean alarme=false;
boolean eta,allumerClin=false;
boolean clignioTActivE=false;
int contActivEClignoT=0;


//pour faie deiler le text
int p;
String textInitiale;
int restText;


String textAFaireDefiler;
    //caractere
    byte lum[8] = {
    B10101,
    B01110,
    B10101,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000
    };
    
    byte deg[8] = {
    B01110,
    B10001,
    B10001,
    B01110,
    B00000,
    B00000,
    B00000,
    B00000
    };
    
    byte cloche[8] = {
    B01110,
    B10101,
    B10111,
    B10001,
    B01110,
    B00000,
    B00000,
    B00000
    };
    
  byte symb[8] = {
    B01110,
    B10001,
    B11111,
    B10001,
    B01110,
    B00000,
    B00000,
    B00000
    };
      byte symb2[8] = {
    B01110,
    B10101,
    B11111,
    B10101,
    B01110,
    B00000,
    B00000,
    B00000
    };
    
void setup()
{
  
        p=16;
      restText=0;
    pinMode(piezo,OUTPUT);
    pinMode(led,OUTPUT);
    digitalWrite(led,1);
    Serial.begin(9600);
    lcd.begin(16,2); //utilisation d'un Ã©cran 16 colonnes et 2 lignes
   analogWrite(contraste,10);//0 valeur max
   analogWrite(luminositer,70);//0 valeur min
   
        lcd.clear();
         lcd.createChar(0,lum); //apprend le caractÃ¨re Ã  l'Ã©cran LCD
        lcd.createChar(1,deg); //apprend le caractÃ¨re Ã  l'Ã©cran LCD
        
        
      
        lcd.createChar(2,cloche); //apprend le caractÃ¨re Ã  l'Ã©cran LCD
        afficherSymbole();   


        //pour le capteur IR
       irrecv.enableIRIn();
       
       
}


void loop()
{
  
   //biper(200);
  analogWrite(piezo,20);
  /*delay(500);
  analogWrite(piezo,0);
  delay(500);*/

    /*
    if(Serial.available())
    {
        //alors on va lire le contenu de la réception
        lireVoieSerie();
        //on entre dans une variable la valeur retournée par la fonction comparerMot()
       // etat = comparerMot(mot);
    }
    
  if(alarme)
  {
   //** biper(600,100);

  }
  
  
  if(clignioTActivE && contActivEClignoT==0)
    faireClignoter(led,250);
    //faireClignoter(piezo,250);
  
 
   if(millis()%250==0)
    {
      faireDefilerText(textAFaireDefiler);
    }
    
    //traitement des commande par IR
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value);
   /* if(results.value==948321248)
      alumerRelai=!alumerRelai;
    if(results.value==948321232)
      alumerLumiaire=!alumerLumiaire;*/
      
   /* 
    irrecv.resume(); // Receive the next value
  }
  delay(100);*/
  
 
    
  
}

void afficherSymbole()
{
        lcd.createChar(3,symb);
        lcd.setCursor(4,0);
        lcd.write((uint8_t) 3);
        lcd.createChar(4,symb2);;
        lcd.setCursor(5,0);
        lcd.write((uint8_t) 4);
}


/*void biper(int intervale)//fait biber le piezo et clignoter la led
{
  /*if(autorisationBuper)
  {
      analogWrite(luminositer,200);
      analogWrite(contraste,5);
  }*/
  /* if(millis()%intervale==0)
  {
    if(autorisationBuper)
    {
    //**  tone(piezo,fr,intervale);
    analogWrite(piezo,20);
      digitalWrite(led,0);
    }*/
 // }*/
 /* else
  {
    digitalWrite(led,1);
  }
  
  
  
}*/

void faireClignoter(int led,int intervale)
{      
  if(millis()%intervale==0)
  {
    allumerClin=!allumerClin;
  }
  if(allumerClin)
    digitalWrite(led,0);
  else
   digitalWrite(led,1);
}

void capterTemperature()
{
      //capteur de temperature
        valeurTemperature = analogRead(capteurTemperature);//o-1024
        valeurTemperature=valeurTemperature*5.0/1024;//en volte: 0-5
    
  // valeurTemperature=map(valeurTemperature, 0.00, 5.00, -40, 125);
   
      valeurTemperature=(valeurTemperature-0.5)*100;
    //  Serial.println(valeurTemperature);
        lcd.setCursor(2,0);
        lcd.write((uint8_t) 1);
        ecrireSurLeLCD(valeurTemperature,0,0,false);
}

void capterLamumiaire()
{
          valeurLumieire = analogRead(capteurLumiR);//o-1024
          valeurLumieire=valeurLumieire*100.0/1024;//de 0-100
   
          if(valeurLumieire>0 )
          {
            analogWrite(luminositer,200);
            analogWrite(contraste,5);
          }
          
          else
          {
            analogWrite(luminositer,0);
            // contActivEClignoT++;//pour desactiver le clignotement de la led
  
          }
}

//lit un mot sur la voie série (lit jusqu'à rencontrer le caractère '\n')
void lireVoieSerie(void)
{
    int i = 0; //variable locale pour l'incrémentation des données du tableau
    
    //on lit les caractères tant qu'il y en a
    //OU si jamais le nombre de caractères lus atteint 19 (limite du tableau stockant le mot ­ 1 ca
    while(Serial.available() > 0 && i <= tailletableau-1)
    {
        //on enregistre le caractère lu
        mot[i] = Serial.read();
        //laisse un peu de temps entre chaque accès a la mémoire
        delay(10);
        //on passe à l'indice suivant
        i++;
    }
    //on supprime le caractère '\n' et on le remplace par celui de fin de chaine '\0'
    mot[i] = '\0';
    
    
    strRecu=mot;
   // Serial.println(strRecu);
    String type=strRecu.substring(0,strRecu.indexOf("="));      
   
    if(type.compareTo("timeDate")==0)
    {
      String text=strRecu.substring(strRecu.indexOf("=")+1,strRecu.length());
     // lcd.clear();
     String time=text.substring(0,text.indexOf("/"));
     String a=text.substring(text.indexOf("/")+1,text.indexOf("*"));
     String etatUneHeur=text.substring(text.indexOf("*")+1,text.indexOf("+"));
     String etatAlarme=text.substring(text.indexOf("+")+1,text.indexOf("~"));
     //"~"+m_evenementDuJour+"°"+m_evenement1+"("+m_evenement2+")"+m_evenement3+"[");
     String message=text.substring(text.indexOf("~")+1,text.indexOf("%"));
    textAFaireDefiler=message;
     //detection de l'indicatif pour allumer le led en cas d'evenement
     String indicatif=message.substring(0,2);
   //  Serial.println(indicatif);
   if(indicatif.compareTo(">>")==0)
     clignioTActivE=true;
   
    capterLamumiaire();
     ecrireSurLeLCD("               ",0,0,false);
   //**  afficherSymbole();
      capterTemperature();
      ecrireSurLeLCD(time,7,0,false);
    
      if(a.compareTo("a")==0)
      {
        lcd.setCursor(15,0);
        lcd.write((uint8_t) 2);
        
      }
      if(a.compareTo("d")==0)
      {
        ecrireSurLeLCD(" ",15,0,false);
      }
      if(etatUneHeur.compareTo("a")==0)
      {
       //** tone(piezo,600,500);//une bupe
      }  
      if(etatAlarme.compareTo("a")==0)
      {
        alarme=true;
        autorisationBuper=true;      }   
    }
    else if(type.compareTo("eteindreLed")==0)
    {
      contActivEClignoT++;//pour desactiver le clignotement de la led
    }
}

void afficherMessage(String message)
{
  ecrireSurLeLCD("       ",4,1,false);
  ecrireSurLeLCD(message,(message.length()/2)+3,2,false);//(message.length()/2)+4
}

void ecrireSurLeLCD(String text,int colonne,int linge,boolean avecEffacement)
{
  if(avecEffacement)
  {
    lcd.clear();
    lcd.setCursor(colonne,linge);
    lcd.print(text);
  }
  else
  {
    lcd.setCursor(colonne,linge);
    lcd.print(text);
  }
}

void ecrireSurLeLCD(int text,int colonne,int linge,boolean avecEffacement)
{
  if(avecEffacement)
  {
    lcd.clear();
    lcd.setCursor(colonne,linge);
    lcd.print(text);
  }
  else
  {
    lcd.setCursor(colonne,linge);
    lcd.print(text);
  }
}

void faireDefilerText(String text)
{
  if(p==0)
  {
    if(restText<text.length())
    {
      restText++;
    }
    else
    {
      p=16;
      restText=0;
    }
    
  }
  else
  {
    p--;
  }
  
  ecrireSurLeLCD("                ",0,1,false);
  ecrireSurLeLCD(text.substring(restText),p,1,false);
  
}

