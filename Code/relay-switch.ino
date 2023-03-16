/*
  relay-switch

  This code controls the relay, switching 240V supply on/off at user-specified intervals.
  The relay is in a Normally-Open state when powered down.
  
  The following script energises the circuit for "on" milliseconds, then returns relay to Normally-Open (NO) for "off" milliseconds.
  This is repeated until a total ON time, "t", is reached.
*/
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  long on=60000;     // Sets 'on' time interval
  long off=120000;    // Sets 'off' time interval
// test loop function for setting a total 'on' time
  for (long t=0; t<1800000; t=t+on) {    // Sets the loop to run until total ON time (ms) is met - adds the ON time after each iteration (1800000 = 30 mins)
    digitalWrite(LED_BUILTIN, HIGH);    // Turn the relay to NC - Homogeniser turns ON for 'on' seconds
    delay(on);                          // Wait for 'on' milliseconds
    digitalWrite(LED_BUILTIN, LOW);     // turns relay to NO - Homogeniser OFF for 'off' seconds
    delay(off);                         // Wait for 'off' milliseconds
    Serial.println(""); 
   }
  
  exit(0);  // exits the loop() or the code just repeats itself forever
}
