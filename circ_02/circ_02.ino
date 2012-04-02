/*
 * circ_02
 * 8 LED Fun
 * Multiple LEDs
 */
 
// LED pin variables
// An array to hold the pin each LID is connected to
// (i.e. LED #0 is connected to pin 2
int ledPins[] = { 2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // oneAfterAnotherNoLoop();
  
  // oneAfterAnotherLoop();
  
  // oneOnAtATime();
  
  // inAndOut();
  
  progressBar();
}

/*
 * oneAfterAnotherNoLoop() - will light one LED then delay for delayTime the light
 * the next LED until all LEDs are on.  It will then turn them off one after
 * another.
 *
 * This does it without using a loop which makes for a lot of typing.
 */
 void oneAfterAnotherNoLoop() {
   int delayTime = 50;
   
   // Turn each LED on
   
   digitalWrite(ledPins[0], HIGH);
   delay(delayTime);
   digitalWrite(ledPins[1], HIGH);
   delay(delayTime);
   digitalWrite(ledPins[2], HIGH);
   delay(delayTime);
   digitalWrite(ledPins[3], HIGH);
   delay(delayTime);
   digitalWrite(ledPins[4], HIGH);
   delay(delayTime);
   digitalWrite(ledPins[5], HIGH);
   delay(delayTime);
   digitalWrite(ledPins[6], HIGH);
   delay(delayTime);
   digitalWrite(ledPins[7], HIGH);
   delay(delayTime);
   
   // Turn each LED off
   
   digitalWrite(ledPins[7], LOW);
   delay(delayTime);
   digitalWrite(ledPins[6], LOW);
   delay(delayTime);
   digitalWrite(ledPins[5], LOW);
   delay(delayTime);
   digitalWrite(ledPins[4], LOW);
   delay(delayTime);
   digitalWrite(ledPins[3], LOW);
   delay(delayTime);
   digitalWrite(ledPins[2], LOW);
   delay(delayTime);
   digitalWrite(ledPins[1], LOW);
   delay(delayTime);
   digitalWrite(ledPins[0], LOW);
   delay(delayTime);
 }
 
/*
 * oneAfterAnotherLoop() - will light one LED then delay for delayTime the light
 * the next LED until all LEDs are on.  It will then turn them off one after
 * another.
 *
 * This is just like oneAfterAnotherNoLoop except it uses a loop
 */
void oneAfterAnotherLoop() {

  int delayTime = 50;
   
   // Turn each LED on
   for(int i = 0; i < 8; i++) {
     digitalWrite(ledPins[i], HIGH);
     delay(delayTime);
   }
   
   // Turn each LED off
   for(int i = 7; i >= 0; i--) {
     digitalWrite(ledPins[i], LOW);
     delay(delayTime);
   }
}

/*
 * oneOnAtATime() - turns each LED on and off, one at a time
 */
void oneOnAtATime() {
  
  int delayTime = 100;
  
  for(int i = 0; i < 8; i++) {
    turnPinOnAndOff(ledPins[i], delayTime);
  }
  
  for(int i = 6; i > 0; i--) {
    turnPinOnAndOff(ledPins[i], delayTime);
  }
}

/*
 * turnPinOnAndOff(int pin, int delayTime) - turns a pin on and off
 */
void turnPinOnAndOff(int pin, int delayTime) {
  
  digitalWrite(pin, HIGH);
  delay(delayTime);
  digitalWrite(pin, LOW);
  delay(delayTime);
}

/*
 * inAndOut() - This will turn on the two middle LEDs then the next two out
 * making an in and out look
 */
void inAndOut() {

  // the time (in milliseconds) to pause between LEDs
  int delayTime = 200; 
  
  // runs the LEDs out from the middle
  for(int i = 0; i < 4; i++) {
    
    int offLED = i - 1;
    if (i == 0) {
      offLED = 3;
    }
  
    int onLED1 = 3 - i;
    int onLED2 = 4 + i;
    int offLED1 = 3 - offLED;
    int offLED2 = 4 + offLED;
     
    digitalWrite(ledPins[onLED1], HIGH);
    digitalWrite(ledPins[onLED2], HIGH);  
    digitalWrite(ledPins[offLED1], LOW);
    digitalWrite(ledPins[offLED2], LOW);
    
    if (i != 3) {
      delay(delayTime);
    }
  }
  
  //runs the LEDs into the middle
  for(int i = 3; i >= 0; i--){
    int offLED = i + 1;
    if(i == 3) {
      offLED = 0;
    }            
                 
    int onLED1 = 3 - i;
    int onLED2 = 4 + i;
    int offLED1 = 3 - offLED;
    int offLED2 = 4 + offLED;
    
    digitalWrite(ledPins[onLED1], HIGH);
    digitalWrite(ledPins[onLED2], HIGH);    
    digitalWrite(ledPins[offLED1], LOW);    
    digitalWrite(ledPins[offLED2], LOW);        
    
    if (i != 0) {
      delay(delayTime);
    }
  }
}

/*
 * progressBar() - show progress by moving one turned-off LED across the row
 */
void progressBar() {
  
  int delayTime = 100;
  
  for (int i = 0; i < 8; i++) {
    turnOnAllBut(ledPins, ledPins[i]);
    delay(delayTime);
  }
}

/*
 * turnOnAllBut(int pin) - turns on all pins except one
 */
void turnOnAllBut(int *pins, int pin) {

  int count = sizeof(pins) / sizeof(int); 
  
  // Turn on pins
  for(int i = 0; i < 8; i++) {
    if (pins[i] != pin) {
      digitalWrite(pins[i], HIGH);
    }
  }
  
  // Turn off pin
  for(int i = 0; i < 8; i++) {
    if (pins[i] == pin) {
      digitalWrite(pins[i], LOW);
    }
  }
}
