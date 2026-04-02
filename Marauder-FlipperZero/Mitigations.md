# Come proteggersi da attacchi di Deauthentication e Sniffing

Durante i test è emerso quanto sia semplice intercettare un handshake. Ecco le contromisure consigliate:

1. **Password Complesse:** Utilizzare password di almeno 16 caratteri con simboli, numeri e maiuscole. Una password complessa rende inutile l'uso di Hashcat con wordlist standard come RockYou.
2. **Protocollo WPA3:** Se il router lo supporta, passare a WPA3. Questo protocollo protegge meglio l'handshake (tramite SAE) e rende molto più difficile la decifrazione offline.
3. **PMF (Protected Management Frames):** Attivare i "Frame di gestione protetti" nelle impostazioni del router. Questo impedisce al Flipper Zero di "buttare fuori" i dispositivi dalla rete (attacco di Deauth).
4. **Disattivare il WPS:** Il tasto WPS è spesso una vulnerabilità nota. È consigliabile disattivarlo.
