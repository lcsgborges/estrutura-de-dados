#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000
#define R 1000

typedef struct {
    int dado;
    int chave;
} Item;

void couting_sort(Item *v, int l, int r){

    Item aux[SIZE];
    int count[R+1];

    for (int i = 0; i <= R; i++)
        count[i] = 0;

    for (int i = l; i <= r; i++)
        count[v[i].chave + 1]++;  

    for (int i = 1; i <= R; i++)
        count[i] = count[i] + count[i-1];

    for (int i=l; i <= r; i++)
        aux[count[v[i].chave]++] = v[i];

    for (int i=l; i<=r; i++)
        v[i] = aux[i-l];
}

int main() {
    Item v[SIZE];
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        v[i].dado = rand() % 100;
        v[i].chave = rand() % (R + 1);
    }
    clock_t start_time = clock();

    couting_sort(v, 0, SIZE - 1);

    clock_t end_time = clock();

    double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC; 

    for (int i = 0; i < SIZE; i++) 
        printf("dado: %.2d, chave: %.2d\n", v[i].dado, v[i].chave);
    
    printf("\nTempo de execução do Counting Sort para %d elementos e %d chaves = %f seg\n", SIZE, R, time_taken);
    
    return 0;
}