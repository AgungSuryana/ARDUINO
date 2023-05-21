#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

#include "MQ135.h"

SoftwareSerial esp8266(9, 10); // RX pin: 9, TX pin: 10

const int sensorPin = A0;
const int buzzerPin = 7;
const int relayPin = 6;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Air Quality");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring");
  
  delay(2000);
  
  Serial.begin(115200);
  esp8266.begin(115200);

  sendData("AT+RST\r\n", 2000, true); // reset module
  sendData("AT+CWMODE=2\r\n", 1000, true); // configure as access point
  sendData("AT+CIFSR\r\n", 1000, true); // get IP address
  sendData("AT+CIPMUX=1\r\n", 1000, true); // configure for multiple connections
  sendData("AT+CIPSERVER=1,80\r\n", 1000, true); // turn on server on port 80

  lcd.clear();
}

void loop() {
  MQ135 gasSensor = MQ135(sensorPin);
  float air_quality = gasSensor.getPPM();

  if (esp8266.available()) {
    if (esp8266.find("+IPD,")) {
      delay(1000);
      int connectionId = esp8266.read() - '0';
      String webpage = "<h1>IOT Air Pollution Monitoring System</h1>";
      webpage += "<p><h2>";
      webpage += "Air Quality is ";
      webpage += air_quality;
      webpage += " PPM";
      webpage += "<p>";

      if (air_quality <= 1000) {
        webpage += "Fresh Air";
      } else if (air_quality <= 2000) {
        webpage += "Poor Air";
      } else if (air_quality > 2000) {
        webpage += "Danger! Move to Fresh Air";
      }

      webpage += "</h2></p></body>";

      String cipSend = "AT+CIPSEND=";
      cipSend += connectionId;
      cipSend += ",";
      cipSend += webpage.length();
      cipSend += "\r\n";

      sendData(cipSend, 1000, true);
      sendData(webpage, 1000, true);

      cipSend = "AT+CIPCLOSE=";
      cipSend += connectionId;
      cipSend += "\r\n";

      sendData(cipSend, 3000, true);
    }
  }

  lcd.setCursor(0, 1);
  lcd.print("PPM: ");
  lcd.print(air_quality);

  if (air_quality <= 300) {
    lcd.setCursor(0, 0);
    lcd.print("Udara Segar");
    noTone(buzzerPin);
    digitalWrite(relayPin, HIGH);
  } else if (air_quality <= 800) {
    lcd.setCursor(0, 0);
    lcd.print("Udara Buruk");
    tone(buzzerPin, 1000);
    digitalWrite(relayPin, LOW);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Udara Berbahaya");
    tone(buzzerPin, 2000);
    digitalWrite(relayPin, LOW);
  }

  delay(1000);
  lcd.clear();
}

String sendData(String command, int timeout, bool debug) {
  String response = "";
  esp8266.print(command);

  unsigned long startTime = millis();
  while (millis() - startTime < timeout) {
    if (esp8266.available()) {
      char c = esp8266.read();
      response += c;
    }
  }

  if (debug) {
    Serial.print(response);
  }

  return response;
}
