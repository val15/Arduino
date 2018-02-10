int capteurG=A9;
int capteurD=A8;
int capteurM=A10;

int ledCapteurG=25;
int ledCapteurM=27;
int ledCapteurD=29;

void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(ledCapteurM, OUTPUT);
  pinMode(ledCapteurD, OUTPUT);
  pinMode(ledCapteurG, OUTPUT);

  digitalWrite(ledCapteurG,0);
  digitalWrite(ledCapteurD,0);
  digitalWrite(ledCapteurG,0);
  
}
 
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
 // int sensorValue = analogRead(ledCapteur1);
  
  // print out the value you read:
  Serial.print( analogRead(capteurG));
  Serial.print("\t");
  Serial.print( analogRead(capteurM));
  Serial.print("\t");
  if(capteurD>100)
    Serial.print( analogRead(capteurD-100));
  else
    Serial.print( analogRead(capteurD));
  Serial.println();
 // delay(1);        // delay in between reads for stability
  lireLigneAuSol();
}

void lireLigneAuSol()
{

  int vlimit=900;
  if(analogRead(capteurM)>=vlimit)
    digitalWrite(ledCapteurM,1);
  else
    digitalWrite(ledCapteurM,0);
    
  if(analogRead(capteurG)>=vlimit)
    digitalWrite(ledCapteurG,1);
  else
    digitalWrite(ledCapteurG,0);

  if(analogRead(capteurD)>=vlimit)
    digitalWrite(ledCapteurD,1);
  else
    digitalWrite(ledCapteurD,0);
  
}

