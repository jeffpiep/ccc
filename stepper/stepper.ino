
#define enPin 8 // enable pin
#define stpPin 2  //connect pin 13 to step
#define dirPin 5  // connect pin 12 to dir

boolean a = false; // direction counter
int pw = 1; // pulse width to CNC shield
int pri = 3; // pulse rep interval (determines speed)
int num = 40;

void setup() 
{                
  pinMode(enPin, OUTPUT);
  pinMode(stpPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(stpPin, LOW);
  digitalWrite(dirPin, LOW);
  digitalWrite(enPin, LOW);
}

void loop() 
{
  // alternate directions with counter a
  if (a)
  {
    digitalWrite(dirPin,HIGH);
  }
  else
  {
    digitalWrite(dirPin,LOW);
  }
  
  for (int b=0; b<num; b++)
  {
    stepMotor();
    delay(pri);
  }
  a = !a;
}

void stepMotor()
{
  digitalWrite(stpPin, HIGH);
  delay(pw);
  digitalWrite(stpPin, LOW);
}

