
#include <Servo.h>


Servo servo1;  // create servo object to control a servo
Servo servo2;
int half = 800;
int quarter = 400;
int eighth = 200;
int travel = 100;

int notedistance = 20;
int pitchA = 30;
int pitchB = 50;
int pitchC = 70;
int pitchD = 90;
int pitchE = 110;
int pitchF = 130;
int pitchG = 150;

// twelve servo objects can be created on most boards

int downPos = 150;    // Servo poition required to hit key
int upPos = 130;      //Servo position when not hitting key
int servo1pin = 11;
int servo2pin = 12;

void setup() {
  // put your setup code here, to run once:
  servo1.attach(servo1pin);
  servo2.attach(servo2pin);
  Serial.begin(9600);//serial rate
}
void play(Servo finger, int notetime) {
  int time_play = millis();
  finger.write(downPos);              // tell servo to go to position in variable 'pos'
  while (millis() < time_play + notetime - travel){
    
  }
}
void retract(Servo finger, Servo belt, int traveltime, int note) {
  int time_retract = millis();
  finger.write(upPos);              // tell servo to go to position in variable 'pos'
  belt.write(note);
  while(millis() < time_retract + traveltime){
    // waits traveltime for the servo to reach the position
  }
}

void quit(Servo finger) {
  finger.detach();
}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(5000);
  retract(servo1, servo2, travel, pitchA);
  play(servo1, quarter);
  retract(servo1, servo2, travel, pitchA);
  play(servo1, quarter);
  retract(servo1, servo2, travel, pitchA);
  play(servo1, half);
  
  retract(servo1, servo2, travel, pitchA);
  play(servo1, quarter);
  retract(servo1, servo2, travel, pitchA);
  play(servo1, quarter);
  retract(servo1, servo2, travel, pitchA);
  play(servo1, half);

  
  retract(servo1, servo2, travel, pitchA);
  play(servo1, quarter);
  retract(servo1, servo2, travel, pitchC);
  play(servo1, quarter);
  retract(servo1, servo2, travel, pitchF);
  play(servo1, half);

  
  retract(servo1, servo2, travel, pitchG);
  play(servo1, eighth);
  retract(servo1, servo2, travel, pitchA);
  play(servo1, quarter);
  
  
  //Serial.println("Done");
}
