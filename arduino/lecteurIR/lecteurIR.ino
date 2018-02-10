int entrEAnologique=A0;
int valeurRLue=0;
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  valeurRLue = analogRead(entrEAnologique);
  Serial.println(valeurRLue);
  delay(500);

  
}
