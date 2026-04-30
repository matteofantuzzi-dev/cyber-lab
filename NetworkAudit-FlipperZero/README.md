# Flipper Zero - Ethernet Networking Audit (W5500)

> **⚠️ DISCLAIMER: A SOLO SCOPO EDUCATIVO**  
> Tutte le informazioni, i test e i log contenuti in questo repository sono pubblicati esclusivamente a scopo didattico e di studio della sicurezza delle reti. L'autore non si assume alcuna responsabilità per l'uso improprio di queste informazioni. Ogni test è stato eseguito su una rete privata di proprietà dell'autore.

Questo repository documenta i test di analisi di rete effettuati con il **Flipper Zero** e il modulo **Ethernet W5500** utilizzando il firmware **Momentum**.

---

## 📸 Galleria del Progetto

| Setup Fisico | Configurazione di Rete |
| :---: | :---: |
| ![Setup Fisico](setup_fisico.jpg) | ![Configurazione IP](config_ip.jpg) |
| *Modulo W5500 collegato tramite extender.* | *Configurazione manuale dei parametri di rete.* |

| Risultato Discovery | Port Scan Audit |
| :---: | :---: |
| ![SSDP Result](discovery_ssdp.jpg) | ![Port Scan](port_scan.jpg) |
| *Identificazione router locale via SSDP.* | *Analisi porte aperte per verifica servizi.* |

---

## 🛠 Specifiche Tecniche
*   **Hardware:** Flipper Zero + Ethernet Board (HanRun HR961160C).
*   **Firmware:** Momentum (Custom Firmware).
*   **Alimentazione:** GPIO 5V abilitato.
*   **Network Target:** Rete locale privata (Indirizzi IP oscurati per privacy).

## 🚀 Test Eseguiti

### 1. Network Mapping (ARP Scan)
Rilevamento degli host attivi nel segmento di rete locale per verificare la corretta assegnazione dell'indirizzo IP del Flipper.

### 2. Service Discovery (SSDP)
Identificazione del gateway principale e dei servizi UPnP attivi.
*   **Device Found:** Router Brand (Huawei)
*   **Info:** Linux UPnP/1.0.

### 3. Vulnerability Audit (Port Scanning)
Eseguita scansione "Top 100" per identificare servizi potenzialmente esposti:
*   **DNS Service:** Identificato su porta standard 53.
*   **Web Management:** Identificato su porte 80/443.

---

## 📂 Struttura Repository
* `README.md` - Documentazione e Disclaimer.
* `network_test_log.txt` - Log tecnico dei test (IP Anonymized).
* `/img` - Screenshot delle operazioni.
