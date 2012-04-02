/* Blink
 * Turns on an LID for one second, then off for one second,
 * repeatedly.
 */
 
int ledPin = 9;     // LED connected to digital pin 9

// The setup() method runs once, when the sketch starts
void setup() {
  pinMode(ledPin, OUTPUT);
}

// the loop() method runs over and over again,
// as long as the Arduino has power
void loop() {
  
  for(int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(4);
  }
  
  for(int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(4);
}
