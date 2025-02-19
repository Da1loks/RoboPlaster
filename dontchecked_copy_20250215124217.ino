#include <AFMotor.h> 
const int motorPin1 = 10;   // Первый пин мотора шпателя
const int motorPin2 = 9;  // Второй пин мотора шпателя

AF_DCMotor motor1(1); // Передний левый
AF_DCMotor motor2(2); // Передний правый
AF_DCMotor motor3(3); // Задний левый
AF_DCMotor motor4(4); // Задний правый

void setup() {
  // Настройка скорости моторов
  motor1.setSpeed(120);
  motor2.setSpeed(120);
  motor3.setSpeed(170);
  motor4.setSpeed(170);
  // Остановка моторов
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  // Настройка пинов для дополнительного мотора
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  for(int cycle = 0; cycle < 5; cycle++) {
    // Движение в бок
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
    delay(500);  // Движение 1 секунду
    
    // Остановка движения в бок
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    delay(50);    // Пауза 50 мс
    
    // Движение дополнительного мотора вперед
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(3000);  // 5 секунд вперед
    
    // Движение дополнительного мотора назад
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(1300);  // 1 секунда назад
// Движение дополнительного мотора вперед
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(3000);  // 5 секунд вперед
    
    // Движение дополнительного мотора назад
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(1300);  // 1 секунда назад
    
    // Остановка дополнительного мотора
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    delay(50);    // Пауза 50 мс перед следующим циклом
  }
  
  // Пауза после 5 циклов
  delay(5000);
}