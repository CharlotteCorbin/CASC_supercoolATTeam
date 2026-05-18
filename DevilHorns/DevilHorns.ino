#include <Servo.h> 

const int buttonPin = 4; 
const int servoPin = 9; // may need to change this servopin not very sure 

const int start_POS = x; //Starting position 
const int end_POS = y; //Ending Position 
const int speed = z; //The speed while flipping pages


void setup() {
  // set up for the devil positions. 
  pageServo.attach(servoPin);
  pinMode(buttonPin, INPUT_PULLUP);
  pageServo.write(start_POS);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW){
    turnPage();
    delay(1000);
  }

}

void turnPage(){
  // turning page mechanism 
  for (int pos = start_POS; pos < end_POS; pos++){
    pageServo.write(pos);
    delay(speed);
  }
  delay(1000);
  for (int pos = end_POS; pos > start_POS; pos--){
    pageServo(pos);
    delay(speed);
  }

}
