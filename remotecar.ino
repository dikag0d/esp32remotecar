#include <PS3Controller.h>

// ==========================
// PIN MOTOR
// ==========================
#define ENA  25   // PWM motor kiri
#define IN1  26
#define IN2  27

#define ENB  14   // PWM motor kanan
#define IN3  12
#define IN4  13

// ==========================
// SETUP
// ==========================
void setup() {
  Serial.begin(115200);

  // Motor output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start PS3
  PS3.begin("01:02:03:04:05:06");  
  Serial.println("Menunggu koneksi PS3 Controller...");
}

void loop() {

  if (!PS3.isConnected()) return;

  // ==========================
  // BACA JOYSTICK PS3
  // ==========================
  int LX = PS3.data.analog.stick.lx;  // -128 → kiri, 127 → kanan
  int LY = PS3.data.analog.stick.ly;  // -128 → atas, 127 → bawah

  // Konversi ke kecepatan PWM (0 – 255)
  int speedY = map(abs(LY), 0, 128, 0, 255);
  int speedTurn = map(abs(LX), 0, 128, 0, 255);

  // ==========================
  // KONTROL MOBIL
  // ==========================

  // ---------------------------
  // MAJU
  // ---------------------------
  if (LY < -20) {
    motorKiri(speedY);
    motorKanan(speedY);
  }

  // ---------------------------
  // MUNDUR
  // ---------------------------
  else if (LY > 20) {
    motorKiri(-speedY);
    motorKanan(-speedY);
  }

  // ---------------------------
  // BEL0K KANAN
  // ---------------------------
  else if (LX > 20) {
    motorKiri(speedTurn); 
    motorKanan(-speedTurn);
  }

  // ---------------------------
  // BEL0K KIRI
  // ---------------------------
  else if (LX < -20) {
    motorKiri(-speedTurn);
    motorKanan(speedTurn);
  }

  // ---------------------------
  // DIAM
  // ---------------------------
  else {
    motorKiri(0);
    motorKanan(0);
  }
}

// ==========================
// FUNGSI MOTOR
// ==========================
void motorKiri(int speed) {

  if (speed > 0) {  // MAJU
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, speed);
  }
  else if (speed < 0) { // MUNDUR
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, -speed);
  }
  else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
  }
}

void motorKanan(int speed) {

  if (speed > 0) {  // MAJU
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, speed);
  }
  else if (speed < 0) { // MUNDUR
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, -speed);
  }
  else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0);
  }
}
