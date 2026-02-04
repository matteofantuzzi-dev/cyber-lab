# 🏮 Cyber-Lab: Smart Night-Light System (Final Edition)

Benvenuti nel progetto **Cyber-Lab**, un sistema di illuminazione intelligente basato su Arduino Uno. Il sistema rileva l'assenza di luce e attiva una sequenza coreografica che include un semaforo di segnalazione e una serie di 8 LED, concludendosi con un messaggio di saluto sul display LCD.

## 🚀 Funzionalità
- **Startup Diagnostic**: All'accensione, il sistema esegue un test del display e un feedback sonoro (mini-beep).
- **Rilevamento Crepuscolare**: Attivazione automatica tramite sensore di luce.
- **Semaforo Inverso**: Sequenza di avvio Rosso -> Giallo -> Verde (500ms cad.).
- **Sequenza LED**: Accensione progressiva di 8 LED (700ms cad.).
- **Display I2C**: Visualizzazione dinamica degli stati ("SYSTEM READY", "GOOD NIGHT").
- **Monitoraggio Seriale**: Log completo di ogni evento (rilevamento buio, stato LED, reset luce).

## 🛠️ Hardware Necessario
| Componente | Quantità | Note |
| :--- | :--- | :--- |
| Arduino Uno R3 | 1 | Microcontrollore principale |
| Display LCD 16x2 I2C | 1 | Indirizzo 0x27 |
| Sensore di Luce (LDR) | 1 | Collegato al Pin Digitale 7 |
| Modulo Semaforo | 1 | Pin Verde (A1), Giallo (A2), Rosso (A3) |
| Buzzer (3-pin) | 1 | Collegato al Pin 6 |
| LED (Colori vari) | 8 | Resistenze da 220 ohm incluse |

## 🔌 Schema di Collegamento (Pin Map)
Il progetto utilizza quasi tutti i pin disponibili per massimizzare l'output visivo:

### Display & Sensori
- **LCD I2C**: SDA -> A4, SCL -> A5, VCC -> 5V, GND -> GND
- **Sensore Luce**: Signal -> Pin 7
- **Buzzer**: Signal -> Pin 6

### Output Visivi
- **Semaforo**: Verde (A1), Giallo (A2), Rosso (A3)
- **8 LED Sequence**: Pin Digitali 2, 3, 4, 5, 9, 10, 11, 12

## 📜 Logica del Software
1. **Fase Standby**: Il sistema monitora il Pin 7. Il display è spento per risparmiare energia.
2. **Fase Trigger**: Quando il sensore rileva il buio (`HIGH`), avvia `avviaSequenza()`.
3. **Esecuzione**: Il semaforo indica la preparazione, i LED si accendono uno alla volta per creare un effetto "scia".
4. **Fase Sleep**: Appare "GOOD NIGHT" per 3 secondi, poi tutto si spegne completamente.
5. **Reset**: Il sistema non riparte finché non viene rilevata nuovamente la luce (per evitare loop infiniti).

## 💻 Installazione
1. Assicurati di avere installato la libreria `LiquidCrystal_I2C`.
2. Carica il file `.ino` tramite l'IDE di Arduino.
3. Apri il **Monitor Seriale** (9600 baud) per visualizzare il debug in tempo reale.

---
*Sviluppato con passione nel Cyber-Lab.*
