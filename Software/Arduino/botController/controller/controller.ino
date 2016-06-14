String message; //string that stores the incoming message

void setup()
{
  Serial.begin(9600); //set baud rate for bluetooth communitcation
  
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
}

void loop()
{
  
  if (Serial.available() > 0) {
  int inByte = Serial.read();
    // do something different depending on the character received.
    // The switch statement expects single number values for each case;
    // in this exmaple, though, you're using single quotes to tell
    // the controller to get the ASCII value for the character.  For
    // example 'a' = 97, 'b' = 98, and so forth:

    switch (inByte) {
      case 'a':
        // right motor forward
        digitalWrite(12, HIGH); // Establishes forward direction of Channel A
        digitalWrite(9, LOW);   // Disengage the Brake for Channel A
        analogWrite(3, 200);    // Spins the motor on Channel A 
        break;
      
      case 'b':
        // left motor forward
        digitalWrite(13, LOW);  //Establishes backward direction of Channel B
        digitalWrite(8, LOW);   //Disengage the Brake for Channel B
        analogWrite(11, 200);   //Spins the motor on Channel B at full speedd
        break;
      
      case 'c':
        // power down right motor
        analogWrite(3, 0);   // set power of channel A to 0
        break;
      
      case 'd':
        // power down left motor
        analogWrite(11, 0);    // set power of channel B to 0
        break;
      
      case 'e':
        // right motor backwards
        digitalWrite(12, LOW);  // Establishes backward direction of Channel A
        digitalWrite(9, LOW);   // Disengage the Brake for Channel A
        analogWrite(3, 200);    // Spins the motor on Channel A 
        break;
      
      case 'f':
        // left motor bacwards
        digitalWrite(13, HIGH);  // Establishes backward direction of Channel B
        digitalWrite(8, LOW);    // Disengage the Brake for Channel B
        analogWrite(11, 200);    // Spins the motor on Channel B
        break;

        
      default:
        ;
    }
  }
}

    
