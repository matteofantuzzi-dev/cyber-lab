# Analisi Dati Pi-hole

Questo modulo dimostra l'integrazione tra Python e database SQLite.
Il sistema interroga il file `/etc/pihole/pihole-FTL.db` per estrarre metriche di sicurezza senza sovraccaricare la dashboard web.

### Metriche Estratte:
- **Status 1, 4, 5**: Rappresentano query bloccate tramite Gravity, blacklist esplicite o filtri DNS esterni.
- **Timestamp Filtering**: Viene utilizzato il formato Unix timestamp per isolare esattamente gli ultimi 7 giorni di attività.
