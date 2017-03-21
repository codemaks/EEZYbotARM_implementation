// potControl
// Wed Jan  4 22:23:06 GMT 2017
// by Maks G <http://github.com/codemaks> 
// Controls a robotic arm of 4 servos using 4 potentiometers


#include <Servo.h> 

//create servo objects (maximum of 8 can be used)
Servo baseServo;
Servo liftServo;
Servo pushServo;
Servo clawServo;

// Analog pins to connect potentiometers to.
const int baseInPin = A0; 
const int liftInPin = A1;
const int pushInPin = A2;
const int clawInPin = A3;

// Variables to map to 0 degrees to 180 degree range
int baseDegrees = 0;
int liftDegrees = 0;
int pushDegrees = 0;
int clawDegrees = 0;


void setup()
{
  baseServo.attach(3);
  liftServo.attach(5);
  pushServo.attach(6);
  clawServo.attach(9);
  Serial.begin(9600);
} 

void loop()
{
  // read analog values and map it to the range of 0-180 degrees
  // TODO: why is it 1023, if arduino's precision is 8bit=255?
  baseDegrees = map(analogRead(baseInPin), 0, 1023, 0, 180);
  liftDegrees = map(analogRead(liftInPin), 0, 1023, 0, 180);
  pushDegrees = map(analogRead(pushInPin), 0, 1023, 0, 180);
  clawDegrees = map(analogRead(clawInPin), 0, 1023, 0, 180);
  // serialPrintServoValues(baseDegrees, liftDegrees, pushDegrees, clawDegrees);
  baseServo.write(baseDegrees);
  liftServo.write(liftDegrees);
  pushServo.write(pushDegrees);
  clawServo.write(clawDegrees);
  delay(15);   // waits 15ms for the servo to reach the position 
}

void serialPrintServoValues(int base, int lift, int push, int claw)
{
  Serial.print("outputs = ");
  Serial.print(base); Serial.print("\t ");
  Serial.print(lift); Serial.print("\t ");
  Serial.print(push); Serial.print("\t ");
  Serial.println(claw);
}
