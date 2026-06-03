# Guida al Funzionamento: Modulo Geiger per Flipper Zero

## 🔬 Come funziona il Modulo?

Il cuore di questo modulo è il **tubo Geiger-Müller (modello J305)**, un cilindro sigillato contenente una miscela di gas nobili a bassa pressione. 

1. **Iniezione di Alta Tensione**: Il Flipper Zero fornisce un'alimentazione iniziale a 5V tramite i pin GPIO. Il circuito interno del modulo eleva questa tensione portandola a circa **400V**, applicandola all'asse centrale del tubo.
2. **Ionizzazione del Gas**: Quando una particella energetica (radiazione Beta o Gamma) attraversa la parete del tubo e colpisce il gas interno, lo ionizza separando gli elettroni dai nuclei.
3. **L'impulso Elettrico**: Sotto l'effetto dei 400V, gli elettroni scattano verso l'anodo generando una scarica elettrica brevissima.
4. **Il "Click" sul Flipper**: Questa scarica viene isolata in sicurezza e inviata al processore del Flipper Zero sotto forma di impulso digitale, che l'applicazione traduce in un segnale visivo ed acustico.

---

## 📊 Interpretazione dei Valori e Fondo Naturale

Come si nota nella quarta foto del progetto, lo schermo del Flipper mostra l'andamento delle radiazioni in tempo reale.

### Cosa significano le unità di misura?
* **CPS (Counts Per Second)**: Il numero di particelle rilevate in un singolo secondo. Nell'ambiente normale di casa questo valore è quasi sempre fisso a `0 cps`, interrotto da picchi sporadici di `1 cps`.
* **CPM (Counts Per Minute)**: Il numero di impulsi contati nell'arco di un minuto intero. È il valore più stabile per calcolare la radiazione di fondo.

### Quali sono i valori normali in un ambiente sicuro?
In un normale ambiente domestico o all'aperto, privo di sorgenti radioattive artificiali, il contatore registrerà la **Radiazione di Fondo Naturale** (generata da raggi cosmici e isotopi stabili presenti nel terreno).

| Valore CPM | Livello di Radiazione | Significato e Stato Ambientale |
|---|---|---|
| **10 - 40 CPM** | **~0.08 - 0.15 µSv/h** | **Fondo Naturale Normale**: Valore perfettamente sicuro. Corrisponde alla lettura standard visibile nella foto di test (`26 cpm`). |
| **40 - 100 CPM** | **~0.15 - 0.30 µSv/h** | **Lieve incremento naturale**: Comune vicino a strutture massicce in granito, porfido, mattoni vintage o in alta montagna. |
| **> 150 CPM** | **> 0.50 µSv/h** | **Anomalia / Presenza di Sorgente**: Valore tipico quando si avvicina il sensore a sorgenti di test (es. sale iposodico ricco di Potassio-40, vecchi orologi al radio o minerali di uranite). |

---

## 🛠️ Note di Configurazione Software

Come mostrato nella seconda e terza immagine documentata:
1. Prima di lanciare l'applicazione del contatore Geiger, è necessario recarsi su `GPIO > Manual Control` e attivare la voce **`5V on GPIO < ON >`**. Questo permette al modulo di accendersi e generare l'alta tensione necessaria al tubo.
2. Successivamente, avviando l'applicazione dedicata, l'interfaccia configurerà il monitoraggio grafico ad impulsi (istogramma a barre verticali), dove ogni linea verticale rappresenta una particella catturata dal sensore.
