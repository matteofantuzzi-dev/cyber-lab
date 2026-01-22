# Progetto: Secure DNS & Remote Access Lab
**Integrazione Pi-hole + Tailscale Mesh VPN**

## 🎯 Obiettivo
Realizzare un sistema di filtraggio DNS (Ad-blocking) centralizzato e un accesso remoto sicuro ai dispositivi della rete locale senza l'esposizione di porte pubbliche (Port Forwarding), superando le limitazioni hardware dei router consumer e degli extender Wi-Fi.

## 🛠️ Architettura Finale
Dopo una fase iniziale di test con WireGuard (PiVPN), l'architettura è stata evoluta in una **Mesh VPN** per garantire maggiore stabilità e sicurezza OpSec.

- **DNS Server**: Pi-hole (Local Sinkhole)
- **VPN Protocol**: Tailscale (basato su WireGuard)
- **Remote Access**: RDP over Tailscale (Desktop Remoto sicuro)
- **Network Path**: Router ZTE -> Ethernet Switch -> Raspberry Pi

## 📈 Evoluzione e Troubleshooting
Durante lo sviluppo è stato riscontrato un conflitto ARP/IP dovuto all'uso di un Wi-Fi Extender. 
1. **Problema**: L'extender creava instabilità nel Port Forwarding (UDP 51820).
2. **Soluzione**: Collegamento fisico via LAN allo switch principale e migrazione verso Tailscale.
3. **Risultato**: Accesso remoto garantito anche sotto reti CGNAT o dietro firewall restrittivi.

## ⚙️ Configurazione Tecnica
- **Interfaccia d'ascolto Pi-hole**: `Permit all origins` (per accettare richieste dal tunnel Tailscale).
- **Global DNS (Tailscale Admin)**: IP virtuale del Raspberry impostato come Nameserver primario con `Override Local DNS` attivo.
