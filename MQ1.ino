#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <Servo.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

#define BLYNK_AUTH_TOKEN "KAZDeOFStFylpaV57E-pVqLGwerAsP7z"
char ssid[] = "AGUNG";
char pass[] = "agungsuryana18";


LiquidCrystal_I2C lcd(0x27, 16, 2);

const int MQ135_PIN = A0;
const int BUZZER_PIN = 8;
const int RELAY_PIN = 9;

#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

void setup() {
  Serial.begin(115200);
  EspSerial.begin(ESP8266_BAUD);
  delay(10);
  lcd.begin(16, 2);
  lcd.backlight();

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
   Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  int airQuality = analogRead(MQ135_PIN);

  Serial.print("Air Quality: ");
  Serial.println(airQuality);

  int ppm = map(airQuality, 0, 1023, 0, 1000);

  Serial.print("PPM: ");
  Serial.println(ppm);

  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("PPM:");
  lcd.setCursor(5, 1);
  lcd.print(ppm);

 if (airQuality >= 800) {
  lcd.setCursor(0, 0);
  lcd.print("Udara Berbahaya");
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, HIGH); // Mengatur suara buzzer dengan PWM penuh (255)
}
else if (airQuality >= 300) {
  lcd.setCursor(0, 0);
  lcd.print("Udara Buruk");
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, HIGH); // Mengatur suara buzzer dengan PWM setengah (128)
}
else {
  lcd.setCursor(0, 0);
  lcd.print("Udara Segar"); // Menempatkan kursor di kolom 11 pada baris 1
  digitalWrite(RELAY_PIN, HIGH);
  noTone(BUZZER_PIN);
}

  Blynk.virtualWrite(V1, ppm); // V1 is for PPM
  Blynk.run();
  delay(1000);
}
