import os
import time

BACKUP_DIR = "/media/pirasp/BACKUP"
DAYS_TO_KEEP = 7

def cleanup():
    # Monta la chiavetta prima di pulire
    os.system("sudo mount /dev/sda1 /media/pirasp/BACKUP")
    
    now = time.time()
    for f in os.listdir(BACKUP_DIR):
        file_path = os.path.join(BACKUP_DIR, f)
        # Se il file è più vecchio di 7 giorni, cancellalo
        if os.stat(file_path).st_mtime < now - (DAYS_TO_KEEP * 86400):
            if f.endswith(".tar.gz"):
                os.remove(file_path)
                print(f"Deleted old backup: {f}")
    
    os.system("sudo umount /media/pirasp/BACKUP")

if __name__ == "__main__":
    cleanup()
