const int unBouton = 2; //un bouton sur la broche 2
bool etat=false;
void setup()
{
  Serial.begin(9600);
    //on met le bouton en entrée
    pinMode(unBouton, INPUT);
    //on active la résistance de pull­up en mettant la broche à l'état haut (mais cela reste toujou
    digitalWrite(unBouton, HIGH);

    pinMode(7, OUTPUT);
}
 
void loop()
{
  etat = digitalRead(unBouton); //Rappel : bouton = 2
  int ichoix=0;
    if(etat == HIGH)
        ichoix = 0;
        actionRelache(); //le bouton est relaché
    else
        ichoix=1;
        actionAppui();

 //  if()
    digitalWrite(7,etat);
}

void actionAppui()
{
  etat!=etat;
}

void actionRelache()
{

}
}

