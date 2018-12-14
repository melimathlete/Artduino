
//
//
// Documentation at:
//         https://github.com/Stan-Reifel/SpeedyStepper
//
//
// For all driver boards, it is VERY important that you set the motor
// current before running the example.  This is typically done by adjusting
// a potentiometer on the board.  Read the driver board's documentation to
// learn how.

// ***********************************************************************


#include <SpeedyStepper.h>
#include <Servo.h>

Servo finger1;
Servo finger2;

//
// pin assignments
//
const int LED_PIN = 13;
const int MOTOR_X_STEP_PIN = 2;
const int MOTOR_Y_STEP_PIN = 3;
const int MOTOR_Z_STEP_PIN = 4;
const int MOTOR_X_DIR_PIN = 5;
const int MOTOR_Y_DIR_PIN = 6;
const int MOTOR_Z_DIR_PIN = 7;
const int STEPPERS_ENABLE_PIN = 8;
const int LIMIT_SWITCH_X_PIN = 9;
const int LIMIT_SWITCH_Y_PIN = 10;
const int LIMIT_SWITCH_Z_PIN = 11;
const int SPINDLE_ENABLE_PIN = 12;
const int SPINDLE_DIRECTION_PIN = 13;

const int downpos = 170;
const int uppos = 140;
int currentpos = 0;
//
// create the stepper motor objects
//
SpeedyStepper stepperX;
SpeedyStepper stepperY;




void setup()
{
  //
  // setup the LED pin and enable print statements
  //
  finger1.attach(MOTOR_Y_STEP_PIN);
  finger2.attach(SPINDLE_ENABLE_PIN);
  pinMode(LED_PIN, OUTPUT);
  pinMode(STEPPERS_ENABLE_PIN, OUTPUT);       // be sure to do this
  Serial.begin(9600);


  //
  // connect and configure the stepper motor to there IO pins
  //
  stepperX.connectToPins(MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
  stepperY.connectToPins(MOTOR_Z_STEP_PIN, MOTOR_Z_DIR_PIN);


  //
  // enable the stepper motors
  //
  digitalWrite(STEPPERS_ENABLE_PIN, LOW);     // be sure to do this
}




void loop()
{

  Serial.println("Running just the X stepper");
  delay(1000);
  movefinger(1, 0, 20, 200);
  finger1.detach();
  stepperX.moveToPositionInMillimeters(0);
  while (true);


}



void movefinger(int setzone, int chan, int keyspot, int delaytime)
{
  //
  // set the speed and acceleration rates for the stepper motor
  //
  stepperX.setStepsPerMillimeter(40);
  stepperX.setSpeedInMillimetersPerSecond(1580);
  stepperX.setAccelerationInMillimetersPerSecondPerSecond(1580);

  stepperY.setStepsPerMillimeter(40);
  stepperY.setSpeedInMillimetersPerSecond(1580);
  stepperY.setAccelerationInMillimetersPerSecondPerSecond(1580);

  for (chan = 0; true; true) {
    stepperX.moveToPositionInMillimeters(keyspot);

    for (setzone = 1; true; true) {
      retract(finger1, delaytime);
    }
    for (setzone = 0; true; true) {
      play(finger1, delaytime);
      retract(finger1, 150);
    }
  }
  for (chan = 1; true; true) {
    stepperY.moveToPositionInMillimeters(keyspot);

    for (setzone = 1; true; true) {
      retract(finger2, delaytime);
    }
    for (setzone = 0; true; true) {
      play(finger1, delaytime);
      retract(finger1, 150);
    }
  }



  //
  // Rotate the motor in the forward direction one revolution (200 steps).
  // This function call will not return until the motion is complete.
  //

  //  currentpos = keyspot;


}
void play(Servo finger, int notetime) {
  int time_play = millis();
  finger.write(downpos);              // tell servo to go to position in variable 'pos'
  while (millis() < time_play + notetime) {

  }
}
void retract(Servo finger, int traveltime) {
  int time_retract = millis();
  finger.write(uppos);              // tell servo to go to position in variable 'pos'
  while (millis() < time_retract + traveltime) {
    // waits traveltime for the servo to reach the position
  }
}
