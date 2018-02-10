int etat;
void setup()
{
    //on met le bouton en entrée
    pinMode(2, INPUT);
    //on active la résistance de pull­up en mettant la broche à l'état haut (mais cela reste toujou
    digitalWrite(2, HIGH);
    
    pinMode(13, OUTPUT);
    digitalWrite(13,HIGH);
}
 
void loop()
{
    //votre programme
    
        etat = digitalRead(2); //Rappel : bouton = 2
 
    if(etat == HIGH)
        actionRelache(); //le bouton est relaché
    else
        actionAppui(); //le bouton est appuy
}

void actionRelache()
{
  digitalWrite(13,HIGH);
}

void actionAppui()
{
  digitalWrite(13,LOW);
}
