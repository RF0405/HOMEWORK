void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  Serial.begin(9600);
}
int income=0;
void loop()
{
  if(Serial.available()>0)
    {
      income=Serial.read();
        switch(income)
        {
          case '0':
              {
              digitalWrite(0,LOW);
              digitalWrite(1,LOW);
              digitalWrite(2,LOW);
              digitalWrite(3,LOW);
              digitalWrite(4,LOW); 
              }
            break;
          case '1':
              {
              digitalWrite(0,HIGH);
              digitalWrite(1,LOW);
              digitalWrite(2,LOW);
              digitalWrite(3,LOW);
              digitalWrite(4,LOW);
              }
            break;
          case '2':
              {
              digitalWrite(0,LOW);
              digitalWrite(1,HIGH);
              digitalWrite(2,LOW);
              digitalWrite(3,LOW);
              digitalWrite(4,LOW);
              }
             break;
            case '3':
              {
              digitalWrite(0,HIGH);
              digitalWrite(1,HIGH);
              digitalWrite(2,LOW);
              digitalWrite(3,LOW);
              digitalWrite(4,LOW);
              }
              break;
            case '4':
              {
              digitalWrite(0,LOW);
              digitalWrite(1,LOW);
              digitalWrite(2,HIGH);
              digitalWrite(3,LOW);
              digitalWrite(4,LOW);
              }
              break;
            case '5':
              {
              digitalWrite(0,HIGH);
              digitalWrite(1,LOW);
              digitalWrite(2,HIGH);
              digitalWrite(3,LOW);
              digitalWrite(4,LOW);
              }
             break;
            case '6':
              {
              digitalWrite(0,LOW);
              digitalWrite(1,HIGH);
              digitalWrite(2,HIGH);
              digitalWrite(3,LOW);
              digitalWrite(4,LOW);
              }
             break;
            case '7':
              {
              digitalWrite(0,HIGH);
              digitalWrite(1,HIGH);
              digitalWrite(2,HIGH);
              digitalWrite(3,LOW);
              digitalWrite(4,LOW);
             }
             break;

            default:
              break;
           }
        }
       digitalWrite(4,HIGH);
      
}
