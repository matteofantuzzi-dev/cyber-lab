import subprocess
from datetime import datetime

NTFY_TOPIC = "system_update"

def invia_notifica(titolo, messaggio, priorita="default"):
    comando = f'curl -s -o /dev/null -H "Title: {titolo}" -H "Priority: {priorita}" -d "{messaggio}" https://ntfy.sh/{NTFY_TOPIC}'
    subprocess.run(comando, shell=True)

def manutenzione_sistema():
    ora_inizio = datetime.now().strftime("%H:%M:%S")
    comandi = [
        ("Update", "sudo apt-get update"),
        ("Upgrade", "sudo apt-get upgrade -y"),
        ("Autoremove", "sudo apt-get autoremove -y"),
        ("Autoclean", "sudo apt-get autoclean")
    ]
    report = []
    successo = True

    for nome, cmd in comandi:
        res = subprocess.run(cmd, shell=True, capture_output=True, text=True)
        status = "✅ OK" if res.returncode == 0 else "❌ FAIL"
        if res.returncode != 0: successo = False
        report.append(f"{nome}: {status}")

    msg = "\n".join(report) + f"\n\nInizio: {ora_inizio}\nFine: {datetime.now().strftime('%H:%M:%S')}"
    invia_notifica("Sistema Aggiornato ✅" if successo else "Errore Sistema ⚠️", msg)
    print("Manutenzione conclusa.")

if __name__ == "__main__":
    manutenzione_sistema()
