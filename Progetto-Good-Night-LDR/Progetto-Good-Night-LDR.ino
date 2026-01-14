#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int pinSensore = 7;
const int leds[] = {9, 10, 11, 12}; 
const int numLeds = 4;
bool sequenzaCompletata = false; 

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // Velocità ridotta per garantire stabilità ai contatti sulla breadboard
  Wire.setClock(10000); 

  lcd.init();
  lcd.noBacklight(); 
  lcd.clear();

  pinMode(pinSensore, INPUT);
  
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {
  int statoSensore = digitalRead(pinSensore);

  if (statoSensore == HIGH && sequenzaCompletata == false) {
    
    // --- 1. SEQUENZA LED ---
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(leds[i], HIGH);
      if (i == numLeds - 1) {
        delay(300); // Breve flash dell'ultimo LED
      } else {
        delay(1000); 
      }
    }

    // Spegnimento immediato di tutti i LED
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(leds[i], LOW);
    }

    // --- 2. SEQUENZA DISPLAY ---
    delay(100);        
    lcd.backlight();   
    lcd.clear();
    lcd.setCursor(3, 0);
    
    // Scrittura lettera per lettera per evitare errori di comunicazione
    char msg[] = "GOOD NIGHT";
    for (int i = 0; i < 10; i++) {
      lcd.print(msg[i]);
      delay(100);      
    }

    // Il display resta acceso per 4 secondi
    delay(4000); 

    // Spegnimento totale del display
    lcd.clear();
    lcd.noBacklight();
    
    sequenzaCompletata = true; 
    Serial.println("Ciclo notturno completato.");
  }

  // Reset del sistema quando torna la luce (sensore LOW)
  if (statoSensore == LOW) {
    sequenzaCompletata = false; 
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(leds[i], LOW);
    }
    lcd.noBacklight();
    lcd.clear();
  }
  
  delay(100); 
}
