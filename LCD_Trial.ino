#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int song = 0;
const int modes = 4;
int playState = 0;
int buttonState = LOW;
int lastButtonState = LOW;
int playButtonState = LOW;
int lastPlayButtonState = LOW;
int hi = 0 ;

const int ledPin = 10;
const int playButtonPin = 11;
const int buttonPin = 12;

// Timers for the debouncing
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;

/*
  int scale(ledPin){
  digitalWrite(ledPin,HIGH);
}
*/


void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(playButtonPin,INPUT);
  pinMode(buttonPin,INPUT);
  lcd.begin(16,2);
  lcd.clear();
  long baudRate = 9600;
  Serial.begin(baudRate);
}

void loop() {
  // put your main code here, to run repeatedly:

playButtonState = digitalRead(playButtonPin);
if (song == 0){
  if (playState == 0){
  lcd.setCursor(3,0);
  lcd.print("Piano Cat");
  }
  if (playButtonState != lastPlayButtonState){
    if (playButtonState == HIGH){
      lcd.clear();
      playState = 1;
      lcd.setCursor(4,0);
      lcd.print("Playing");
      lcd.setCursor(3,1);
      lcd.print("Piano Cat");
    }
  }
}

if (song == 1){
  if (playState == 0){
  lcd.setCursor(0,0);
  lcd.print("Twinkle Twinkle");
  }
  if (playButtonState != lastPlayButtonState){
    if (playButtonState == HIGH){
      lcd.clear();
      playState = 1;
      lcd.setCursor(4,0);
      lcd.print("Playing");
      lcd.setCursor(0,1);
      lcd.print("Twinkle Twinkle");
    }
  }
}

if (song == 2){
  if (playState == 0){
  lcd.setCursor(5,0);
  lcd.print("Scale");
  }
  if (playButtonState != lastPlayButtonState){
    if (playButtonState == HIGH){
      lcd.clear();
      playState = 1;
      lcd.setCursor(4,0);
      lcd.print("Playing");
      lcd.setCursor(5,1);
      lcd.print("Scale");
    }
  }
}

if (song == 3){
  if (playState == 0){
    lcd.setCursor(3,0);
    lcd.print("Art-Duino");
  }
  if (playButtonState != lastPlayButtonState){
    if (playButtonState == HIGH){
      lcd.clear();
      playState = 1;
      lcd.setCursor(4,0);
      lcd.print("Playing");
      lcd.setCursor(3,1);
      lcd.print("Art-Duino");
    }
  }
}

buttonState = digitalRead(buttonPin);
if (buttonState != lastButtonState){
if (buttonState == HIGH){
  if ((millis() - lastDebounceTime) > debounceDelay){
  song += 1;
  if (song == modes){
  song = 0;
  }
  lastDebounceTime = millis();
  lcd.clear();
  playState = 0;
  }
  }
lastButtonState = buttonState;
}

 Serial.print("Song =");
 Serial.print(song);
 Serial.print(" Button =");
 Serial.print(buttonState);
 Serial.print(" PlayState =");
 Serial.print(playState);
 Serial.print(" led =");
 Serial.println(digitalRead(ledPin));

}
