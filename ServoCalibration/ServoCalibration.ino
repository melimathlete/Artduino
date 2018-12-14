#include <Servo.h>
Servo servo1;

void setup() {
  // put your setup code here, to run once:
servo1.attach(11);
Serial.begin(9600);
}

void calibrate(int pos){
  servo1.write(pos);
  Serial.println("position: " + pos);
}
void loop() {
  // put your main code here, to run repeatedly:
calibrate(130);
delay(1000);
calibrate(150);
delay(1000);
}
