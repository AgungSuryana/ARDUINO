#include <Servo.h>

Servo myservo;  // Membuat objek servo

void setup() {
  myservo.attach(2);  // Menghubungkan servo ke pin 9
}

void loop() {
  myservo.write(0);         // Menggerakkan servo ke posisi 0 derajat
  delay(1000);              // Menunggu selama 1 detik
  myservo.write(90);        // Menggerakkan servo ke posisi 90 derajat
  delay(1000);              // Menunggu selama 1 detik
  myservo.write(180);       // Menggerakkan servo ke posisi 180 derajat
  delay(1000);              // Menunggu selama 1 detik
}
