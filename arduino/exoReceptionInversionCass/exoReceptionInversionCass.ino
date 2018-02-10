    char carlu = 0; //variable contenant le caractÃ¨re Ã  lire
    int cardispo = 0; //variable contenant le nombre de caractÃ¨re disponibles dans le buffer
void setup()
{
    //on dÃ©marre la liaison en la rÃ©glant Ã  une vitesse de 9600 bits par seconde.
    Serial.begin(9600);
    
    
 /* Serial.println(toMinuscule('Z'));
  Serial.println(toMaguscule('x'));*/
    
}
void loop()
{
    //votre programme
    
   // if(L==

    
    
    //fin du programme
    delay(100);
  
     
}

void serialEvent()
{
 /* while (Serial.available())
     {*/
    // Serial.println();
      cardispo = Serial.available();
      String mot="";
    
    while(cardispo > 0) //tant qu'il y a des caractÃ¨res Ã  lire
    {
      
        carlu = Serial.read(); //on lit le caractÃ¨re
        if(carlu>='A' && carlu<='Z')
        {
          mot+=toMinuscule(carlu);
           // Serial.print(toMinuscule(carlu));
        }
       else if(carlu>='a' && carlu<='z')
        {
          //  Serial.print(toMaguscule(carlu));
          mot+=toMaguscule(carlu);
        }
        else
        {
         // Serial.print(carlu); //puis on le renvoi Ã  lâexpÃ©diteur tel quel
         mot+=carlu;
        }
        
        
        cardispo = Serial.available(); //on relit le nombre de caractÃ¨res dispo
      //  Serial.println(mot);

    }
     Serial.println(mot);
  
}



char toMinuscule(char I)
{
  char i,c=0;
  char chT='A';
  for(c=0;c<27;c++)
  {
    
    if(I==chT)
    {
      i='a'+c;
    }
    chT++;  
  }  
  return i;  
}

char toMaguscule(char I)
{
  char i,c=0;
  char chT='a';
  for(c=0;c<27;c++)
  {
    
    if(I==chT)
    {
      i='A'+c;
    }
    chT++;  
  }  
  return i;  
}
