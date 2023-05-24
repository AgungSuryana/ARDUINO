#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

SoftwareSerial arduinoSerial(10, 11); // RX pin: 10, TX pin: 11

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inisialisasi objek LCD dengan alamat 0x27, 16 kolom, dan 2 baris

const int sensorPin = A0;
const int buzzerPin = 2;
const int relayPin = 3;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  lcd.begin(16, 2);  // Inisialisasi LCD dengan 16 kolom dan 2 baris
  lcd.backlight();   // Nyalakan backlight LCD
  lcd.setCursor(0, 0);
  lcd.print("DETEKSI ASAP DAN GAS");
  lcd.setCursor(0, 1);
  lcd.print("System");
  delay(2000);       // Tahan tampilan pesan selama 2 detik
  lcd.clear();       // Bersihkan LCD

  Serial.begin(115200);
  arduinoSerial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  if (arduinoSerial.available()) {
    // Read data from Arduino
    String receivedData = arduinoSerial.readStringUntil('\n');
    receivedData.trim(); // Remove leading/trailing whitespaces

    if (receivedData == "ON") {
      // Arduino sent "ON" command
      digitalWrite(relayPin, HIGH); // Turn on relay
    } else if (receivedData == "OFF") {
      // Arduino sent "OFF" command
      digitalWrite(relayPin, LOW); // Turn off relay
    }
  }

  // Display sensor value on LCD
  lcd.setCursor(0, 0);
  lcd.print("Sensor Value: ");
  lcd.print(sensorValue);

  // Perform air quality analysis based on sensor value
  if (sensorValue <= 300) {
    // Good air quality
    lcd.setCursor(0, 1);
    lcd.print("Air Quality: Good");
    tone(buzzerPin, 1000);
    digitalWrite(relayPin, HIGH); // Turn on relay
  } else if (sensorValue <= 800) {
    // Moderate air quality
    lcd.setCursor(0, 1);
    lcd.print("Air Quality: Moderate");
    noTone(buzzerPin);
    digitalWrite(relayPin, LOW); // Turn off relay
  } else {
    // Poor air quality
    lcd.setCursor(0, 1);
    lcd.print("Air Quality: Poor");
    tone(buzzerPin, 2000);
    digitalWrite(relayPin, HIGH); // Turn on relay
  }

  // Send sensor value to Arduino
  arduinoSerial.print(sensorValue);
  arduinoSerial.print('\n');

  delay(1000);
}
