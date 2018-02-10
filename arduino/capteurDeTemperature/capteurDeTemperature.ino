

 
int valeurCapter;
float tension,temperature;
 
void setup()
{
  Serial.begin(9600);
    //on dÃÂÃÂ©clare les broches en sorties
}
 
void loop()
{
     valeurCapter = analogRead(0);
    
        //tension = (valeurCapter /1024.0)* 5.0 ;  // conversion de cette valeur en tension
        tension =valeurCapter* 5.0 / 1024;
       Serial.print(tension);
        Serial.println("V");
        
       /* temperature=(tension-.5)*100;//convertion du temsino en temperature
        Serial.print("temperature = ");
        Serial.println(temperature);*/
        
        delay(1);

    
    
}



