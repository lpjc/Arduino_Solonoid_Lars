// - - - - - - - - - - - - - - - - - - - - - - - - - - - - -   
// - - - - - - - - - May 2021 - lars.design - - - - - - - - -
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// - Shoutout to debounce code from ArduinoGetStarted.com - 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// Morse code writer. Fritzing at: github.com/lpjc/MorseCode_Lars/ 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// Program to do morse code words with a single button. 

const int BUTTON_PIN = 3;   // pin for button    
const int DEBOUNCE_DELAY = 50;   // debounce value
const int minPauseValue = 600; // millis to seperate words
const int dotTimer = 280; // max millis for a dot
const int dashTimer = 550; // max millis for a dash

int lastSteadyState = LOW;       // the previous steady state from the input pin
int lastFlickerableState = LOW;  // the previous bounceable state from the input pin
int currentState;     
String morseChar; // the current reading from the input pin

// all millis() are long, as they often get oo big for int's
unsigned long lastDebounceTime = 0;  
unsigned long PressDuration = 0;
unsigned long PauseDuration = 0;
unsigned long EndPress = 0;
unsigned long StartPress = 0;
unsigned long EndPause = 0;
unsigned long StartPause = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  // If the switch/button changed, due to noise or pressing:
  if (currentState != lastFlickerableState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
    lastFlickerableState = currentState;
  }

  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) { //if debounce delay is calculated and the switch is final

    if(lastSteadyState == HIGH && currentState == LOW){ 
      
      StartPress = millis();
      EndPause = millis();
      PauseDuration = EndPause - StartPause;
      
      if(isNewWord(PauseDuration) == true){
        Serial.println("// new letter // !");
        }
   
     }
      
    else if(lastSteadyState == LOW && currentState == HIGH){ //if debounce delay is calculated and the switch is final
      
      EndPress = millis();
      StartPause = millis();
      PressDuration = EndPress - StartPress;
      morseChar = DotOrDash(PressDuration);
      Serial.print(morseChar);
      }
      
    lastSteadyState = currentState;
  }
}

// ___________ CUSTOM FUNCTIONS ___________

boolean isNewWord(int pauseTime){
  if(pauseTime >minPauseValue){
    return true;
    } else { return false;}
  }

String DotOrDash(int timing){
  String result;
  if (timing < dotTimer){
    result = "dot "; 
    }
  if((timing >dotTimer) && (timing < dashTimer)){
     result = "dash ";
    }
  return result;
  }
