# Flipper Zero: WiFi Evil Portal & Credential Capture Test

## Descrizione
Questo progetto è un Proof of Concept (PoC) realizzato a scopo educativo e di ricerca sulla sicurezza informatica. Dimostra la tecnica del **Rogue Access Point** (Access Point Maligno) e del **Phishing tramite Captive Portal**.

L'obiettivo è sensibilizzare gli utenti sul pericolo delle reti Wi-Fi aperte e sulla facilità con cui le credenziali possono essere intercettate se inserite in pagine web non protette (HTTP).

## Hardware Utilizzato
* **Flipper Zero**: Utilizzato come interfaccia di controllo e database per i log.
* **WiFi Dev Board (ESP32)**: Utilizzata per trasmettere il segnale Wi-Fi e ospitare il server DNS/Web.
* **Firmware**: WiFi Marauder / Evil Portal.

## Analisi Tecnica
1.  **Impostazione SSID**: Il file `ap.config.txt` definisce il nome della rete broadcast.
2.  **Captive Portal**: Il file `index.html` viene servito automaticamente a ogni dispositivo che si connette grazie al DNS Hijacking (ogni richiesta viene reindirizzata a `172.0.0.1`).
3.  **Data Logging**: Le variabili inviate tramite il metodo `GET` dal form HTML vengono catturate dal modulo ESP32 e salvate in formato testuale.

## Risultati del Test
Durante il test, un dispositivo mobile si è connesso alla rete "Test_WiFi". Una volta inserite le credenziali nella pagina di "Aggiornamento Firmware" simulata, i dati sono stati registrati con successo come mostrato nel file di log.
