#include <Morse.h>
#include <stdio.h>
int _pin;
  int _dottime;
void MorseMorse(int pin)

{

  pinMode(pin,OUTPUT);

  _pin=pin;

  _dottime=250;

}



void Morsedot()

{

  digitalWrite(_pin,HIGH);

  delay(_dottime);

  digitalWrite(_pin,LOW);

  delay(_dottime);

}



void Morsedash()

{

  digitalWrite(_pin,HIGH);

  delay(_dottime*4);

  digitalWrite(_pin,LOW);

  delay(_dottime);

}



void Morsec_space()

{

  digitalWrite(_pin,LOW);

  delay(_dottime*3);

}



void Morsew_space()

{

  digitalWrite(_pin,LOW);

  delay(_dottime*7);

}

char MORSE[][4]=
{
  {'.','-','*','*'},//A  dot dash  ‘’ ‘’
  {'-','.','.','.'},//B
  {'-','.','-','.'},//C
  {'-','.','.','*'},//D
  {'.','*','*','*'},//E
  {'.','.','-','.'},//F
  {'-','-','.','*'},//G
  {'.','.','.','.'},//H
  {'.','.','*','*'},//I
  {'.','-','-','-'},//J
  {'-','.','-','*'},//K
  {'.','-','.','.'},//L
  {'-','-','*','*'},//M
  {'-','.','*','*'},//N
  {'-','-','-','*'},//O
  {'.','-','-','.'},//P
  {'-','-','.','-'},//Q
  {'.','-','.','*'},//R
  {'.','.','.','*'},//S
  {'-','*','*','*'},//T
  {'.','.','-','*'},//U
  {'.','.','.','-'},//V
  {'.','-','-','*'},//W
  {'-','.','.','-'},//X
  {'-','.','-','-'},//Y
  {'-','-','.','.'},//Z
};
void setup() 
{
   Serial.begin(9600);
   MorseMorse(13);
}
String str="";
String text="";
int k=0;
int i=0;
int n=0;
int x;
void loop() 
{ 
  int i;
  while(Serial.available()>0)
      {
        str +=char(Serial.read());  
        n++;
      }
  for(i=0;str[i]!='\n';i++)
  {
      if(str[i]>=97 and str[i]<=122)
      {
        for(x=0;x<4;x++,k++)
         text +=char(MORSE[int(str[i]-97)][x]);
         if(str[i+1]>=97 and str[i+1]<=122)
         {
            text[k]=' ';
            k++;
         }
         else 
         {
            text[k]=' ';k++;
            text[k]=' ';k++;
            text[k]=' ';k++;
            text[k]=' ';k++;
         }
      }


    
  }
  for(i=0;i<k;i++)
  {if(text[i]=='.' )
     Morsedot(); 
  else if(text[i]=='-')
     Morsedash();
  else if(text[i]==' ')
     Morsec_space();
  }
  
  
    
}
