#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void lectura(int array[], int maximo, char[]);
void burbuja(int array[], int contador);
void shell(int array[], int contador);
void swap(int* a, int* b);
int particion (int array[], int bajo, int alto);
void quickSort(int array[], int bajo, int alto);


//Programa, Algoritmo, Forma de los datos, Cantidad 
int main(int argc, char *argv[]){
    //argv[i], i = 0: nombre del programa, i = 1: primer argumento y sucesivamente
    time_t t_1, t_2;
    int maximo = atoi(argv[3]); //atoi convierte un char en un int
    int array[maximo], contador;
    lectura(array, maximo, argv[2]);

    for(contador = 10000; contador <= maximo; contador = contador + 10000){

    t_1 = time(NULL);

    if (strcmp(argv[1], "burbuja") == 0){
        burbuja(array, contador);
    }
    else if (strcmp(argv[1], "shell") == 0){
        shell(array, contador);
    }
    else if (strcmp(argv[1], "quick") == 0){
        quickSort(array, 0, contador-1);
    }
    t_2 = time(NULL);

    printf("%d;%lf\n", contador, difftime(t_2, t_1));
    }

    return 0;
}

void lectura(int array[], int n, char tipo[]){
    FILE *entrada = fopen(tipo, "r");
    int i = 0;

    for(i = 0; i < n ; i++){
        int numero;
        fscanf(entrada, "%d", &numero);
        array[i] = numero;
    }

    fclose(entrada);
}

void burbuja(int array[], int contador){

    int i, j, aux;
    for(i = 0; i < contador-1; i++){

        for(j = 0; j < contador-i-1; j++){

            if (array[j+1] < array[j]){

                aux = array[j+1];
                array[j+1] = array[j];
                array[j] = aux;
            }
        }
    }
}
    
void shell(int array[], int contador){

    int salto, cambios, i, aux;

    for(salto = contador/2; salto!=0; salto = salto/2){

        cambios = 1;
        
        while (cambios != 0){

            cambios=0; 

            for(i = salto;i < contador; i++){

                if(array[i-salto]>array[i]){ 
                    
                    aux=array[i];
                    array[i]=array[i-salto]; 
                    array[i-salto]=aux; 
                    cambios++;
                } 
            }
        }
    }
}

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
 
int particion (int array[], int bajo, int alto){
    int pivote, i, j;
    pivote = array[alto];
    i = (bajo - 1);
 
    for (j = bajo; j <= alto- 1; j++){
        if (array[j] <= pivote){
            i++; 
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[alto]);
    return (i + 1);
}
 
void quickSort(int array[], int bajo, int alto){
	int pi;
    if (bajo < alto){
        pi = particion(array, bajo, alto);
        quickSort(array, bajo, pi - 1);
        quickSort(array, pi + 1, alto);
    }
}