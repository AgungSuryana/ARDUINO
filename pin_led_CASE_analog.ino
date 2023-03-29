const int PIN_LED_0 = 6;
const int PIN_LED_1 = 7;
const int PIN_LED_2 = 8;
const int PIN_LED_3 = 9;
const int PIN_LED_4 = 10;
const int PIN_LED_5 = 11;
const int PIN_LED_6 = 12;
const int PIN_LED_7 = 13;
const int PIN_BUZZER = 5;

void setup() {
  pinMode(PIN_LED_0, OUTPUT);
  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_LED_3, OUTPUT);
  pinMode(PIN_LED_4, OUTPUT);
  pinMode(PIN_LED_5, OUTPUT);
  pinMode(PIN_LED_6, OUTPUT);
  pinMode(PIN_LED_7, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int teg = analogRead(A1);
  Serial.println(teg);

  switch(teg/125) {
    case 0:
      digitalWrite(PIN_LED_0, LOW);
      digitalWrite(PIN_LED_1, LOW);
      digitalWrite(PIN_LED_2, LOW);
      digitalWrite(PIN_LED_3, LOW);
      digitalWrite(PIN_LED_4, LOW);
      digitalWrite(PIN_LED_5, LOW);
      digitalWrite(PIN_LED_6, LOW);
      digitalWrite(PIN_LED_7, LOW);
      digitalWrite(PIN_BUZZER,LOW); 
      break;
    case 1:
      digitalWrite(PIN_LED_0, HIGH);
      digitalWrite(PIN_LED_1, HIGH);
      digitalWrite(PIN_LED_2, LOW);
      digitalWrite(PIN_LED_3, LOW);
      digitalWrite(PIN_LED_4, LOW);
      digitalWrite(PIN_LED_5, LOW);
      digitalWrite(PIN_LED_6, LOW);
      digitalWrite(PIN_LED_7, LOW);
      digitalWrite(PIN_BUZZER,LOW); 
      break;
    case 2:
      digitalWrite(PIN_LED_0, LOW);
      digitalWrite(PIN_LED_1, LOW);
      digitalWrite(PIN_LED_2, HIGH);
      digitalWrite(PIN_LED_3, HIGH);
      digitalWrite(PIN_LED_4, LOW);
      digitalWrite(PIN_LED_5, LOW);
      digitalWrite(PIN_LED_6, LOW);
      digitalWrite(PIN_LED_7, LOW);
      digitalWrite(PIN_BUZZER,LOW); 
      break;
    case 3:
      digitalWrite(PIN_LED_0, LOW);
      digitalWrite(PIN_LED_1, LOW);
      digitalWrite(PIN_LED_2, LOW);
      digitalWrite(PIN_LED_3, LOW);
      digitalWrite(PIN_LED_4, HIGH);
      digitalWrite(PIN_LED_5, HIGH);
      digitalWrite(PIN_LED_6, LOW);
      digitalWrite(PIN_LED_7, LOW);
      digitalWrite(PIN_BUZZER,LOW); 
      break;
    case 4:
      digitalWrite(PIN_LED_0, LOW);
      digitalWrite(PIN_LED_1, LOW);
      digitalWrite(PIN_LED_2, LOW);
      digitalWrite(PIN_LED_3, LOW);
      digitalWrite(PIN_LED_4, LOW);
      digitalWrite(PIN_LED_5, LOW);
      digitalWrite(PIN_LED_6, HIGH);
      digitalWrite(PIN_LED_7, HIGH);
      digitalWrite(PIN_BUZZER,LOW); 
      break;
    case 5:
     digitalWrite(PIN_LED_0, LOW);
      digitalWrite(PIN_LED_1, LOW);
      digitalWrite(PIN_LED_2, LOW);
      digitalWrite(PIN_LED_3, LOW);
      digitalWrite(PIN_LED_4, LOW);
      digitalWrite(PIN_LED_5, LOW);
      digitalWrite(PIN_LED_6, LOW);
      digitalWrite(PIN_LED_7, LOW);
      digitalWrite(PIN_BUZZER,HIGH); 
     break; 
     }
     }
