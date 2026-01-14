# 🛡️ Raspberry Pi Password Manager (Vaultwarden + Tailscale)

Questa repository contiene la configurazione completa per ospitare un'istanza privata di **Vaultwarden** (Bitwarden) su Raspberry Pi. Il sistema è reso sicuro e accessibile globalmente tramite **Tailscale**, eliminando la necessità di aprire porte sul router o configurare DNS dinamici complessi.

## 🏗️ Architettura
- **Server:** Vaultwarden (Rust implementation of Bitwarden).
- **Containerizzazione:** Docker & Docker Compose.
- **Rete & SSL:** Tailscale (Mesh VPN) + Tailscale Serve (HTTPS/TLS automatico).

## 🚀 Installazione e Configurazione

### 1. Preparazione Ambiente
Assicurarsi che Docker e Tailscale siano installati sul Raspberry Pi.
```bash
# Crea la directory di lavoro
mkdir ~/vaultwarden-server && cd ~/vaultwarden-server
