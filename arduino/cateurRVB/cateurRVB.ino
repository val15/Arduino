

const int ledRouge = 9;
const int ledVerte =  10;
const int ledBleue = 11;
int r,g,b;
int valeurRLue,valeurGLue,valeurBLue;
 
void setup()
{
  Serial.begin(9600);
    //on dÃ©clare les broches en sorties
    pinMode(ledRouge, OUTPUT);
    pinMode(ledVerte, OUTPUT);
    pinMode(ledBleue, OUTPUT);
 
    //on met la valeur de chaque couleur
    
    r=0;
    g=0;
    b=0;
  }
 
void loop()
{
    
    valeurRLue = analogRead(0);
    delay(5);
    valeurGLue = analogRead(1);
    delay(5);
    valeurBLue = analogRead(2);
    delay(5);
    

    Serial.print("valeur rouge : ");
    Serial.print(valeurRLue);
    Serial.print("\tvaleur vert : ");
    Serial.print(valeurGLue);
    Serial.print("\tvaleur bleu : ");
    Serial.println(valeurBLue);
    //Serial.println(valeurRLue);
    r=valeurRLue/100;
    g=valeurGLue/100;
    b=valeurBLue/100;
    colore(r,g,b);
    
    
}

void colore(int re,int gr,int bl)
{
      analogWrite(ledRouge, re);
      analogWrite(ledVerte, gr);
      analogWrite(ledBleue, bl);  
}

