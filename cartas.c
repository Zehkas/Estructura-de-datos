#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void genera_baraja(int ba[][2]);
void ver_baraja(int ba[][2]);

int main(){
    int ba[52][2];
    genera_baraja(ba);

    ver_baraja(ba);

    return 0;
}

void genera_baraja(int ba[][2]){
    int i;
    srand(time(NULL));
    
    for (i = 0; i < 52; i++){
        ba[i][0] = i + 1;
        ba[i][1] = rand()%5; // ba[i][1] define el tipo, 1 = Picas, 2 = Corazones, 3 = Rombos, 4 = Treboles 
    }
}


void ver_baraja(int ba[][2]){
    int i;
    for (i = 0; i < 52; i++){
        printf("Numero: %2d Tipo: %2d\n", ba[i][0], ba[i][1]); 
    }
}