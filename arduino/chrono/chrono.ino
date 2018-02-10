#include <TM1640.h>
#include <TM16XXFonts.h>
#include <TM1638.h>
#include <InvertedTM1638.h>
#include <TM16XX.h>




TM1640 module(8, 9); // define a module on data pin 3, clock pin 2

const long MAX = 100000000; // upper limit on displaying 8 digits
char buffer[16 + 1]; // our display buffer
long hi; // counter for left-most 8 digits; higher part of counter
long lo; // counter for right-most 8 digits; lower part of counter
void setup() 
{
  // put your setup code here, to run once:
  module.setupDisplay(true, 1);
  lo = MAX - 1000;  // interesting start value
  hi = MAX - 1; // another interesting start value

}

void loop() 
{
  // put your main code here, to run repeatedly:
  lo += 1; // increment lower part of the counter

  if (lo == MAX) { // have we overflowed the lower part of the counter?
    lo = 0; // reset lower to zero
    ++hi; // increment high part

    if (hi == MAX) { // have we overflowed the higher part of the counter?
      lo = 0; 
      hi = 0;
    }
  }

  if (hi == 0) 
  { // if nothing in high part, left pad display with eight spaces
    sprintf(buffer, "        %8ld", lo);
  } 
  else 
  {
    sprintf(buffer, "%8ld%08ld", hi, lo);
  }

  module.setDisplayToString(buffer,0b1111111111111111);

}
