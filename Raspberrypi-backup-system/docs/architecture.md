# 🏛️ Architettura del Sistema e Scelte Tecniche

Questo documento descrive le decisioni ingegneristiche prese durante lo sviluppo del sistema di backup automatizzato per Raspberry Pi.

## 1. Logica Core: Perché Python?
Sebbene un semplice script Bash avrebbe potuto gestire il comando `tar`, è stato scelto **Python 3** per diverse ragioni strategiche:
* **Gestione degli Errori:** Python permette una gestione robusta delle eccezioni e il controllo dei codici di ritorno delle chiamate di sistema, evitando che lo script fallisca silenziosamente.
* **Integrazione API:** L'integrazione con l'API REST di **ntfy.sh** risulta più pulita e leggibile rispetto a complessi comandi curl concatenati in Bash.
* **Scalabilità:** Lo script è facilmente estensibile per includere rotazione dei log, sincronizzazione cloud (AWS/Dropbox) o monitoraggio hardware aggiuntivo.

## 2. Strategia di Storage: Montaggio Just-in-Time (JIT)
Per garantire l'integrità dei dati e la longevità dell'hardware, il sistema segue un approccio di **Montaggio JIT**:
* **Prevenzione Corruzione:** L'unità USB viene mantenuta smontata quando inattiva. Questo protegge il file system da corruzioni durante improvvisi cali di tensione o blackout, problemi comuni con gli alimentatori dei Raspberry Pi.
* **Sicurezza:** Un disco non montato è meno vulnerabile a cancellazioni accidentali o modifiche non autorizzate del sistema.
* **Flusso di Automazione:**
    1. Creazione del punto di montaggio (mount point).
    2. Montaggio della partizione hardware (`/dev/sda1`).
    3. Esecuzione delle operazioni di I/O (compressione e scrittura).
    4. Chiamata al comando `sync` per svuotare i buffer di scrittura.
    5. Smontaggio sicuro.



## 3. Sfide di Rete e Ottimizzazione
Durante lo sviluppo sono state riscontrate criticità nella stabilità della connessione SSH dovute alla topologia di rete (Raspberry Pi collegato via Ethernet a un WiFi Extender).

### La Sfida:
* **Latenza SSH:** Le fluttuazioni del segnale tra l'extender e il router principale causavano frequenti cadute della sessione.
* **Conflitto di Interfaccia:** L'attivazione simultanea di WiFi e Ethernet generava instabilità nel routing dei pacchetti.

### La Soluzione:
* **Power Management:** È stato disattivato il risparmio energetico del WiFi (`power_save off`) per evitare che il chip di rete entrasse in stato di standby.
* **Ottimizzazione Script:** La logica è stata progettata come **"fire and forget"**. Catturando l'output tramite `subprocess` e inviando aggiornamenti via `ntfy`, il sistema non richiede una sessione terminale attiva per completare il backup.
* **Hardening:** Sono state documentate procedure per bloccare interfacce instabili (`rfkill`) e dare priorità alla connessione cablata.

## 4. Integrazione Pi-hole
Invece di utilizzare il comando integrato `pihole -a -t` (Teleporter) — che può variare tra le versioni o fallire per permessi di root — il sistema esegue uno **Snapshot Diretto del File System**:
* **Target:** Cartelle `/etc/pihole` e `/etc/dnsmasq.d`.
* **Vantaggi:** Questo metodo cattura direttamente il database `gravity.db` (liste di blocco), `setupVars.conf` (impostazioni di rete) e le regole DNS personalizzate, garantendo un ripristino 1:1 anche in caso di reinstallazione del software.

---
**Nota:** Questa architettura privilegia l'affidabilità rispetto alla velocità, garantendo che l'utente sia sempre informato sull'esito del backup, anche in condizioni di rete instabile.
