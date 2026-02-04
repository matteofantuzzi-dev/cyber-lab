/*
 * PROJECT: Cyber-Lab Final Edition
 * COMPONENTS: Arduino Uno, I2C LCD 16x2, 8 LEDs, Traffic Light Module, Buzzer, Light Sensor.
 * DESCRIPTION: A smart night-sequence system that triggers a traffic light and LED 
 * sequence when darkness is detected, with serial monitoring.
 */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Configurazione Display I2C (Indirizzo 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// --- PIN MAP ---
const int pinSensore = 7;   // Sensore crepuscolare
const int pinBuzzer  = 6;   // Buzzer (Segnale su Pin 6)

// Semaforo (Pin Analogici usati come Digitali)
const int semVerde  = A1;
const int semGiallo = A2;
const int semRosso  = A3;

// Array 8 LED Digitali
const int leds[] = {2, 3, 4, 5, 9, 10, 11, 12}; 
const int numLeds = 8;

// --- VARIABILI DI STATO ---
bool sequenzaEseguita = false; 

void setup() {
  Serial.begin(9600);
  
  // Stabilizzazione comunicazione I2C
  Wire.begin();
  Wire.setClock(10000); 

  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  // Configurazione Pin
  pinMode(pinBuzzer, OUTPUT);
  pinMode(semVerde, OUTPUT);
  pinMode(semGiallo, OUTPUT);
  pinMode(semRosso, OUTPUT);
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
  pinMode(pinSensore, INPUT);
  
  // --- STARTUP SEQUENCE ---
  lcd.setCursor(2, 0);
  lcd.print("SYSTEM READY");
  Serial.println(F("--- SYSTEM READY ---"));
  
  // Unico Beep di sistema (300Hz, 50ms)
  tone(pinBuzzer, 300, 50); 
  
  delay(3000); 
  lcd.clear();
  lcd.noBacklight();
  Serial.println(F("In attesa del sensore..."));
}

void loop() {
  // Lettura sensore (HIGH = Buio, LOW = Luce)
  bool buioRilevato = (digitalRead(pinSensore) == HIGH);

  // LOGICA: Rilevamento Buio
  if (buioRilevato && !sequenzaEseguita) {
    Serial.println(F("BUIO RILEVATO")); 
    avviaSequenza();
    sequenzaEseguita = true; 
  }

  // LOGICA: Rilevamento Luce (Reset sistema)
  if (!buioRilevato && sequenzaEseguita) {
    Serial.println(F("LUCE RILEVATA")); 
    sequenzaEseguita = false;
    
    // Pulizia display per il prossimo ciclo
    lcd.init();
    lcd.noBacklight();
  }
}

void avviaSequenza() {
    // 1. SEMAFORO ATTIVO (Rosso -> Giallo -> Verde)
    Serial.println(F("SEMAFORO ATTIVO")); 
    digitalWrite(semRosso, HIGH); 
    delay(500); 
    digitalWrite(semRosso, LOW);
    
    digitalWrite(semGiallo, HIGH); 
    delay(500); 
    digitalWrite(semGiallo, LOW);
    
    digitalWrite(semVerde, HIGH); 
    delay(500); 
    digitalWrite(semVerde, LOW);

    delay(500); // Pausa pre-LED

    // 2. SEQUENZA 8 LED (Accensione progressiva)
    Serial.println(F("SEQUENZA LED INIZIATA")); 
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(leds[i], HIGH); 
      Serial.print(F("LED ")); Serial.print(i+1); Serial.println(F(" ACCESO"));
      delay(700); 
    }
    Serial.println(F("TERMINE SEQUENZA LED")); 

    // 3. MESSAGGIO FINALE LCD
    lcd.backlight();
    lcd.display();
    lcd.clear(); 
    lcd.setCursor(3, 0);
    lcd.print("GOOD NIGHT");

    // 4. ATTESA PRIMA DELLO SPEGNIMENTO
    delay(3000); 

    // 5. SPEGNIMENTO TOTALE (Tutti i LED e Display)
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(leds[i], LOW);
    }
    
    lcd.clear();
    lcd.noBacklight();
    lcd.noDisplay(); 
    Serial.println(F("Sequenza terminata. Tutto spento."));
}
