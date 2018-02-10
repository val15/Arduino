const int ledRouge = 9;
const int ledVerte =  10;
const int ledBleue = 11;
int c,r,g,b;
int d;
 
void setup()
{
  Serial.begin(9600);
    //on déclare les broches en sorties
    pinMode(ledRouge, OUTPUT);
    pinMode(ledVerte, OUTPUT);
    pinMode(ledBleue, OUTPUT);
 
    //on met la valeur de chaque couleur
    
    c=0;
    r=0;
    g=0;
    b=0;
    d=10;
  }
 
void loop()
{
    //on ne change pas la couleur donc rien à faire dans la boucle principale
    r=155;
    g=25;
    b=200;
    
    while(r<256)
    {
      b++,
      Serial.print(r);
      Serial.print(g);
      Serial.println(b);
      colore(r,g,b);
      delay(d);
      if(b==255)
      {
        b=0;
        g++;
      }
      if(g==255)
      {
        g=0;
        r++;
      }
      if(r==255)
      {
        r=0;
      }
    } 
}

void colore(int re,int gr,int bl)
{
      analogWrite(ledRouge, re);
      analogWrite(ledVerte, gr);
      analogWrite(ledBleue, bl);  
}
