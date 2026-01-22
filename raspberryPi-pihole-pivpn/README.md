# Progetto: Ad-Blocking VPN (Pi-hole + PiVPN)

## Descrizione
Realizzazione di un server domestico su Raspberry Pi per il filtraggio del traffico DNS (Pi-hole) e accesso sicuro dall'esterno tramite protocollo WireGuard (PiVPN).

## Stack Tecnologico
- **Hardware**: Raspberry Pi collegato via LAN.
- **OS**: Raspberry Pi OS (Debian based).
- **Software**: Pi-hole, PiVPN (WireGuard).
- **Network**: Router ZTE con Port Forwarding.

## Diario di Configurazione
- **Step 1**: Installazione Pi-hole e configurazione IP statico su interfaccia `eth0` (`192.168.8.203`).
- **Step 2**: Installazione PiVPN e generazione profilo client WireGuard.
- **Step 3**: Configurazione Virtual Server su Router ZTE (Porta UDP 51820).
- **Issue riscontrata**: Problemi di instradamento dovuti all'uso di un Wi-Fi Extender tra Raspberry e Router.
- **Soluzione prevista**: Collegamento diretto LAN al router principale per eliminare conflitti ARP/IP e latenza dell'extender.

## Comandi Utili
- Verifica VPN: `pivpn -c`
- Generazione QR: `pivpn -qr`
- Stato Pi-hole: `pihole status`
