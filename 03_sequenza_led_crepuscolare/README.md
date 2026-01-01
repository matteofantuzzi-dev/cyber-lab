# Sequenza LED Crepuscolare (4 LED)

Questo progetto esplora la gestione di più uscite digitali attivate da un sensore di luce LM393.

## 📁 Versioni del Progetto
Ho implementato due varianti del codice per mostrare diversi livelli di complessità:

1. **[Versione Base](./03a_sequenza_crepuscolare_base.ino)**: Una sequenza lineare dove i LED si accendono uno dopo l'altro ogni secondo e restano fissi. Ideale per testare i collegamenti.
2. **[Versione Avanzata (KITT Mode)](./03b_effetto_kitt.ino)**: Utilizza **Array** e **cicli for** per creare un effetto scanner "Supercar". Il codice è più ottimizzato e fluido.

## 🔌 Schema di Collegamento
* **Sensore LM393**: D0 -> Pin 7
* **LEDs**: Pin 9, 10, 11, 12 (tutti con resistenza da 220Ω verso GND)

## 💡 Concetti Appresi
- Ottimizzazione del codice tramite Array e cicli `for`.
- Gestione della temporizzazione non lineare.
- Organizzazione di un progetto multi-file.
