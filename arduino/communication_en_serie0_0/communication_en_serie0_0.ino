void setup()
{
    //on démarre la liaison en la réglant à une vitesse de 9600 bits par seconde.
    Serial.begin(9600);
    
   //l'objet exécute une première fonction
    Serial.print("Salut les zéros ! ");
    //puis une deuxième fonction, différente cette fois­ci
    Serial.println("Vive Zozor !");
    //et exécute à nouveau la même
    Serial.println("Cette phrase passe en dessous des deux précédentes");
    
    
    
  /*   Serial.println(9);            //chiffre
    Serial.println(42);           //nombre
    Serial.println(32768);        //nombre
    Serial.print(3.1415926535,10);   //nombre à virgule*/
    
    Serial.println(65, BIN); //envoie la valeur 1000001
    Serial.println(65, DEC); //envoie la valeur 65
    Serial.println(65, OCT); //envoie la valeur 101 (ce n'est pas du binaire !)
    Serial.println(65, HEX); //envoie la valeur 41
}
void loop()
{
    //votre programme
}
