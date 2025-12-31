/*
 * PROGETTO: Test Sensore di Luminosità LM393
 * DESCRIZIONE: Legge i valori digitali e analogici dal sensore e li invia al Monitor Seriale.
 */

const int pinDigitale = 7;    // Ingresso D0
const int pinAnalogico = A0;  // Ingresso AO
const int ledBoard = 13;      // LED integrato "L"

void setup() {
  pinMode(pinDigitale, INPUT);
  pinMode(ledBoard, OUTPUT);
  
  // Avvia la comunicazione con il computer
  Serial.begin(9600);
  Serial.println("--- Test Sensore LM393 Avviato ---");
}

void loop() {
  // Lettura dei dati dal sensore
  int statoDigitale = digitalRead(pinDigitale);
  int valoreAnalogico = analogRead(pinAnalogico);

  // Mostra i dati sul Monitor Seriale
  Serial.print("Digitale (D0): ");
  Serial.print(statoDigitale);
  Serial.print(" | Analogico (A0): ");
  Serial.println(valoreAnalogico);

  // Accende il LED integrato se il sensore rileva buio (D0 = HIGH)
  digitalWrite(ledBoard, statoDigitale);

  delay(500); // Legge i dati ogni mezzo secondo
}
