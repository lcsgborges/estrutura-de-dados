#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

typedef int Item;
#define SIZE 1000000
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if (less(B,A)) exch(A,B);}

static Item *pq;
static int N;

void insertion_sort(Item *v, int l, int r){
    for (int i = l + 1; i <= r; i++){
        Item temp = v[i];
        int j = i;
        while (j > l && temp < v[j - 1]){
            v[j] = v[j - 1];
            j--;
        }
        v[j] = temp;
    }
}

void fixDown(int k, int N){
    while (2 * k <= N){
        int j = 2 * k;
        if (j < N && less(pq[j], pq[j + 1])) j++;
        if (!less(pq[k], pq[j])) break;
        exch(pq[k], pq[j]);
        k = j;
    }   
}

void heap_sort(Item *v, int l, int r){
    pq = v - 1;  // Ajustando indexação do heap
    N = r - l + 1;

    for (int k = N / 2; k >= 1; k--){
        fixDown(k, N);
    }
    while (N > 1){
        exch(pq[1], pq[N]);
        fixDown(1, --N);
    }
}

void mediana(Item *v, int l, int r){
    int meio = (r + l) / 2;
    cmpexch(v[meio], v[r]);
    cmpexch(v[l], v[meio]);
    cmpexch(v[r], v[meio]);
}

int partition(Item *v, int l, int r){
    Item p = v[r];
    int i = l - 1, j = r;
    
    while (1){
        while (less(v[++i], p));
        while (j > l && less(p, v[--j]));
        if (i >= j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void intro(Item *v, int l, int r, int maxdepth){
    if (r - l <= 24) return;
    else if (maxdepth == 0) heap_sort(v, l, r);
    else{
        mediana(v, l, r);
        int c = partition(v, l, r);
        intro(v, l, c - 1, maxdepth - 1);
        intro(v, c + 1, r, maxdepth - 1);
    }
}

void intro_sort(Item *v, int l, int r){
    int maxdepth = 2 * ((int)log2((double)(r - l + 1)));
    intro(v, l, r, maxdepth);
    insertion_sort(v, l, r);
}

int main(){
    srand(time(NULL));
    
    Item vetor[SIZE];

    for (int i = 0; i < SIZE; i++)
        vetor[i] = rand() % SIZE + 1;

    clock_t start_time = clock();

    intro_sort(vetor, 0, SIZE - 1);

    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor[i]);
    printf("\n");

    printf("Tempo de execução do Intro Sort: %f segundos\n", time_taken); // 0.008578 segundos 

    // em teste contra o quick_sort, se mostrou 0.01 mais rápido

    return 0;
}
      