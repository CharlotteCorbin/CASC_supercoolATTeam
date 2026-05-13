//Codes written with the help of claude ai. 

// ========== PINS ==========
#define MOTOR_A_IN1 18
#define MOTOR_A_IN2 19
#define MOTOR_B_IN1 x
#define MOTOR_B_IN2 y

// ========== STATE ==========
bool isRunning = false;

// ========== SETUP ==========
void setup() {
  Serial2.begin(115200, SERIAL_8N1, 16, 17); // RX=GPIO16, TX=GPIO17

  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_IN1, OUTPUT);
  pinMode(MOTOR_B_IN2, OUTPUT);

  stopMotors();
}

// ========== MAIN LOOP ==========
void loop() {
  if (Serial2.available()) {
    char signal = Serial2.read();

    if (signal == '1') {
      if (!isRunning) {
        runMotors();
        isRunning = true;
      } else {
        stopMotors();
        isRunning = false;
      }
    }
  }
}

// ========== DC MOTOR FUNCTIONS ==========
void runMotors() {
  digitalWrite(MOTOR_A_IN1, HIGH);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN1, HIGH);
  digitalWrite(MOTOR_B_IN2, LOW);
}

void stopMotors() {
  digitalWrite(MOTOR_A_IN1, LOW);
  digitalWrite(MOTOR_A_IN2, LOW);
  digitalWrite(MOTOR_B_IN1, LOW);
  digitalWrite(MOTOR_B_IN2, LOW);
}