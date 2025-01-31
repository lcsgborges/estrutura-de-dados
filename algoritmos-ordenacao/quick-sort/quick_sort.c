// Quick Sort:

// melhorando o quick_sort: adicionando mediana

#include <stdio.h>
#include <time.h>

typedef int Item;
#define SIZE 1000000
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item T = A; A = B; B = T;}
#define cmpexch(A,B) {if (less(B,A)) exch(A,B);}

void mediana(Item *v, int l, int r){
    int meio = (r+l) / 2;

    cmpexch(v[meio], v[r]);
    cmpexch(v[l], v[meio]);
    cmpexch(v[r], v[meio]);
}

int partition(Item *v, int l, int r){

    mediana(v, l, r);

    int i = l-1, j = r;
    Item p = v[r];

    while (i<j){
        while(v[++i] < p);
        while(p < v[--j]);
        
        if(i < j)
            exch(v[i], v[j]);
    }
    exch(v[r], v[i]);
    return i;
}


void quick_sort(Item *v, int l, int r){

    if (r <= l)
        return;

    int i = partition(v, l, r);
    quick_sort(v, l, i-1);
    quick_sort(v, i+1, r);
}


int main(){
    srand(time(NULL));
    Item vetor[SIZE];

    for (int i = 0; i < SIZE; i++)
        vetor[i] = rand() % SIZE +1;

    clock_t start_time = clock();

    quick_sort(vetor, 0, SIZE -1);

    clock_t end_time = clock();

    double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor[i]);

    printf("\nTempo de execução do Quick Sort: %f segundos\n", time_taken);

// -------------------------------------------------------------------------------------------------
    
    clock_t start_time2 = clock();

    quick_sort(vetor, 0, SIZE -1);

    clock_t end_time2 = clock();

    double time_taken2 = (double) (end_time2 - start_time2) / CLOCKS_PER_SEC;

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor[i]);

    printf("\nTempo de execução do Quick Sort no \"pior caso\": %f segundos\n", time_taken2);

    return 0;
}