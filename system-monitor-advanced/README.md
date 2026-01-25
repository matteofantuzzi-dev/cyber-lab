# 🛡️ Raspberry Pi Advanced Monitor

Evoluzione del sistema di monitoraggio termico con integrazione del controllo risorse (CPU/RAM) e notifiche push.

## 🚀 Modulo Monitoraggio Risorse (CPU, RAM, TEMP)
In questa fase ho evoluto il monitor semplice della temperatura in un sistema di controllo completo del Raspberry Pi.

### **Cosa fa questo modulo:**
* **Monitoraggio Triplo**: Controlla in tempo reale Temperatura (°C), Carico CPU (%) e Utilizzo RAM (%).
* **Dashboard Dinamica**: Una pagina web che cambia colore (da verde/blu a rosso) se i parametri superano i limiti.
* **Allerta Intelligente**: Notifiche push immediate sul telefono tramite **ntfy.sh**.
* **Gestione Errori Unicode**: Implementato encoding UTF-8 per supportare le Emoji (🚨, ⚠️) nelle notifiche, risolvendo i problemi di codifica `latin-1`.

---

## 🛠️ Architettura del Sistema
Il sistema raccoglie i dati dai sensori hardware e li smista su tre canali diversi contemporaneamente:



1.  **Web**: Genera un file HTML statico per la visualizzazione rapida.
2.  **Log**: Alimenta un file CSV per lo storico delle prestazioni.
3.  **Push**: Interroga il server ntfy.sh solo in caso di superamento soglie.

## 📊 Soglie di Allerta impostate
| Parametro | Soglia | Segnale Visivo | Tag Notifica |
| :--- | :--- | :--- | :--- |
| **Temperatura** | 75°C | Rosso | `fire` |
| **Carico CPU** | 95% | Rosso | `zap` |
| **Memoria RAM** | 90% | Rosso | `warning` |

## ⚙️ Installazione rapida
1.  Posizionare `monitor.py` in `/home/pirasp/cyberlab-monitor/`.
2.  Installare le dipendenze: `pip install psutil requests`.
3.  Configurare il file `.service` in `/etc/systemd/system/` per l'avvio automatico.
4.  Comando per il controllo log: `sudo journalctl -u raspberry-monitor.service -f`.
