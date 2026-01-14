# Progetto Good Night - Arduino Cyber-Lab

Sistema di automazione che attiva una sequenza di luci e un messaggio su display LCD quando viene rilevata l'oscurità.

## Componenti
- **Sensore**: Fotoresistenza (LDR) su Pin 7.
- **Luci**: 4 LED su Pin 9, 10, 11, 12.
- **Display**: LCD 16x2 I2C (SDA su A4, SCL su A5).

## Funzionamento
1. Al buio i LED si accendono in cascata.
2. Al termine, i LED si spengono e il display mostra "GOOD NIGHT".
3. Dopo 4 secondi il display si oscura per risparmio energetico.
4. Il sistema si resetta automaticamente al ritorno della luce.

## Ottimizzazioni
È stata ridotta la frequenza del bus I2C a 10kHz e implementata la stampa a caratteri singoli per ovviare a problemi di instabilità nei collegamenti jumper.
