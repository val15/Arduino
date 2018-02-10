 int v;
void setup()
{
  Serial.begin(9600);
    //on dÃ©clare les broches en sorties
    pinMode(3, OUTPUT);
 
    //on met la valeur de chaque couleur
   // analogWrite(3, 0);
  }
 
void loop()
{
    
    v = analogRead(0);
    v=v*255.0/1024;
    analogWrite(3,v);
    Serial.println(v);
    
}
