
/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 12;
const int commandeRelai=13;
const int commandeLumiaire=11;
IRrecv irrecv(RECV_PIN);

decode_results results;

boolean alumerRelai=true;
boolean alumerLumiaire=false;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(commandeRelai, OUTPUT);
  pinMode(commandeLumiaire, OUTPUT);
}

void loop() 
{
  if (irrecv.decode(&results)) 
  {
    //Serial.println(results.value);
    if(results.value==948321248)
      alumerRelai=!alumerRelai;
    if(results.value==948321232)
      alumerLumiaire=!alumerLumiaire;
      
    
    irrecv.resume(); // Receive the next value
  }
  delay(100);
  //1 948321248
  //sys 948321278
  //2 948321232
  
  if(alumerRelai)
    digitalWrite(commandeRelai,1);
  else
    digitalWrite(commandeRelai,0);
    
  if(alumerLumiaire)
    digitalWrite(commandeLumiaire,1);
  else
    digitalWrite(commandeLumiaire,0);
    
  

}
