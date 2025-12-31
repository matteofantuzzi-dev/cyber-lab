/*
 * File: WiFi_Scanner_AT.ino
 * Repository: cyber-lab / esp01-wifi-scanner
 * Descrizione: Bridge Seriale per scansione reti WiFi tramite comandi AT
 */

#include <SoftwareSerial.h>

// Definizione Pin: RX Pin 2 (va al TX ESP), TX Pin 3 (va al RX ESP)
SoftwareSerial esp8266(2, 3); 

void setup() {
  Serial.begin(9600);    // Comunicazione verso il PC (Monitor Seriale)
  esp8266.begin(9600);   // Comunicazione verso ESP-01 (precedentemente settato a 9600)
  
  Serial.println("--- ESP-01 WiFi Scanner Ready ---");
  Serial.println("Comandi consigliati:");
  Serial.println("1. AT+CWMODE=1  (Imposta Station Mode)");
  Serial.println("2. AT+CWLAP     (Scansiona reti)");
}

void loop() {
  // Legge dall'ESP e scrive sul PC
  if (esp8266.available()) {
    Serial.write(esp8266.read());
  }
  // Legge dal PC e scrive sull'ESP
  if (Serial.available()) {
    esp8266.write(Serial.read());
  }
}
