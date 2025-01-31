#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;

#define SIZE 100000
#define Key(A) (A)
#define less(A,B) ( Key(A) < Key(B) ) 
#define exch(A,B){Item t = A; A = B; B = t;}

static Item *pq;
static int N;

// funções da heap que vamos usar: fixDown 

void fixDown(int k, int N){
    while (2*k <= N){
        int j = 2*k;

        if(j<N && less(pq[j], pq[j+1])) j++;

        if(! less(pq[k], pq[j])) break;

        exch(pq[k], pq[j]);

        k = j;
    }
}


void heap_sort(Item *v, int l, int r){
    pq = v+l-1;
    N = r-l+1;

    for(int k = N/2; k>=1; k--)
        fixDown(k, N);

    while(N>1){
        exch(pq[1], pq[N]);
        fixDown(1, --N);
    }
}

int main(){
    srand(time(NULL));
    Item vetor[SIZE];

    for (int i = 0; i < SIZE; i++)
        vetor[i] = rand() % SIZE +1;

    clock_t start_time = clock();

    heap_sort(vetor, 0, SIZE -1);

    clock_t end_time = clock();

    double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor[i]);

    printf("\nTempo de execução do HeapSort: %f segundos\n", time_taken);

    return 0;
}