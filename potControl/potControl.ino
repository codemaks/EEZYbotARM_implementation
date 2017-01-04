// potControl
// Wed Jan  4 22:23:06 GMT 2017
// by Maks G <http://github.com/codemaks> 
// Controls a robotic arm of 4 servos using 4 potentiometers


#include <Servo.h> 

//create servo objects (maximum of 8 can be used)
Servo baseservo;
Servo liftservo;
Servo pushservo;
Servo clawservo;

// Analog pins to connect potentiometers to.
const int baseInPin = A0; 
const int liftInPin = A1;
const int pushInPin = A2;
const int clawInPin = A3;

// Variables to read analog voltages (0-255)
int baseValue = 0;
int liftValue = 0;
int pushValue = 0;
int clawValue = 0;
// Variables to map to 0 degrees to 180 degree range
int baseOutput = 0;
int liftOutput = 0;
int pushOutput = 0;
int clawOutput = 0;


void setup()
{
  baseservo.attach(3);
  liftservo.attach(5);
  pushservo.attach(6);
  clawservo.attach(9);
  Serial.begin(9600);
} 


void loop()
{
// read the analog in value:
  baseValue = analogRead(baseInPin);
  liftValue = analogRead(liftInPin);
  pushValue = analogRead(pushInPin);
  clawValue = analogRead(clawInPin);
  // map it to the range of the analog out:
  baseOutput = map(baseValue, 0, 1023, 0, 180);
  liftOutput = map(liftValue, 0, 1023, 0, 180);
  pushOutput = map(pushValue, 0, 1023, 0, 180);
  clawOutput = map(clawValue, 0, 1023, 0, 180);

  Serial.print("outputs = ");
  Serial.print(baseOutput); Serial.print("\t ");
  Serial.print(liftOutput); Serial.print("\t ");
  Serial.print(pushOutput); Serial.print("\t ");
  Serial.println(clawOutput);
  baseservo.write(baseOutput);
  liftservo.write(liftOutput);
  pushservo.write(pushOutput);
  clawservo.write(clawOutput);
  delay(15);   // waits 15ms for the servo to reach the position 
}
