//**debut de l'initialisation

#include <LiquidCrystal.h>

//lcd
LiquidCrystal lcd(7, 12, 5, 4, 8, 2); //liaison 4 bits de donnÃ©es
int luminositer = 6;//luminositée de l'afficheur
//led RVB
int const r=10;
int const b=9;
int const v=11;


//declaration des autres ports
const int capteurLumiR = 1;
const int capteurTemperature = 2;
const int piezo = 13;

//varibles pour le led RVB
bool rougeTrFaibleAllumE=false;
bool rougeAllumE=false;
bool clignoTActiV=false;
bool autorisationRougeTrFaibleAllumE=true;
bool autorisationRougeAllumE=true;
bool autorisationClignoTActiV=true;

//varibles pour traiter la réception des données sur la ports série
int const tailletableau = 1000;
char mot[tailletableau]; //le mot lu sur la voie série
String type;
String dateTime;
String strRecu;

//pour faie deiler le text
String textAFaireDefiler;
int p;
String textInitiale;
int restText;

//autres varibles
int valeurLumieire;
float valeurTemperature;

boolean autorisationBuper = true;
boolean alarme = false;
boolean eta, allumerClin = false;
boolean rvbActivE = false;
int contActivEClignoT = 0;

boolean activerCapteurBip = false;






//**fin de l'intitialisation*/

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

byte montre[8] = {
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
  Serial.begin(9600);
  p = 16;
  restText = 0;
  pinMode(piezo, OUTPUT);
  pinMode(r, OUTPUT);
    pinMode(v, OUTPUT);
    pinMode(b, OUTPUT);
  
  lcd.begin(16, 2); //utilisation d'un Ã©cran 16 colonnes et 2 lignes
  analogWrite(luminositer, 70); //0 valeur min

  //pour afficheur les differents les symbole
  lcd.clear();
  lcd.createChar(0, lum); //apprend le caractÃ¨re Ã  l'Ã©cran LCD
  lcd.createChar(1, deg); //apprend le caractÃ¨re Ã  l'Ã©cran LCD
  lcd.createChar(2, montre); //apprend le caractÃ¨re Ã  l'Ã©cran LCD
  //pour le symbole
  afficherSymbole();
  tone(piezo, 600, 500);
}


void afficherSymbole()
{
  lcd.createChar(3, symb);
  lcd.setCursor(4, 0);
  lcd.write((uint8_t) 3);
  lcd.createChar(4, symb2);;
  lcd.setCursor(5, 0);
  lcd.write((uint8_t) 4);
}


void loop()
{
  // com
  if (Serial.available())
    lireVoieSerie();
  if (alarme)
    biper(600, 500);
  if (autorisationClignoTActiV && clignoTActiV)
    faireClignoter( 250);

   if(autorisationRougeAllumE &&  rougeAllumE)
    rvbEnRouge();
   if(autorisationRougeTrFaibleAllumE &&  rougeTrFaibleAllumE)
   {
    rvbEnRougeTrFaible();
    tone(piezo, 500, 500);
   }
   
  if (millis() % 250 == 0)
    faireDefilerText(textAFaireDefiler);
}


void biper(int fr, int intervale) //fait biber le piezo et clignoter la led
{
  if (autorisationBuper)
  {
    analogWrite(luminositer, 200);
  }
  if (millis() % intervale == 0)
  {
    if (autorisationBuper)
    {
      tone(piezo, fr, intervale);
    }
  }
}

void faireClignoter(int intervale)
{
  if (millis() % intervale == 0)
  {
    allumerClin = !allumerClin;
  }
  if (allumerClin)
    rvbEnBleu();
  else
    rvbOff();
}

void capterLamumiaire()
{

  //capteur de lumiaire
  valeurLumieire = analogRead(capteurLumiR);//o-1024
  valeurLumieire = valeurLumieire * 100.0 / 1024; //de 0-100

  if (valeurLumieire > 0 )
  {
    analogWrite(luminositer, 200);
    activerCapteurBip = true;
  }
  else
  {
    analogWrite(luminositer, 0);
    activerCapteurBip = false;
  }
}

void lireVoieSerie(void)
{
  int i = 0; //variable locale pour l'incrémentation des données du tableau
  while (Serial.available() > 0 && i <= tailletableau - 1)
  {
    //on enregistre le caractère lu
    mot[i] = Serial.read();
    //laisse un peu de temps entre chaque accès a la mémoire
    delay(10);
    //on passe à l'indice suivant
    i++;
  }
  mot[i] = '\0';
  strRecu = mot;
  String type = strRecu.substring(0, strRecu.indexOf("="));
    if (type.compareTo("timeDate") == 0)
    {
        String text = strRecu.substring(strRecu.indexOf("=") + 1, strRecu.length());
        String time = text.substring(0, text.indexOf("/"));
        String a = text.substring(text.indexOf("/") + 1, text.indexOf("*"));
        String etatUneHeur = text.substring(text.indexOf("*") + 1, text.indexOf("+"));
        String etatAlarme = text.substring(text.indexOf("+") + 1, text.indexOf("<"));
        String activerAlarme = text.substring(text.indexOf("<") + 1, text.indexOf(">"));
        String autorisationActiverClignotement = text.substring(text.indexOf(">") + 1, text.indexOf("~"));
        String message = text.substring(text.indexOf("~") + 1, text.indexOf("%"));
         String debit = text.substring(text.indexOf("%") + 1, text.indexOf("\\"));
        String peutDEspace=text.substring(text.indexOf("\\") + 1, text.indexOf("{"));
        textAFaireDefiler = message;
        //detection de l'indicatif pour allumer le led en cas d'evenement
        String indicatif = message.substring(0, 2);
        //  Serial.println(indicatif);
        if (indicatif.compareTo(">>") == 0)
        {
            clignoTActiV=true;
        }
        if(debit.compareTo("0K") == 0)
        {
            rougeTrFaibleAllumE=true;
        }
        else
        {
            rougeTrFaibleAllumE=false;
            rvbOff();
        }
        if(peutDEspace.compareTo("v") == 0)
        rougeAllumE=true;
        else
        {
            rougeAllumE=false;
            rvbOff();
        }

        String autorisationLedVitesseActiV=text.substring(text.indexOf("{") + 1, text.indexOf("}"));
        if(autorisationLedVitesseActiV.compareTo("d")==0)
        {
            autorisationRougeTrFaibleAllumE=false;
            rvbOff();
        }
        else
        {
            autorisationRougeTrFaibleAllumE=true;
        }
        String autorisationLedEspaceFaibleActiV=text.substring(text.indexOf("}") + 1, text.indexOf("°"));
        if(autorisationLedEspaceFaibleActiV.compareTo("d")==0)
        {
            autorisationRougeAllumE =false;
            rvbOff();
        }
        else
            autorisationRougeAllumE =true;
        capterLamumiaire();
        ecrireSurLeLCD("               ", 0, 0, false);
        afficherSymbole();
        ecrireSurLeLCD(debit, 0, 0, false);
        ecrireSurLeLCD(time, 7, 0, false);
        if (a.compareTo("a") == 0)
        {
            lcd.setCursor(15, 0);
            lcd.write((uint8_t) 2);

        }
        if (a.compareTo("d") == 0)
        {
          ecrireSurLeLCD(" ", 15, 0, false);
        }
        if (etatUneHeur.compareTo("a") == 0)
        {
          if(activerCapteurBip)
              tone(piezo, 600, 500); //une bipe
        }
        if (etatAlarme.compareTo("a") == 0)
        {
            alarme = true;
            autorisationBuper = true;
        }
        if (activerAlarme.compareTo("d") == 0) // d signifi etiendre l' alarme
        {
            alarme = false;
            autorisationBuper = false;
        }
        if (activerAlarme.compareTo("a") == 0) 
        {
            alarme = true;
            autorisationBuper = true;
        }
        
        if (autorisationActiverClignotement.compareTo("d") == 0)
        {
            autorisationClignoTActiV=false;
            rvbOff();
        }
        else
            autorisationClignoTActiV=true;
    }
}

void afficherMessage(String message)
{
  ecrireSurLeLCD("       ", 4, 1, false);
  ecrireSurLeLCD(message, (message.length() / 2) + 3, 2, false); //(message.length()/2)+4
}

void ecrireSurLeLCD(String text, int colonne, int linge, boolean avecEffacement)
{
  if (avecEffacement)
    lcd.clear();
  lcd.setCursor(colonne, linge);
  lcd.print(text);
}

void faireDefilerText(String text)
{
  if (p == 0)
  {
    if (restText < text.length())
    {
      restText++;
    }
    else
    {
      p = 16;
      restText = 0;
    }
  }
  else
  {
    p--;
  }
  ecrireSurLeLCD("                ", 0, 1, false);
  ecrireSurLeLCD(text.substring(restText), p, 1, false);
}


void rvbOff()
{
        analogWrite(r, 0);
      analogWrite(v, 0);
     analogWrite(b, 0); 
}

 void rvbEnRouge()
 {
      analogWrite(r, 250);
      analogWrite(v, 0);
     analogWrite(b, 0); 
 }

 void rvbEnRougeTrFaible()
 {
    analogWrite(r, 10);
      analogWrite(v, 0);
     analogWrite(b, 0); 
 }
 void rvbEnBleu()
 {
   
       analogWrite(r, 50);
      analogWrite(v, 50);
      analogWrite(b, 150); 
 }
