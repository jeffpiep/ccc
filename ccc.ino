// adapted from sketch found at http://forum.arduino.cc/index.php?topic=133894.0

// define pins to match the CNC shield http://blog.protoneer.co.nz/arduino-cnc-shield/
#define enPin 8 // enable pin
#define stpPin 2  //connect pin 2 to step
#define dirPin 5  // connect pin 5 to dir

boolean a = false; // direction counter
int pw = 1; // pulse width to CNC shield
int pri = 3; // pulse rep interval (determines speed)
int num = 40; // number of steps in a move

void setup() 
{                
  pinMode(enPin, OUTPUT);
  pinMode(stpPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(stpPin, LOW);
  digitalWrite(dirPin, LOW);
  digitalWrite(enPin, LOW); // enable is really enable-bar
}

void loop() 
{
  // alternate directions with counter a
  if (a) {
    digitalWrite(dirPin,HIGH);
  }
  else {
    digitalWrite(dirPin,LOW);
  }

  for (int b=0; b<num; b++) {
    // step motor
    digitalWrite(stpPin, HIGH);
    delay(pw);
    digitalWrite(stpPin, LOW);
    // wait PRI length to set speed
    delay(pri);
  }
  // reverse direction next go around
  a = !a;
}



