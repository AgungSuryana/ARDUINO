#include <Stepper.h>
// jumlah langkah per putaran motor
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // inisialisasi objek Stepper dengan pin 8, 9, 10, dan 11

void setup() {
  // nothing to do here
  Serial.begin(9600);
}


void loop() {
  int teg = analogRead(A1);
  Serial.println(teg);
  // putar searah jarum jam selama 1 putaran
  myStepper.setSpeed(100); // kecepatan motor dalam satuan rpm (rotasi per menit)
  
   // tunggu selama 1 detik

   // tunggu selama 1 detik
}
