#include <stdio.h>
#include <time.h>

#define SIZE 1000

int busca_sequencial(int *v, int tam, int k){
    for (int i = 0; i < tam; i++){
        if (v[i] == k)
        return i;
    }
    return -1;
}

int main(){
    srand(time(NULL));

    int vetor[SIZE];

    for (int i = 0; i < SIZE; i++){
        vetor[i] = rand() % SIZE +1;
    }

    int buscador = busca_sequencial(vetor, SIZE, 55);

    for (int i = 0; i < SIZE; i++){
        printf("%d ", vetor[i]);
    }

    printf("\nbuscador, indice = %d", buscador);



    return 0;
}