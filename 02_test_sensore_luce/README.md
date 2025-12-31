# Test Sensore di Luminosità (Modulo LM393)

Questo progetto serve a testare il corretto funzionamento del modulo sensore di luminosità (fotoresistenza) e a monitorarne i valori tramite il Monitor Seriale di Arduino.

## 🔌 Collegamenti effettuati
Il modulo è collegato direttamente ad Arduino sulla breadboard:
* **VCC** -> 5V di Arduino
* **GND** -> GND di Arduino
* **D0 (Digital Out)** -> Pin 7 di Arduino (per test ON/OFF)
* **AO (Analog Out)** -> Pin A0 di Arduino (per lettura valori 0-1023)

## 📈 Funzionamento
Il codice permette di:
1. Leggere lo stato digitale (0 o 1) per capire se viene superata la soglia impostata sul modulo.
2. Leggere il valore analogico preciso per monitorare la variazione di luce ambientale nel Monitor Seriale.
3. Accendere il LED integrato (L) su Arduino quando il modulo rileva buio.
