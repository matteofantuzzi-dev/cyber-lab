/*
 * Progetto 03: Sequenza LED Crepuscolare
 * Lab: CyberLab
 */

const int pinSensore = 7;
const int led1 = 9;
const int led2 = 10;
const int led3 = 11;
const int led4 = 12;

void setup() {
  pinMode(pinSensore, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int buio = digitalRead(pinSensore);

  if (buio == HIGH) {
    Serial.println("Buio rilevato: Avvio sequenza...");
    
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led3, HIGH);
    delay(1000);
    digitalWrite(led4, HIGH);
    
    // Attendiamo un po' prima di ricontrollare per evitare loop frenetici
    delay(500);
  } else {
    // Spegnimento totale in caso di luce
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
}
