

const int ledRouge = 9;
const int ledVerte =  10;
const int ledBleue = 11;
int r,g,b;
int valeurRLue,valeurGLue,valeurBLue;
 
void setup()
{
  Serial.begin(9600);
    //on déclare les broches en sorties
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
    valeurGLue = analogRead(1);
    valeurBLue = analogRead(2);
    
    r=valeurRLue*255.0/1024;
    g=valeurGLue*255.0/1024;
    b=valeurBLue*255.0/1024;
    //Serial.println(r);
    //Serial.println(valeurRLue);
    colore(r,g,b);
    
    
}

void colore(int re,int gr,int bl)
{
      analogWrite(ledRouge, re);
      analogWrite(ledVerte, gr);
      analogWrite(ledBleue, bl);  
}
