void setup()
{
    Serial.begin(9600);
    pinMode(4, OUTPUT);
    pinMode(7, OUTPUT);
}
 
void loop()
{
    char carlu = 0; //variable contenant le caractère à lire
    int cardispo = 0; //variable contenant le nombre de caractère disponibles dans le buffer
    
    cardispo = Serial.available();
    
    while(cardispo > 0) //tant qu'il y a des caractères à lire
    {
        carlu = Serial.read(); //on lit le caractère
      //  Serial.println(carlu); //puis on le renvoi à l’expéditeur tel quel
     
      
      if(carlu=='a')
          digitalWrite(4, HIGH);
       if(carlu=='b')
          digitalWrite(4, LOW);

             if(carlu=='a')
          digitalWrite(7, LOW);
       if(carlu=='b')
          digitalWrite(7, HIGH);   
        
      cardispo = Serial.available(); //on relit le nombre de caractères dispo
    }
    //fin du programme
}
