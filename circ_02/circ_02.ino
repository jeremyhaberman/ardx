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
  oneAfterAnotherNoLoop();
  
  // oneAfterAnotherLoop();
  
  // oneOnAtATime();
  
  // inAndOut();
}

/*
 * oneAfterAnotherNoLoop() - will lige one LED then delay for delayTime the light
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