

#include <Servo.h>

class Eighth{
  Servo finger1;  // create servo object to control a servo
  // twelve servo objects can be created on most boards
  const byte pin;
  int pos = 0;    // variable to store the servo position
  int count = 0;

  void setup() {
    // put your setup code here, to run once:
    finger1.attach(pin);

  }

  void loop() {
    for (pos = 0; pos <= 90; pos += 10) {
      finger1.write(pos);
      delay(10);
    }
    delay(90);
    for (pos = 90; pos >= 0; pos -= 10) {
      finger1.write(pos);
      delay(10);
    }
  }
};

class Quarter {

  Servo finger1;  // create servo object to control a servo
  // twelve servo objects can be created on most boards
  const byte pin;
  int pos = 0;    // variable to store the servo position
  int count = 0;

  void setup() {
    // put your setup code here, to run once:
    finger1.attach(pin);

  }

  void loop() {
    for (pos = 0; pos <= 90; pos += 10) {
      finger1.write(pos);
      delay(10);
    }
    delay(180);
    for (pos = 90; pos >= 0; pos -= 10) {
      finger1.write(pos);
      delay(10);
    }
  }
};

class Half{
  Servo finger1;  // create servo object to control a servo
  // twelve servo objects can be created on most boards
  const byte pin;
  int pos = 0;    // variable to store the servo position
  int count = 0;

  void setup() {
    // put your setup code here, to run once:
    finger1.attach(pin);

  }

  void loop() {
    for (pos = 0; pos <= 90; pos += 10) {
      finger1.write(pos);
      delay(10);
    }
    delay(180 * 2);
    for (pos = 90; pos >= 0; pos -= 10) {
      finger1.write(pos);
      delay(10);
    }
  }
};

class Whole{
  Servo finger1;  // create servo object to control a servo
  // twelve servo objects can be created on most boards
  const byte pin;
  int pos = 0;    // variable to store the servo position
  int count = 0;

  void setup() {
    // put your setup code here, to run once:
    finger1.attach(pin);

  }

  void loop() {
    for (pos = 0; pos <= 90; pos += 10) {
      finger1.write(pos);
      delay(10);
    }
    delay(180 * 4);
    for (pos = 90; pos >= 0; pos -= 10) {
      finger1.write(pos);
      delay(10);
    }
  }
};


class REighth{
  Servo finger1;  // create servo object to control a servo
  // twelve servo objects can be created on most boards
  const byte pin;
  int pos = 0;    // variable to store the servo position
  int count = 0;

  void setup() {
    // put your setup code here, to run once:
    finger1.attach(pin);

  }

  void loop() {
    //180 msecond per eighth note
    delay(180);
  }
};

class RQuarter{
  Servo finger1;  // create servo object to control a servo
  // twelve servo objects can be created on most boards
  const byte pin;
  int pos = 0;    // variable to store the servo position
  int count = 0;

  void setup() {
    // put your setup code here, to run once:
    finger1.attach(pin);

  }

  void loop() {
    //180 msecond per eighth note
    delay(180*2);
  }
};

class RHalf{
  Servo finger1;  // create servo object to control a servo
  // twelve servo objects can be created on most boards
  const byte pin;
  int pos = 0;    // variable to store the servo position
  int count = 0;

  void setup() {
    // put your setup code here, to run once:
    finger1.attach(pin);

  }

  void loop() {
    //180 msecond per eighth note
    delay(180*4);
  }
};

class RWhole{
  Servo finger1;  // create servo object to control a servo
  // twelve servo objects can be created on most boards
  const byte pin;
  int pos = 0;    // variable to store the servo position
  int count = 0;

  void setup() {
    // put your setup code here, to run once:
    finger1.attach(pin);

  }

  void loop() {
    //180 msecond per eighth note
    delay(180*8);
  }
};


//Jingle Bells
//4 4 2 | 4 4 2 | 4 4 4 /8 8 | 2 /2|
//180 msecond per eighth note

Quarter();
Quarter();
Half();
