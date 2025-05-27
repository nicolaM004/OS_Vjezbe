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
