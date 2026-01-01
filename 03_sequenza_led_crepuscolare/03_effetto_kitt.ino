/*
 * Progetto: Effetto KITT (Supercar) Crepuscolare
 * Lab: CyberLab
 */

const int pinSensore = 7;
const int ledPins[] = {9, 10, 11, 12}; // Array dei pin per gestire i LED più facilmente
const int numeroLed = 4;
const int velocita = 100; // Millisecondi tra un LED e l'altro

void setup() {
  pinMode(pinSensore, INPUT);
  for (int i = 0; i < numeroLed; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  if (digitalRead(pinSensore) == HIGH) {
    // Andata: da 9 a 12
    for (int i = 0; i < numeroLed; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(velocita);
      digitalWrite(ledPins[i], LOW);
    }

    // Ritorno: da 11 a 10 (per non ripetere gli estremi)
    for (int i = numeroLed - 2; i > 0; i--) {
      digitalWrite(ledPins[i], HIGH);
      delay(velocita);
      digitalWrite(ledPins[i], LOW);
    }
  } else {
    // Se c'è luce, tutto spento
    for (int i = 0; i < numeroLed; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }
}
