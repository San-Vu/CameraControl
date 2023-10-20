String inputString = "";         // a string to hold incoming data
bool stringComplete = false;     // whether the string is complete

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);            // initialize serial communication:
  inputString.reserve(200);      // reserve 200 bytes for the inputString

}

void loop() {
  if (stringComplete) {
    Serial.println(inputString);   // print the string when a newline arrives:
    inputString = "";              // clear the string:
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();   // get the new byte:
    inputString += inChar;               // add it to the inputString:
    if (inChar == '\n') {                // if the incoming character is a newline, set a flag so the main loop can process it:
      stringComplete = true;
    }
  }
}