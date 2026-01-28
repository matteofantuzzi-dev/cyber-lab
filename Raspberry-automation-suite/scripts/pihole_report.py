import sqlite3
import subprocess
from datetime import datetime, timedelta

DB_PATH = "/etc/pihole/pihole-FTL.db"
NTFY_TOPIC = "pihole_report"

def invia_notifica(titolo, messaggio):
    comando = f'curl -s -o /dev/null -H "Title: {titolo}" -d "{messaggio}" https://ntfy.sh/{NTFY_TOPIC}'
    subprocess.run(comando, shell=True)

def genera_report():
    settimana_fa = int((datetime.now() - timedelta(days=7)).timestamp())
    try:
        conn = sqlite3.connect(DB_PATH)
        c = conn.cursor()
        c.execute("SELECT COUNT(*) FROM queries WHERE status IN (1, 4, 5, 9, 10, 11) AND timestamp > ?", (settimana_fa,))
        bloccate = c.fetchone()[0]
        
        c.execute("SELECT domain, COUNT(*) as f FROM queries WHERE status IN (1, 4, 5) AND timestamp > ? GROUP BY domain ORDER BY f DESC LIMIT 1", (settimana_fa,))
        top_d = c.fetchone()
        
        c.execute("SELECT client, COUNT(*) as f FROM queries WHERE status IN (1, 4, 5) AND timestamp > ? GROUP BY client ORDER BY f DESC LIMIT 1", (settimana_fa,))
        top_c = c.fetchone()
        conn.close()

        msg = f"🛡️ Report Settimanale\n\n🚫 Bloccate: {bloccate}\n🌐 Top Threat: {top_d[0] if top_d else 'N/A'}\n📱 Client: {top_c[0] if top_c else 'N/A'}"
        invia_notifica("Pi-hole Security Stats 📊", msg)
        print("Report Generato con successo")
    except Exception as e:
        invia_notifica("Errore Report ❌", str(e))

if __name__ == "__main__":
    genera_report()
