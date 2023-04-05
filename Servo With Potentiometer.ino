#include <Servo.h>

Servo myservo;
int potPin = A0;  // pin potensiometer
int servoPin = 9;  // pin servo

void setup() {
  myservo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(potPin);
  int servoAngle = map(potValue, 0, 1023, 0, 180);
  myservo.write(servoAngle);
  delay(15);
}
