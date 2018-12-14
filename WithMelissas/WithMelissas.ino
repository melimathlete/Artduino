 
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

const int downpos = 160;
const int uppos = 140;
int currentpos = 0;

int midiNotes[]={41,43,45,57,48,50,52,53,55,57,59,60,62,64,66,67,69,71,72,74,76,77,79,81,83,84};
int stepperNotes[]={0,20,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500,520};
char noteNames[]={'F2','G2','A2','B2','C3','D3','E3','F3','G3','A3','B3','C4','D4','E4','F4','G4','A4','B4','C5','D5','E5','F5','G5','A5','B5','C6'};
//
// create the stepper motor objects
//
SpeedyStepper stepperX;




void setup()
{
  //
  // setup the LED pin and enable print statements
  //
  finger1.attach(MOTOR_Y_STEP_PIN);
  pinMode(LED_PIN, OUTPUT);
  pinMode(STEPPERS_ENABLE_PIN, OUTPUT);       // be sure to do this
  Serial.begin(9600);


  //
  // connect and configure the stepper motor to there IO pins
  //
  stepperX.connectToPins(MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
  //  stepperY.connectToPins(MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);


  //
  // enable the stepper motors
  //
  digitalWrite(STEPPERS_ENABLE_PIN, LOW);     // be sure to do this
}




void loop()
{
  //60 is C5
  //base note log12 to get note in each octave, thats is each base note plus 20*7=140 times the number of octaves
  //maybe make a lookup table
  //(notenum-41)mod12 //0 is F
  //start at 41 and put everything in a table
  //each note gets a location starting at 0 and going up by 20
  int notevalues[3][26]
  for (j=0; j<7; j++)
    notevalues[0][j]=;
  
  Serial.println("Running just the X stepper");
  
  stepperX.setStepsPerMillimeter(40);
  stepperX.setSpeedInMillimetersPerSecond(1580);
  stepperX.setAccelerationInMillimetersPerSecondPerSecond(1580);
  
  movefinger(30, 180);
  movefinger(0, 360);
  movefinger(50, 180);
  movefinger(70, 180);
  movefinger(90, 180);
  movefinger(110, 180);
  movefinger(130, 180);
  movefinger(200, 180);
  finger1.detach();
  stepperX.moveToPositionInMillimeters(0);
  while (true);


}

void timeconvert(int seconds)
{
  ms=seconds/1000;
  return ms;
}

void noteconvert(int notenum)
{

}

void movefinger(int keyspot, int delaytime)
{
  //
  // set the speed and acceleration rates for the stepper motor
  //
  retract(finger1, 200);
  stepperX.moveToPositionInMillimeters(keyspot);

  //
  // Rotate the motor in the forward direction one revolution (200 steps).
  // This function call will not return until the motion is complete.
  //

  play(finger1, delaytime);
  
  //  currentpos = keyspot;


}
void play(Servo finger, int notetime) {
  int time_play = millis();
  finger.write(downpos);              // tell servo to go to position in variable 'pos'
  while (millis() < time_play + notetime + 50) {

  }
}
void retract(Servo finger, int traveltime) {
  int time_retract = millis();
  finger.write(uppos);              // tell servo to go to position in variable 'pos'
  while (millis() < time_retract + traveltime) {
    // waits traveltime for the servo to reach the position
  }
}
