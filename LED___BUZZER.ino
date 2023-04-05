int speaker=5;
void setup() {
  pinMode(13,OUTPUT); // apa dampaknya jika baris ini di-non aktifkan
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(speaker,OUTPUT);    
}

void loop() {
  digitalWrite(13,HIGH);
  tone(speaker, 262); 
  delay(500);
 
  digitalWrite(13,LOW);
  delay(500);

  digitalWrite(12,HIGH);
  tone(speaker, 294); 
  delay(500);
  
  digitalWrite(12,LOW);
  delay(500);

  digitalWrite(11,HIGH);
  tone(speaker, 330); 
  delay(500);
 
  digitalWrite(11,LOW);
  delay(500);

  digitalWrite(10,HIGH);
  tone(speaker, 349); 
  delay(500);
  
  digitalWrite(10,LOW);
  delay(500);

  digitalWrite(9,HIGH);
  tone(speaker, 395); 
  delay(500);
  
  digitalWrite(9,LOW);
  delay(500);

  digitalWrite(8,HIGH);
  tone(speaker, 440); 
  delay(500);
  
  digitalWrite(8,LOW);
  delay(500);

  digitalWrite(7,HIGH);
  tone(speaker, 494); 
  delay(500);
  
  digitalWrite(7,LOW);
  delay(500);

  digitalWrite(6,HIGH);
  tone(speaker, 523); 
  delay(500);
  
  digitalWrite(6,LOW);
  delay(500);  
}



//BUZZER
//Pin 13 - 6 ke led 0 - 7 di display kit
//Pin 5 ke buzzer di display kit
//Gnd ke G di display kit
