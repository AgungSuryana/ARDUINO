/*****
 * Nama File : A01_Led_80j_Loop_Fungsi
 * Menyalakan 8 Led dari pin 6..13
 * Cara : menggunakan Loop - For
 *        menggunakan Array 
 *        menggunakan fungsi
 *****/
/* Uno --> P-01 (Display kit)
 *  6  -->  7 
 *  7  -->  6
 *  8  -->  5  
 *  9  -->  4
 *  10 -->  3
 *  11 -->  2 
 *  12 -->  1
 *  13 -->  0
 */

int pin[]={9,8,7,6,10,11,12,13};
int d=150;

void setup() {
  for(int i=0;i<8;i++){
    pinMode(pin[i], OUTPUT);
  }
}

void loop() {
  PutarKiri();
  PutarKanan();
  ZigZag();
}

void PutarKiri() {
  for(int i=0;i<8;i++){
    digitalWrite(pin[i],HIGH);
    delay(d);
    digitalWrite(pin[i],LOW);
  }
}

void PutarKanan() {
  for(int i=7;i>=0;i--){
    digitalWrite(pin[i],HIGH);
    delay(d);
    digitalWrite(pin[i],LOW);
  }
}

void ZigZag() {
  int pin[]={9,12,7,10,6,11,8,13};
  for(int i=7;i>=0;i--){
    digitalWrite(pin[i],HIGH);
    delay(d);
    digitalWrite(pin[i],LOW);
  }
}
