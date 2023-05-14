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

int pin[]={13,12,11,10,6,7,8,9};


int d=500
;
int i;

void setup() {
  i = 0;
  while (i < 8) {
    pinMode(pin[i],OUTPUT);
    i++;
  }
}

void loop() {
  PutarKiri();
  PutarKanan();
  ZigZag();
}

void PutarKiri() {
  i = 0;
  do {
    digitalWrite(pin[i],HIGH);
    delay(d);
    digitalWrite(pin[i],LOW);
    i++;
  } while (i < 8);
}



void PutarKanan() {
  i = 7;
  do {
    digitalWrite(pin[i],HIGH);
    delay(d);
    digitalWrite(pin[i],LOW);
    i--;
  } while (i >= 0);
}


void ZigZag() {
 int pin[]={13,8,11,6,10,7,12,9};


  i = 7;
  do {
    digitalWrite(pin[i],HIGH);
    delay(d);
    digitalWrite(pin[i],LOW);
    i--;
  } while (i >= 0);
}
