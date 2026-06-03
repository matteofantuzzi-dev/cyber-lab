# Flipper Zero - Geiger Counter Module (J305)

Repository dedicato alla documentazione, installazione e configurazione del modulo hardware **Contatore Geiger-Müller** per Flipper Zero. Il modulo permette la rilevazione in tempo reale delle radiazioni ionizzanti (Beta e Gamma) presenti nell'ambiente circostante.

---

## 📸 Galleria del Progetto

Di seguito viene mostrato il flusso di montaggio e configurazione del modulo, i cui file immagine sono salvati all'interno della cartella `assets/`:

| 1. Modulo Hardware | 2. Attivazione Alimentazione |
|---|---|
| <img src="assets/01_modulo_geiger.jpg" width="250"> | <img src="assets/02_gpio_power.jpg" width="250"> |
| Il modulo protetto dal guscio personalizzato. | Abilitazione dell'erogazione dei 5V sui pin GPIO. |

| 3. Avvio Applicazione | 4. Lettura in Tempo Reale |
|---|---|
| <img src="assets/03_app_selection.jpg" width="250"> | <img src="assets/04_realtime_reading.jpg" width="250"> |
| Selezione del profilo software per il tubo J305. | Grafico e misurazione dei CPM (Fondo Naturale). |

---

## 🛠️ Requisiti Hardware e Software
* **Hardware**: Flipper Zero con modulo Geiger-Müller esterno (dotato di tubo J305/M4011).
* **Firmware**: Firmware compatibile con GPIO apps (es. Momentum Firmware).
* **Applicazione**: `Applications > GPIO > [J305] Geiger Counter`.

Per i dettagli approfonditi sulla calibrazione dei pin, sulla fisica del sensore e sui livelli di radiazione registrati, consulta la **[Guida al Funzionamento](GUIDA_FUNZIONAMENTO.md)**.

---

## ⚠️ Disclaimer / Dichiarazione di Non Responsabilità

Questo progetto è condiviso esclusivamente a scopo didattico, informativo e di studio personale dell'elettronica e del software open-source. 

* **Nessuna Responsabilità**: L'autore non si assume alcuna responsabilità per danni materiali, malfunzionamenti del Flipper Zero, scosse elettriche causate dal circuito elevatore di tensione del modulo, o per qualsiasi uso improprio del dispositivo e del modulo da parte di terzi.
* **Non per scopi Medici o di Sicurezza**: Questo modulo non è uno strumento medico o di protezione civile certificato. Non deve essere utilizzato in situazioni di emergenza nucleare o per certificare l'assoluta sicurezza di ambienti o oggetti. L'uso di questo materiale è a completo rischio e pericolo dell'utilizzatore finale.
