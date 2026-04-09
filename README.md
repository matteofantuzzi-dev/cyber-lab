# Cyber Lab

# 🛡️ Cyber Security & Electronics Lab

Questo repository documenta il mio laboratorio personale dedicato alla cybersecurity, all'elettronica e al pentesting. È un ambiente controllato dove testo vulnerabilità, sviluppo prototipi e analizzo segnali radio e di rete.

---

## 💻 Environment & Tools

* **OS**: Kali Linux (Primary Pentesting OS)
* **Virtualization**: VirtualBox (Isolated Lab Network)
* **Hardware**: 
    * **Flipper Zero** + WiFi Dev Board (ESP32)
    * **Raspberry Pi** (Network Monitoring / Headless Pentest Node)
    * **Arduino Uno** & Modular Sensors
* **Safety**: Tutti i test sono eseguiti in ambienti isolati e per soli scopi educativi.

---

## 🚀 Projects & Experiments

### 🐬 Flipper Zero & WiFi Security
* **[Evil Portal - Rogue Access Point](./EvilPortal_Project/):** Test di phishing tramite Captive Portal. Creazione di una rete Wi-Fi fasulla per l'intercettazione di credenziali in ambienti di test (Metodo GET).
* **Sub-GHz Analysis:** Analisi di segnali radio e protocolli di comunicazione a corto raggio.

### 🍓 Raspberry Pi Projects
* **Headless Pentest Box:** Configurazione del Raspberry Pi come nodo remoto per il monitoraggio del traffico di rete e packet sniffing.
* **Network Security Audit:** Utilizzo del Pi per scansionare vulnerabilità interne alla rete del laboratorio.

### 🤖 Arduino & Electronics
* **01_wifi_scanner:** Utilizzo dell'interfaccia seriale per scansionare e listare reti Wi-Fi circostanti.
* **02_test_sensore_luce:** Test funzionale per il modulo sensore di luce LM393 (letture digitali e analogiche).
* **03_sequenza_led_crepuscolare:** Automazione di una sequenza temporizzata di 4 LED attivata dal livello di luminosità ambientale.

### 🔐 Password Cracking & Network Audit
* **Hydra Laboratory:** Test di brute-force contro protocolli SSH e FTP per analizzare la resistenza delle policy di password aziendali.

---

## ⚠️ Disclaimer
Tutti i progetti contenuti in questo repository sono realizzati esclusivamente per **scopi educativi e di Ethical Hacking**. L'autore non si assume alcuna responsabilità per l'uso improprio di queste informazioni. Ogni test è stato effettuato su dispositivi di proprietà dell'autore o con esplicito consenso.

---
**Status:** In continuo aggiornamento 🛠️
