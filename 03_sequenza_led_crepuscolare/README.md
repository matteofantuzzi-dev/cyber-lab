# Sequenza LED Crepuscolare (4 LED)

Questo progetto evolve il test base del sensore LM393 creando una sequenza di attivazione temporizzata di 4 LED.

## 🚀 Funzionamento
Quando il sensore rileva il superamento della soglia di buio:
1. Si accende il primo LED (Pin 9).
2. Dopo 1 secondo si accende il secondo (Pin 10).
3. Dopo un altro secondo il terzo (Pin 11).
4. Dopo un ultimo secondo il quarto (Pin 12).
Tutti i LED rimangono accesi finché persiste il buio. Quando torna la luce, il sistema si resetta spegnendo tutto.

## 🔌 Schema di Collegamento
* **Sensore LM393**: VCC -> 5V, GND -> GND, D0 -> Pin 7.
* **LED 1**: Pin 9 (con resistenza 220Ω).
* **LED 2**: Pin 10 (con resistenza 220Ω).
* **LED 3**: Pin 11 (con resistenza 220Ω).
* **LED 4**: Pin 12 (con resistenza 220Ω).

## 🛠️ Competenze acquisite
- Gestione di uscite multiple in parallelo.
- Utilizzo della funzione `delay()` per la temporizzazione.
- Controllo di flusso condizionale (`if-else`) basato su input digitale.
