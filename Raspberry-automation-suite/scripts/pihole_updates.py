import subprocess
import sys
from datetime import datetime

NTFY_TOPIC = "pihole_update"

def invia_notifica(titolo, messaggio, priorita="default"):
    comando = f'curl -s -o /dev/null -H "Title: {titolo}" -H "Priority: {priorita}" -d "{messaggio}" https://ntfy.sh/{NTFY_TOPIC}'
    subprocess.run(comando, shell=True)

def esegui_pi(nome, comando):
    res = subprocess.run(comando, shell=True, capture_output=True, text=True)
    if res.returncode == 0:
        invia_notifica(f"Pi-hole {nome} ✅", f"Completato alle: {datetime.now().strftime('%H:%M:%S')}")
    else:
        err = (res.stderr.strip() or res.stdout.strip())[:150]
        invia_notifica(f"Pi-hole {nome} ❌", f"Errore:\n{err}", "high")

if __name__ == "__main__":
    azione = sys.argv[1] if len(sys.argv) > 1 else ""
    if azione == "update":
        esegui_pi("Aggiornamento", "sudo pihole -up --unattended")
    elif azione == "gravity":
        esegui_pi("Gravity", "sudo pihole -g")
