#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
#define SIZE 1000000
#define less(A,B) ((A) < (B))
#define exch(A,B) {Item t = A; A = B; B = t;}

static Item *pq;
static int N;

void PQinit(int maxN){
    pq = malloc(sizeof(Item) * (maxN + 1)); // HEAP começa a partir do indíce 1
    N = 0;
}   


int PQempty(){
    return N == 0; // se vazia, retorna 1
}


void fixUp(int k){
    while( k>1 && less(pq[k/2], pq[k])){
        exch(pq[k/2], pq[k]);
        k = k/2;
    }
}


void PQinsert(int k){
    pq[++N] = k;
    fixUp(N);
}


void fixDown(int k, int N){
    int j;

    while(2*k <= N){
        j = 2*k;

        if (j < N && less(pq[j], pq[j+1])) j++;

        if (!less(pq[k], pq[j])) break;

        exch(pq[k], pq[j]);
        k = j;
    }
}

int PQdelMax(){
    exch(pq[1], pq[N]);
    fixDown(1, N-1);
    return pq[N--];
}


void PQchange(int k, int valor){ // trivial se sabemos o índice
    pq[k] = valor;
    fixUp(k);
    fixDown(k, N);
}


void PQsort(Item *v, int l, int r){
    PQinit(r-l+1);

    for (int k=l; k <=r; k++)
        PQinsert(v[k]);
    
    for (int k=r; k>=l; k--)
        v[k] = PQdelMax();
}


int main(){
    srand(time(NULL));
    Item vetor[SIZE];

    for (int i = 0; i < SIZE; i++)
        vetor[i] = rand() % SIZE +1;

    clock_t start_time = clock();

    PQsort(vetor, 0, SIZE -1);

    clock_t end_time = clock();

    double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor[i]);

    printf("\nTempo de execução do PQsort: %f segundos\n", time_taken);

// -------------------------------------------------------------------------------

    PQinit(10);
    PQinsert(10);
    PQinsert(200);
    PQinsert(100);
    PQinsert(30);
    PQinsert(40);
    PQinsert(50);
    PQinsert(60);
    PQchange(1, 8); // o elemento antes de maior prioridade vira 8;
    PQchange(5, 500); // o elemento no indice 5 agora tem prioridade 500;
    printf("%d\n", PQdelMax());
    printf("%d\n", PQdelMax());
    printf("%d\n", PQdelMax());

    return 0;
}