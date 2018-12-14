

#include <Servo.h>


Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int count = 0; 

void setup() {
  // put your setup code here, to run once:
  myservo.attach(11);

}

void loop() {
  // put your main code here, to run repeatedly:
//Jingle Bells
//4 4 2 | 4 4 2 | 4 4 4 /8 8 | 2 /2|
//180 msecond per eighth note

//quarter
  for(pos=0; pos<=90; pos += 10){
      myservo.write(pos);
      delay(10);
  }
  delay(180);
  for(pos=90; pos>=0; pos-=10){
          myservo.write(pos);
      delay(10);
  }

  //quarter
    for(pos=0; pos<=90; pos += 10){
      myservo.write(pos);
      delay(10);
  }
  delay(180);
  for(pos=90; pos>=0; pos-=10){
          myservo.write(pos);
      delay(10);
  }

  //half
    for(pos=0; pos<=90; pos += 10){
      myservo.write(pos);
      delay(10);
  }
  delay(180*2);
  for(pos=90; pos>=0; pos-=10){
          myservo.write(pos);
      delay(10);
  }



}
