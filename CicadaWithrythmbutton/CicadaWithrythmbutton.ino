int solenoidPin = 3; //pin for controlling gate
int noPause = 50;
int pause;
int len = 0;
int ch;
int rythm[];
int i = 0;

int activateButtonState = 0;  
int activateButtonPin = A0;

int rythmButtonState = 0
int rythmButtonPin = A1;

unsigned long StartPress = 0;
unsigned long NextPress = 0;



void tap()
{
        digitalWrite(solenoidPin, HIGH);
        delay(noPause);                   
        digitalWrite(solenoidPin, LOW);
}

void setup() {
  Serial.begin(9600);  
  pinMode(solenoidPin, OUTPUT);
  pinMode(activateButtonPin, INPUT);
  pinMode(rythmButtonPin, INPUT);
}
 
void loop() {
  activateButtonState = digitalRead(buttonPin);
  rythmButtonState = digitalRead(buttonPin);

  if (activateButtonState == HIGH){
    
    StartPress = millis();

    if (rythmButtonState == HIGH){
      if(i == 0){
        rythm[i] = (millis() - StartPress);
        NextPress = millis();
        i++;
        }
      rythm[i] = (millis() - NextPress);
      }
    
    }else{
      tap();
    }
   
}
