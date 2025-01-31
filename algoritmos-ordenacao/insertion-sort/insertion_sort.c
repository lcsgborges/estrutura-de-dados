#include <stdio.h>
#include <time.h>

typedef int Item;
#define SIZE 100000
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item T = A; A = B; B = T;}
#define cmpexch(A, B){ if (less(B, A)) exch(A,B);}


void insertion_sort_ribas(Item *v, int l, int r){
    for (int i = r; i > l; i--)
        cmpexch(v[i-1], v[i]);    // definir o menor elemento do vetor logo no início
    
    for (int i = l + 2; i <= r; i++){
        int j = i;
        Item tmp = v[j];
        while (less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}


void insertior_sort_rose(Item *vet, int inicio, int fim){
    int i, j, chave;

    for (i = inicio +1; i <= fim; i++){
        chave = vet[i];

        for(j = i; j > inicio && chave < vet[j-1]; j--){
            vet[j] = vet[j-1];
        }
        vet[j] = chave;
    }
}


int main(){
    srand(time(NULL));
    
    Item vetor[SIZE];

    for (int i = 0; i < SIZE; i++)
        vetor[i] = rand() % SIZE + 1;

    clock_t start_time = clock();

    insertion_sort_ribas(vetor, 0, SIZE - 1);

    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor[i]);

    printf("\nTempo de execução do Insertion Sort Ribas: %f segundos\n", time_taken);

    // ---------------------------------------------------------------------------------

    Item vetor2[SIZE];

    for (int i = 0; i < SIZE; i++) 
        vetor2[i] = rand() % SIZE + 1;
    
    clock_t start_time2 = clock();

    insertior_sort_rose(vetor2, 0, SIZE-1);

    clock_t end_time2 = clock();

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor2[i]);
    
    double time_taken2 = (double)(end_time2 - start_time2) / CLOCKS_PER_SEC;

    printf("\nTempo execução Insertion Sort Rose: %f segundos\n", time_taken2);

    return 0;
}