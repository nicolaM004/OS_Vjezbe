#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <string.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <pthread.h>

#define SHARED_MEMORY_SIZE (0x6400) // Velicina zajednicke memorije (25600 bajtova)

int segment_Id; // ID segmenta zajednicke memorije
int *sh_mem;    // Pokazivac na zajednicku memoriju

// Funkcija koja se poziva kada se primi signal SIGINT (npr. Ctrl+C)
void brisi(){
    printf("Signal primljen — gasi sve i brise memoriju\n");
    shmdt(sh_mem);                         // Odspaja proces od zajednicke memorije
    shmctl(segment_Id, IPC_RMID, NULL);   // Brise segment zajednicke memorije
    exit(0);                               // Gasi program
}

void main(){
    // Kreiranje segmenta zajednicke memorije
    segment_Id = shmget(IPC_PRIVATE, SHARED_MEMORY_SIZE, IPC_CREAT | 0660);

    // Spajanje procesa na zajednicku memoriju
    sh_mem = (int*) shmat(segment_Id, NULL, 0);

    // Beskonacna petlja — program stalno stvara novi proces
    while(1){
        if(fork() == 0){ // Ako je u dijete procesu
            *sh_mem = 1; // Dijete upisuje vrijednost 1 u zajednicku memoriju
            printf("Dijete upisalo: %d\n", *sh_mem);
            sleep(3); // Simulacija obrade — pauza 3 sekunde
            printf("Dijete vidi u memoriji: %d\n", *sh_mem);
            exit(0); // Dijete zavrsava
        }

        // Roditeljski proces
        signal(SIGINT, brisi); // Postavlja signal handler za Ctrl+C

        *sh_mem = 2; // Roditelj upisuje vrijednost 2 u memoriju
        printf("Roditelj upisao: %d\n", *sh_mem);
        sleep(3); // Pauza da se simulira rad
        printf("Roditelj vidi u memoriji: %d\n", *sh_mem);

        wait(NULL); // Ceka da dijete zavrsi
    }
}

