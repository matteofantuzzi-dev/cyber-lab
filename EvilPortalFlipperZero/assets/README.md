## Demo Walkthrough

Ecco la sequenza tecnica del test:

### 1. Setup dell'Hardware
Il Flipper Zero viene collegato alla WiFi Dev Board (ESP32). Il firmware viene avviato, attivando i server DNS, HTTP e Captive Portal.

![Flipper Setup](assets/01_setup_flipper.png)

### 2. Rilevamento della Rete
Il dispositivo "vittima" scansiona le reti Wi-Fi e rileva la nostra rete aperta chiamata `Test_WiFi`.

![Network Broadcast](assets/02_network_broadcast.png)

### 3. Visualizzazione del Captive Portal
Una volta connesso, il dispositivo reindirizza automaticamente l'utente al portale di autenticazione fasullo ospitato sul Flipper.

![Captive Portal](assets/03_captive_portal.png)

### 4. Inserimento dei Dati
L'utente, fidandosi del portale, inserisce le sue credenziali.

![Data Input](assets/04_data_input.png)

### 5. Cattura dei Dati
I dati inseriti appaiono istantaneamente sullo schermo del Flipper Zero, confermando il successo dell'attacco.

![Capture Success](assets/05_capture_success.png)
