
char L='A';
char l='a';
char ch='0';
int choie;
int c;
void setup()
{
    //on dÃ©marre la liaison en la rÃ©glant Ã  une vitesse de 9600 bits par seconde.
    Serial.begin(9600);
    
   //l'objet exÃ©cute une premiÃ¨re fonction
   c=0;
  /* for(c=0;c<27;c++)
    {
      L=L+c;
      Serial.println(L);
    }*/
   /* L+=1;
    if(L==66)
    {
      Serial.println(L);
    }*/
    choie=0;
    c=0;

    
}
void loop()
{
    //votre programme
    
   // if(L==
   if(choie==0)
   {
     Serial.println(L);
     delay(250);
     c++;
     L++;
     if(L=='Z'+1)
     {
       c=0;
       L='A';
       choie++;
       delay(1000);
     }
   }   
 
    if(choie==1)
   {
     Serial.println(l);
     delay(250);
     c++;
     l++;
     if(l=='z'+1)
     {
       c=0;
       l='a';
       choie++;
       delay(1000);
     }
   }   
   
       if(choie==2)
   {
     Serial.println(ch);
     delay(250);
     c++;
     ch++;
     if(ch=='9'+1)
     {
       c=0;
       ch='0';
       choie=0;
       delay(1000);
     }
   }   
   
  /* char i = 0;
       char lettre = 'a'; // ou 'A' pour envoyer en majuscule
 
    Serial.println("­­­­­­  L'alphabet des Zéros  ­­­­­­"); //petit message d'accueil
 
    //on commence les envois
    for(i=0; i<26; i++)
    {
        Serial.print(lettre); //on envoie la lettre
        lettre = lettre + 1; //on passe à la lettre suivante
        delay(250); //on attend 250ms avant de réenvoyer
    }
    Serial.println(""); //on fait un retour à la ligne
 
    delay(5000); //on attend 5 secondes avant de renvoyer l'alphabet*/
}
