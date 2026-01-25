#Codice python
# -----------------
import os
import time
import requests
import psutil
from datetime import datetime

# --- CONFIGURAZIONE ---
TOPIC = "IL_TUO_TOPIC_QUI" 
SOGLIA_TEMP = 75.0
SOGLIA_CPU = 95.0
SOGLIA_RAM = 90.0
WEB_FILE = "/var/www/html/temp.html"
LOG_FILE = "/home/pirasp/cyberlab-monitor/temp_history.csv"
# ----------------------

def invia_notifica(titolo, messaggio, tag):
    try:
        url = f"https://ntfy.sh/{TOPIC}"
        requests.post(url,
            data=messaggio.encode('utf-8'),
            headers={
                "Title": titolo.encode('utf-8'),
                "Priority": "5",
                "Tags": tag
            },
            timeout=10)
        return True
    except:
        return False

# Inizializzazione Log
if not os.path.exists(LOG_FILE):
    with open(LOG_FILE, "w") as f:
        f.write("Timestamp,Dettagli\n")

alert_temp_inviato = False
alert_cpu_inviato = False
alert_ram_inviato = False
ultimo_log_minuto = -1

print("--- MONITORAGGIO ATTIVO ---")

while True:
    try:
        # Raccolta Dati
        with open("/sys/class/thermal/thermal_zone0/temp", "r") as f:
            temp = float(f.read()) / 1000.0
        cpu_perc = psutil.cpu_percent(interval=1)
        ram_perc = psutil.virtual_memory().percent
        now = datetime.now()
        ts = now.strftime("%H:%M:%S")

        # 1. Gestione Notifiche
        if temp > SOGLIA_TEMP and not alert_temp_inviato:
            if invia_notifica("⚠️ CALORE", f"CPU a {temp}°C", "fire"): alert_temp_inviato = True
        elif temp <= SOGLIA_TEMP: alert_temp_inviato = False

        if cpu_perc > SOGLIA_CPU and not alert_cpu_inviato:
            if invia_notifica("🚨 CPU", f"Carico al {cpu_perc}%", "zap"): alert_cpu_inviato = True
        elif cpu_perc <= SOGLIA_CPU: alert_cpu_inviato = False

        # 2. Scrittura Log CSV (ogni minuto)
        if now.minute != ultimo_log_minuto:
            with open(LOG_FILE, "a") as f:
                f.write(f"{now.strftime('%Y-%m-%d %H:%M:%S')},T:{temp} C:{cpu_perc} R:{ram_perc}\n")
            ultimo_log_minuto = now.minute

        # 3. Aggiornamento Dashboard Web
        col_t = "red" if temp > SOGLIA_TEMP else "#00ff00"
        col_c = "red" if cpu_perc > SOGLIA_CPU else "#3498db"
        col_r = "red" if ram_perc > SOGLIA_RAM else "#f1c40f"

        html = f"""
        <html><head><meta charset="UTF-8"><script>setTimeout(function(){{location.reload();}}, 5000);</script>
        <style>body{{background:#121212;color:white;text-align:center;font-family:sans-serif;}}
        .box{{display:inline-block;margin:15px;padding:20px;border:1px solid #333;border-radius:10px;min-width:200px;}}
        .val{{font-size:40px;font-weight:bold;}}</style></head>
        <body><h1>Cyber-Lab System Monitor</h1>
        <div class="box"><div style="color:#888;">TEMP</div><div class="val" style="color:{col_t};">{temp}°C</div></div>
        <div class="box"><div style="color:#888;">CPU</div><div class="val" style="color:{col_c};">{cpu_perc}%</div></div>
        <div class="box"><div style="color:#888;">RAM</div><div class="val" style="color:{col_r};">{ram_perc}%</div></div>
        <p>Last check: {ts}</p></body></html>"""
        
        with open(WEB_FILE, "w") as f:
            f.write(html)

    except Exception as e:
        print(f"Errore: {e}")
    time.sleep(4)

