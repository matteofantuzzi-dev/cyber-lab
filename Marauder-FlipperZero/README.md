# Wi-Fi Security Audit: Handshake Capture & Cracking con Flipper Zero

Questo progetto documenta l'intero processo di analisi di sicurezza su una rete Wi-Fi (WPA2) utilizzando un Flipper Zero e strumenti di recupero password su PC.

## 📋 Fasi del Progetto (Dalla A alla Z)

### Fase 1: Setup dell'Hardware
- **Dispositivo:** Flipper Zero.
- **Modulo:** Wi-Fi Dev Board (ESP32-S2).
- **Firmware:** WiFi Marauder (installato sulla Dev Board).

### Fase 2: Ricognizione e Scansione
1. Avvio dell'app **WiFi Marauder**.
2. Esecuzione di `Scan APs` per individuare le reti vicine.
3. Identificazione della rete target (SSID) e del relativo canale di trasmissione (**Canale 8**).
4. Selezione del target tramite comando `Select` basato sull'ID della lista.

### Fase 3: Attacco e Cattura (Sniffing)
1. Impostazione del canale fisso tramite il menu `Channel`.
2. Avvio dello sniffing in modalità `Sniff -> Raw` o `Targeted -> Active`.
3. Esecuzione di un attacco di **Deauthentication** per forzare il distacco dei dispositivi connessi.
4. Intercettazione del **4-way handshake** (pacchetti EAPOL) durante il ricollegamento automatico del client.
5. Verifica della cattura tramite il contatore `EAPOL: 1` sul display del Flipper.

### Fase 4: Esportazione e Conversione
1. Trasferimento del file `.pcap` dalla MicroSD del Flipper al PC.
2. Utilizzo di strumenti online (come `cap2hashcat`) per convertire il file PCAP nel formato leggibile da Hashcat (**Format .hc22000**).

### Fase 5: Analisi e Password Recovery
1. Utilizzo di **Hashcat** su PC Windows 11.
2. Creazione/Utilizzo di una **Wordlist** (es. `rockyou.txt` o liste personalizzate).
3. Comando eseguito: 
   `.\hashcat.exe -m 22000 cattura.hc22000 wordlist.txt`
4. Risultato ottenuto: **Status: Cracked**.

## 📊 Conclusioni
Il test ha dimostrato che una password semplice può essere individuata in pochi secondi una volta ottenuto l'handshake, confermando l'importanza di utilizzare chiavi WPA2/WPA3 complesse.
