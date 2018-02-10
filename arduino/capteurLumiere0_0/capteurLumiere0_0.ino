


int v,v1,valeurLumieire,valeurLumieire1;
float seuilObscurite = 75; 
 
void setup()
{
  Serial.begin(9600);
    //on dÃ©clare les broches en sorties
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    valeurLumieire=0;
    valeurLumieire1=0;
}
 
void loop()
{
    
   valeurLumieire = analogRead(0);
   valeurLumieire1 = analogRead(1);
    
    v=valeurLumieire*255.0/1024;
    v1=valeurLumieire1*255.0/1024;
    if(v>v1)
    {
      digitalWrite(9,0);
      digitalWrite(10,1);
    }
    else if(v<v1)
    {
      digitalWrite(10,0);
      digitalWrite(9,1);
    }
    else 
    {
      digitalWrite(9,0);
      digitalWrite(9,1);
    }
    //analogWrite(10,v1);
    
    // envoie vers l'ordinateur, via la liaison série, la valeur de la tension lue
    Serial.print("Tension = ");
    Serial.print(v);
    Serial.println(" V");
 
    delay(500);  
    
    
}

