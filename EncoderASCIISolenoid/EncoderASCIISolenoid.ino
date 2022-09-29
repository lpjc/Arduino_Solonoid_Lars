int solenoidPin = 3;  // pin for controlling gate
int noPause = 50;
int pause;
int len = 0;
int ch;
String code = "";

// analog input for mirkofon
// digital input /HIGH LOW/ KY037

//knock sensor; use high resisters to defeat noise

//int ascTest1 = 119; // use Serial.write to convert int into string
//int ascTest2 = 'm'; // use Serial.print to convert to int

void String2Ascii()
{
  len = code.length();
  for (int i = 0; i < len; i++)
    {
      ch = code.charAt(i); 
      Serial.write(ch);
      Serial.println(ch);
      pause = ch*10;
      if (ch>0){
        digitalWrite(solenoidPin, HIGH);
        delay(noPause);  
          //lightIn = analogRead(A3); test 
         // Serial.println(lightIn);                      
        digitalWrite(solenoidPin, LOW);
        delay(pause);   
      }
    }
}

void setup() {
  //pinMode(solenoidPin1, OUTPUT);
  Serial.begin(9600);
  pinMode(solenoidPin, OUTPUT);
  
}
 
void loop() {
  while (Serial.available())
  {
   code = Serial.readString();
   String2Ascii();
  }    
}
