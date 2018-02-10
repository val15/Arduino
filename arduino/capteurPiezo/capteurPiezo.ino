


const int seuil_detection = 20; 
int valeurSon;
float tension;
 
void setup()
{
  Serial.begin(9600);
    //on dÃÂ©clare les broches en sorties
    pinMode(2, OUTPUT);
    pinMode(12, OUTPUT);
   digitalWrite(2, 1);
}
 
void loop()
{
   /* digitalWrite(12, HIGH);
    delay(5);
    digitalWrite(12, LOW);
    delay(5);  */
    
    //tone(12, 5000);
  
  
  /* valeurSon = analogRead(0);
    
    tension = (valeurSon * 5.0) / 1024;  // conversion de cette valeur en tension
        Serial.print("valeur son = ");
        Serial.println(valeurSon);
 
    if (valeurSon >= seuil_detection)
    {
        digitalWrite(2, 0);  // application du nouvel état en broche 13
 
        // envoi vers l'ordinateur, via la liaison série, des données correspondant au Toc et à la 
        Serial.println("Toc !");
        Serial.print("Tension = ");
        Serial.print(tension);
        Serial.println(" V");
    }
    else
    {
      digitalWrite(2, 1);
    }

        //Serial.println(" V");*/
    
    
}


