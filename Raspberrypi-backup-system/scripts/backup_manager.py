import os
import subprocess
from datetime import datetime

# --- Configuration ---
USB_DEVICE = "/dev/sda1"
MOUNT_POINT = "/media/pirasp/BACKUP"
BACKUP_SOURCE = "/home/pirasp"
NTFY_TOPIC = "backup_raspberrypi"
DATE_STR = datetime.now().strftime("%Y-%m-%d")
FILENAME = f"backup_total_{DATE_STR}.tar.gz"

def send_notification(title, message, priority="default"):
    """Sends push notification via ntfy.sh"""
    cmd = f'curl -s -H "Title: {title}" -H "Priority: {priority}" -d "{message}" https://ntfy.sh/{NTFY_TOPIC}'
    subprocess.run(cmd, shell=True, capture_output=True)

def run_backup():
    os.makedirs(MOUNT_POINT, exist_ok=True)
    
    # Mount USB
    print(f"Mounting {USB_DEVICE}...")
    subprocess.run(f"sudo mount {USB_DEVICE} {MOUNT_POINT}", shell=True)
    
    # Compression (User Home + Pi-hole Configs)
    print("Compressing data...")
    tar_cmd = (
        f"sudo tar -czf {MOUNT_POINT}/{FILENAME} "
        f"--exclude='{BACKUP_SOURCE}/.cache' "
        f"{BACKUP_SOURCE} /etc/pihole /etc/dnsmasq.d"
    )
    
    result = subprocess.run(tar_cmd, shell=True, capture_output=True)
    
    if result.returncode == 0:
        # Get file size
        res_dim = subprocess.run(f"du -h {MOUNT_POINT}/{FILENAME}", shell=True, capture_output=True, text=True)
        size = res_dim.stdout.split()[0] if res_dim.stdout else "N/A"
        send_notification("Backup Success ✅", f"Size: {size}")
    else:
        send_notification("Backup Failed ❌", "Check system logs", "high")

    # Safety unmount
    subprocess.run("sync", shell=True)
    subprocess.run(f"sudo umount {MOUNT_POINT}", shell=True)

if __name__ == "__main__":
    run_backup()
