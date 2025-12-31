# 📡 ESP-01 WiFi Scanner (IoT Security Lab)

Parte dei miei esperimenti nel repository `cyber-lab`. Questo progetto dimostra l'interfacciamento tra Arduino e il modulo ESP8266 per l'analisi delle reti wireless locali.

## 🛠️ Configurazione Hardware
- **MCU:** Arduino Uno
- **WiFi Module:** ESP-01 (ESP8266) con adattatore per breadboard
- **Pins:** Pin 2 (RX) e Pin 3 (TX) tramite libreria `SoftwareSerial`

## 💡 Troubleshooting & Soluzioni
Durante lo sviluppo ho riscontrato problemi di "caratteri sporchi" (garbage data) sul monitor seriale.
- **Problema:** La `SoftwareSerial` non gestisce bene i 115200 baud (velocità di fabbrica dell'ESP).
- **Soluzione:** Ho riconfigurato il modulo permanentemente a **9600 baud** utilizzando il comando `AT+UART_DEF=9600,8,1,0,0`. Questo ha reso la scansione delle reti perfettamente leggibile.

## 🔍 Analisi Reti (Comandi AT)
I comandi principali testati in questo lab:
- `AT+CWMODE=1`: Imposta il modulo in modalità stazione (client).
- `AT+CWLAP`: Esegue il listing degli Access Point disponibili, mostrando SSID, potenza del segnale (RSSI) e MAC Address.

---
*Laboratorio focalizzato sulle basi dell'hardware hacking e delle comunicazioni seriali.*
