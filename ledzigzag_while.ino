int pin[] = {9, 8, 7, 6, 10, 11, 12, 13};
int d = 150;
int i = 0;

void setup() {
  while (i < 8) {
    pinMode(pin[i], OUTPUT);
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
  while (i < 8) {
    digitalWrite(pin[i], HIGH);
    delay(d);
    digitalWrite(pin[i], LOW);
    i++;
  }
}

void PutarKanan() {
  i = 7;
  while (i >= 0) {
    digitalWrite(pin[i], HIGH);
    delay(d);
    digitalWrite(pin[i], LOW);
    i--;
  }
}

void ZigZag() {
  int zigzagPin[] = {9, 12, 7, 10, 6, 11, 8, 13};
  i = 7;
  while (i >= 0) {
    digitalWrite(zigzagPin[i], HIGH);
    delay(d);
    digitalWrite(zigzagPin[i], LOW);
    i--;
  }
}
