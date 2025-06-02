 1. Program: Signalno Upravljanje i Obrada Fajlova

 Opis
Program simulira obradu podataka iz datoteka `status.txt` i `obrada.txt`, a koristi signale za upravljanje ponašanjem programa tokom izvršavanja.

Funkcionalnosti:
- Obrada brojeva iz fajlova: računa kvadrat i upisuje rezultat.
- Koristi signale:
  - `SIGINT` (Ctrl+C) → korisniku nudi meni s opcijama:
    - prekid programa
    - siguran izlaz
    - ispis trenutnog statusa
    - nastavak izvršavanja
  - `SIGTERM` → sigurno zaustavlja program
  - `SIGUSR1` → ispis trenutnog statusa
- Zapisuje status i obradu brojeva u odgovarajuće fajlove.

Cilj:
Pokazati kako upravljati asinhronim signalima u C-u i raditi s fajlovima u stvarnom vremenu.


2. Program: Dekkerov Algoritam sa Zajedničkom Memorijom

Opis
Ovaj program implementira Dekkerov algoritam za međusobno isključivanje između dva procesa koristeći zajedničku memoriju (shared memory).

Funkcionalnosti:
- Kreira dva procesa pomoću `fork()`.
- Svaki proces više puta pokušava ući u tzv. kritični odsjek.
- Korištenjem Dekkerovog algoritma osigurava se da **nikada oba procesa ne budu istovremeno u kritičnom dijelu.
- Komunikacija između procesa vrši se preko segmenta zajedničke memorije (`shmget`, `shmat`, `shmdt`).
- Signal `SIGINT` (Ctrl+C) omogućava čišćenje memorije i siguran izlaz.

Cilj:
Demonstrirati međuprocesnu sinhronizaciju pomoću algoritma bez semafora i bez trke za resursima.


3. Rezervacija stolova – Lamportov algoritam

Opis

Program simulira rezervaciju stolova u restoranu pomoću Lamportovog algoritma za međusobno isključivanje. 

Funkcionalnosti

- Korisnik unosi broj dretvi (korisnika) i broj stolova.
- Svaka dretva pokušava rezervirati nasumično odabrani stol.
- Ako je stol slobodan, dretva ga rezervira.
- Ako je stol zauzet, dretva ispisuje poruku o neuspješnoj rezervaciji.
- Program ispisuje trenutno stanje svih stolova.
- Kada su svi stolovi zauzeti, program završava.
- Korišten je Lamportov algoritam za međusobno isključivanje među dretvama (bez mutexa ili semafora).

Cilj:
Cilj zadatka je demonstrirati međusobno isključivanje među dretvama koristeći Lamportov pristup i simulirati konkurentnu rezervaciju zajedničkih resursa (stolova) bez konflikta i kolizije.


4. Vrtuljak – Upravljanje pristupom pomoću semafora

Opis
Program simulira rad vrtuljka s ograničenim brojem sjedećih mjesta koristeći POSIX semafore za kontrolu pristupa posjetitelja. Vrtuljak prima najviše `N = 5` posjetitelja odjednom, a ostatak čeka na slobodno mjesto. Kada su sva mjesta popunjena, vrtuljak se "okreće", a zatim se sjedeća mjesta ponovno oslobađaju.

Funkcionalnosti

- Vrtuljak ima `N = 5` mjesta koja posjetitelji mogu zauzeti.
- Pokreće se jedan proces koji upravlja vrtuljkom (`vrtuljak`).
- Kreira se `M = 15` posjetitelja (procesa) koji čekaju na ulaz u vrtuljak.
- Svaki posjetitelj:
  - Čeka slobodno mjesto pomoću semafora (`sem_wait`).
  - Kada uđe u vrtuljak, ostaje unutar njega određeno vrijeme (3 sekunde).
- Proces `vrtuljak`:
  - Kontinuirano provjerava broj slobodnih mjesta pomoću `sem_getvalue`.
  - Kada su sva mjesta zauzeta, simulira vožnju (3 sekunde).
  - Po završetku vožnje oslobađa svih `N` mjesta pomoću `sem_post`.
- Semafor se inicijalizira i uništava u glavnom procesu.
- Korišten je named semafor (`sem_open`) radi dijeljenja semafora među procesima.

Cilj

Cilj programa je demonstrirati sinkronizaciju među višestrukim procesima pomoću POSIX semafora. Program simulira situaciju gdje je broj dostupnih resursa (sjedećih mjesta) ograničen i višestruki korisnici (posjetitelji) ih konkurentno pokušavaju koristiti. Vrtuljak se aktivira tek kad su sva mjesta popunjena, čime se prikazuje koordinacija i pravilno upravljanje pristupom zajedničkom resursu.


5. Filozofi – Problem filozofa s semaforima
Opis
Program simulira problem pet filozofa oko okruglog stola koristeći POSIX semafore za sprječavanje mrtve petlje. Svaki filozof mora uzeti dvije vilice da bi jeo.

Funkcionalnosti
5 filozofa (dretvi) i 5 viličica
Svaki filozof:
Mislí → postane gladan → pokuša uzeti vilice → jede → vraća vilice

Korišten semafor mutex za zaštitu kritične sekcije

Funkcije test(), uzima_vilicu() i vrati_vilice() upravljaju stanjem filozofa

Cilj
Demonstrirati pravilnu sinkronizaciju dretvi kako bi se izbjegli:
Mrtva petlja (deadlock)
Izgladnjivanje (starvation)

Program pokazuje kako semafori omogućuju sigurno dijeljenje resursa (viličica) između više dretvi.



