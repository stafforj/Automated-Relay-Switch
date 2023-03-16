/*
  Homogeniser

  This code controls the relay, switching 240V supply off/on at user-specified intervals.
  The relay is in a Normally-Open state when powered down.
  
  The following script turns relay to Normally-Closed (NC) for X seconds, then returns relay to Normally-Open (NO) for Y seconds, repeatedly.
*/
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  long on=60000;     // Sets 'on' time
  long off=120000;    // Sets 'off' time
// test loop function for setting a total 'high' time
  for (long t=0; t<1800000; t=t+on) {    // Sets the loop to run until total ON time (ms) is met - adds the ON time after each iteration (1800000 = 30 mins)
    digitalWrite(LED_BUILTIN, HIGH);    // Turn the relay to NC - Homogeniser turns ON for 'on' seconds
    delay(on);                          // Wait for 'on' milliseconds
    digitalWrite(LED_BUILTIN, LOW);     // turns relay to NO - Homogeniser OFF for 'off' seconds
    delay(off);                         // Wait for 'off' milliseconds
    Serial.println(""); 
   }
  
  exit(0);  // exits the loop() or the code just repeats itself forever
}


// the loop function runs over and over again forever
//void loop() {
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the relay to NC - Homogeniser turns ON for X seconds (red LED turns on)
//  delay(120000);                       // wait for X milliseconds
//  digitalWrite(LED_BUILTIN, LOW);    // turn the relay to NO - Homogeniser turns OFF for Y seconds (red LED turns off)
//  delay(180000);                       // wait for Y milliseconds
//}
