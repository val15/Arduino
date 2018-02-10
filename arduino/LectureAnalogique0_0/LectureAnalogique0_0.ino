//broche analogique 3 OU broche numérique 3
const int monCapteurAnalogeique = 0;
 
//la valeur lue sera comprise entre 0 et 1023
int valeurLue = 0;
float tension;
 
void setup()
{
   //on se contente de démarrer la liaison série
    Serial.begin(9600);
    
    //permet de choisir une tension de référence de 1.1V
    //analogReference(INTERNAL);
}
 
void loop()
{
    //on mesure la tension du capteur sur la broche analogique 3
    valeurLue = analogRead(monCapteurAnalogeique);
 
    
    //on traduit la valeur brute en tension (produit en croix)
    tension = valeurLue * 5.0 / 1024;
    Serial.println(valeurLue);
    Serial.print('v');
        //on saute une ligne entre deux affichages
    Serial.println();
    //on attend une demi­seconde pour que l'affichage ne soit pas trop rapide
    delay(500);
    
}
