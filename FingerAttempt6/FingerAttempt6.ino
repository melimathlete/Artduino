
#include <Servo.h>


Servo servo1;  // create servo object to control a servo
Servo servo2;
int half = 800;
int quarter = 400;
int eighth = 200;
int travel = 100;
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
void play(Servo finger, int delaytime) {
  finger.write(downPos);              // tell servo to go to position in variable 'pos'
  delay(delaytime-travel);  // waits delaytime for the servo to reach the position
}
void retract(Servo finger, int delaytime) {
  finger.write(upPos);              // tell servo to go to position in variable 'pos'
  delay(delaytime);// waits 15ms for the servo to reach the position
}

void quit(Servo finger) {
  finger.detach();
}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(5000);
  play(servo1, quarter);
  retract(servo1, travel);
  play(servo1, quarter);
  retract(servo1, travel);
  play(servo1, quarter);
  retract(servo1, travel);
  retract(servo1, quarter);
  
  //Serial.println("Done");
}
