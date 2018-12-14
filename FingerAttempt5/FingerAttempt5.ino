
#include <Servo.h>


Servo servo1;  // create servo object to control a servo
Servo servo2;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int pos2 = 0;
int count = 0;
int servo1pin=11;
int servo2pin=12;
void setup() {
  // put your setup code here, to run once:
  servo1.attach(servo1pin);
  servo2.attach(servo2pin);
  Serial.begin(9600);//serial rate
}
void playing(int delaytime, Servo finger) {
  Serial.println("hello");
    finger.write(150);              // tell servo to go to position in variable 'pos'
    Serial.println("position: " + pos);
    delay(15);  // waits 15ms for the servo to reach the position
  }
  finger.detach();
  Serial.println("SAD");
  //count++ ;
  //Serial.print(count);
  delay(delaytime);
  finger.attach(11);
    finger.write(130);              // tell servo to go to position in variable 'pos'
    delay(15);// waits 15ms for the servo to reach the position
    //if (pos = 90) {
    //count++ ;
    //Serial.print(count);
    //}
  }
//  servo1.detach();
//  Serial.println("Detach");
//  count++ ;
//  Serial.print(count);
//  delay(delaytime);
//  servo1.attach(11);
}
void rest(int delaytime, int pin1) {
  servo1.detach();
  delay(delaytime + 180);
  servo1.attach(pin1);
}
void quit() {
  servo1.detach();
}

void loop() {
  // put your main code here, to run repeatedly:
  //delay(5000);
  playing(540,servo1);


  //Serial.println("Done");
}
