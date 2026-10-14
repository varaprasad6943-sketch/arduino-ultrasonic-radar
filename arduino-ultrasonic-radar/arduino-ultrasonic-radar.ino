#include <Servo.h>
const int SERVO_PIN = 8;
const int STEP = 2;
const int TRIG = 10;
const int ECHO = 11;
const float SPEED_OF_SOUND = 0.0341;
const int TRIGGER_TIME = 10;
const int DELAY_TIME = 30;
Servo MyServo;
void setup() {
  Serial.begin(9600);

  MyServo.attach(SERVO_PIN);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}


void loop() {
  for (int i = 0; i <= 180; i += STEP) {
    MyServo.write(i);
    UltraSonicSensor(i);
  }
  for (int i = 180; i >= 0; i -= STEP) {
    MyServo.write(i);
    UltraSonicSensor(i);
  }
}

void UltraSonicSensor(int ANGLE) {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(TRIGGER_TIME);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(TRIGGER_TIME);
  digitalWrite(TRIG, LOW);

  long t = pulseIn(ECHO, HIGH, 30000);
  float cm = t * SPEED_OF_SOUND / 2;


  Serial.print(ANGLE);
  Serial.print("deg ");

  Serial.print(cm);
  Serial.println("cm");


  delay(DELAY_TIME);
}
