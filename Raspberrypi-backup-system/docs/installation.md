# 🛠️ Guida all'Installazione e Configurazione

Questa guida ti accompagnerà nel setup completo del sistema di backup sul tuo Raspberry Pi.

## 1. Prerequisiti Hardware
* Raspberry Pi (testato su Pi 3/4).
* Unità USB (Pendrive o SSD esterno) formattata in FAT32 o EXT4.
* Alimentatore stabile (minimo 3A) per gestire il carico della porta USB durante la scrittura.

## 2. Preparazione della Chiavetta USB
Per garantire che lo script trovi sempre l'unità, dobbiamo identificare il device.
1. Collega la chiavetta al Raspberry.
2. Identifica il percorso con: `lsblk` (solitamente è `/dev/sda1`).
3. Crea il punto di montaggio:
   ```bash
   sudo mkdir -p /media/pirasp/BACKUP
   sudo chown pirasp:pirasp /media/pirasp/BACKUP
