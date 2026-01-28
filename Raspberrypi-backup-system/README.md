# 🛡️ Raspberry Pi Automated Backup System & Pi-hole Protection

[![Python Version](https://img.shields.io/badge/python-3.9%2B-blue.svg)](https://www.python.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/platform-Raspberry%20Pi-red.svg)](https://www.raspberrypi.org/)

Un sistema di backup robusto e intelligente progettato per **Raspberry Pi OS**, focalizzato sulla sicurezza dei dati personali e delle configurazioni critiche di **Pi-hole**. Il sistema integra notifiche push in tempo reale per monitorare lo stato del backup senza dover accedere al terminale.



## 🌟 Caratteristiche Principali

* **Backup "Zero-Error" di Pi-hole**: Salvataggio diretto dei database (`gravity.db`) e delle configurazioni DNS, superando i limiti di permessi del comando Teleporter standard.
* **Gestione Dinamica dell'Hardware**: Montaggio e smontaggio automatico dell'unità USB per prevenire la corruzione del file system dovuta a sbalzi di tensione.
* **Notifiche Push istantanee**: Integrazione con l'API di **ntfy.sh** per ricevere notifiche su smartphone (iOS/Android) riguardo a:
    * Esito dell'operazione (Successo/Errore).
    * Dimensione finale dell'archivio compresso.
    * Timestamp dell'esecuzione.
* **Manutenzione Automatica**: Script di cleanup integrato per mantenere solo gli ultimi 7 giorni di backup e ottimizzare lo spazio sulla chiavetta.

## 🛠️ Stack Tecnologico

* **Linguaggio**: Python 3.x
* **OS**: Raspberry Pi OS (Debian based)
* **Notifiche**: ntfy.sh (Pub-Sub via HTTP)
* **Archiviazione**: Tar / Gzip
* **Automazione**: Cron Jobs

## 📂 Struttura del Progetto

```text
├── 📂 scripts
│   ├── backup_manager.py      # Core logic del backup
│   └── cleanup_backups.py     # Gestione rotazione e pulizia file vecchi
├── 📂 config
│   └── crontab_example.txt    # Esempi di programmazione oraria
├── 📂 docs
│   ├── architecture.md        # Analisi tecnica e risoluzione problemi di rete
│   └── installation.md        # Guida passo-passo al setup
└── README.md
