// Shell Sort -> complexidade assintótica vai depender do salto

// 1, 4, 13, 40, 121, 364, 1093, ... 3*h + 1 até n/3

// determinar o n/3, comparar com a sequência

#include <stdio.h>
#include <time.h>

typedef int Item;
#define SIZE 100000
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item T = A; A = B; B = T;}
#define cmpexch(A, B){ if (less(B, A)) exch(A,B);}


void shell_sort(Item *v, int l, int r){

    int h = 1, elem, i, j;

    while(h < (r-l + 1) / 3)
        h = 3*h + 1;

    while(h >= 1){

        for(i = l+h; i <= r; i++){

            elem = v[i];

            for(j = i; j >= l+h && elem < v[j-h]; j -= h){
                v[j] = v[j-h];
            }
        v[j] = elem;
        }
        h = h/3;
    }
}

int main(){
     srand(time(NULL));

    Item vetor1[SIZE];

    for (int i = 0; i < SIZE; i++) 
        vetor1[i] = rand() % SIZE + 1;

    clock_t start_time = clock();

    shell_sort(vetor1, 0, SIZE-1);

    clock_t end_time = clock();

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor1[i]);

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTempo execução Shell Sort: %f segundos\n", time_taken);

    return 0;
}