//Codes written seperately however conjoined with the help claude ai. 

#include <Servo.h>

// ========== PINS ==========
#define BUTTON_PIN 4
#define SERVO_PIN 9
#define IN1 2
#define IN2 5

// ========== SETTINGS ==========
#define TRAVEL_TIME 400
const int START_POS = 0;   // replace with your start angle
const int END_POS = 180;   // replace with your end angle
const int FLIP_SPEED = 15; // replace with your speed

// ========== OBJECTS & STATE ==========
Servo pageServo;
bool isExtended = false;
bool lastButtonState = HIGH;

// ========== SETUP ==========
void setup() {
  Serial.begin(115200);
  pageServo.attach(SERVO_PIN);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pageServo.write(START_POS);
  stopActuator();
}

// ========== MAIN LOOP ==========
void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {
    delay(50);
    turnPage();
    if (!isExtended) {
      extend();
      isExtended = true;
    } else {
      retract();
      isExtended = false;
    }
  }

  lastButtonState = buttonState;
}

// ========== FUNCTIONS ==========
void turnPage() {
  for (int pos = START_POS; pos < END_POS; pos++) {
    pageServo.write(pos);
    delay(FLIP_SPEED);
  }
  delay(1000);
  for (int pos = END_POS; pos > START_POS; pos--) {
    pageServo.write(pos);
    delay(FLIP_SPEED);
  }
}

void extend() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(TRAVEL_TIME);
  stopActuator();
}

void retract() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(TRAVEL_TIME);
  stopActuator();
}

void stopActuator() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}