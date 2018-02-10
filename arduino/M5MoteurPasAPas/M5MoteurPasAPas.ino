//definition des broches
const int A=3;
const int B=4;
const int C=5;
const int D=6;

//pour le tour de boucle
int c=0;

void setup()
{
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    
    c=0;
}

void loop()
{
  
     faireMarcherUn(c);
     delay(500);
     c++;
     if(c==4)
       c=0;
}

void faireMarcherUn(int n)
{
  
  toutArreter();
  switch (n)
  {
    case 0:
      digitalWrite(A,1);
    break;
    case 1:
      digitalWrite(C,1);
    break;
    case 2:
      digitalWrite(B,1);
    break;
    case 3:
      digitalWrite(D,1);
    break;
  }
}

void toutArreter()
{
  digitalWrite(A,0);
  digitalWrite(B,0);
  digitalWrite(C,0);
  digitalWrite(D,0);
}
