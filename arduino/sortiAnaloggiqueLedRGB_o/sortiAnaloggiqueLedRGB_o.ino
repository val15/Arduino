const int ledRouge = 9;
const int ledVerte =  10;
const int ledBleue = 11;
int c;
 
void setup()
{
    //on déclare les broches en sorties
    pinMode(ledRouge, OUTPUT);
    pinMode(ledVerte, OUTPUT);
    pinMode(ledBleue, OUTPUT);
 
    //on met la valeur de chaque couleur
    analogWrite(ledRouge, 255);
    analogWrite(ledVerte, 144);
    analogWrite(ledBleue, 0);
    
    c=0;
}
 
void loop()
{
    //on ne change pas la couleur donc rien à faire dans la boucle principale
    colore(c);
    delay(500);
    c++;
    if(c==7)
    {
      c=0;
    }
    
}

void colore(int i)
{
  switch(i)
    {
    case 0 : //rouge
      analogWrite(ledRouge, 255);
      analogWrite(ledVerte, 0);
      analogWrite(ledBleue, 0);
    break;
    case 1 : //vert
      analogWrite(ledRouge, 0);
      analogWrite(ledVerte, 255);
      analogWrite(ledBleue, 0);
    break;
    case 2 : //bleu
      analogWrite(ledRouge, 0);
      analogWrite(ledVerte, 0);
      analogWrite(ledBleue, 255);
    break;
    case 4 : //jaune
      analogWrite(ledRouge, 255);
      analogWrite(ledVerte, 255);
      analogWrite(ledBleue, 0);
    break;
    case 5 : //violet
      analogWrite(ledRouge, 255);
      analogWrite(ledVerte, 0);
      analogWrite(ledBleue, 255);
    break;
    case 6 : ////blanc
      analogWrite(ledRouge, 255);
      analogWrite(ledVerte, 255);
      analogWrite(ledBleue, 255);
    break;
    default : //noir
      analogWrite(ledRouge, 0);
      analogWrite(ledVerte, 0);
      analogWrite(ledBleue, 255);
    break;
  }
    
    
    
}
