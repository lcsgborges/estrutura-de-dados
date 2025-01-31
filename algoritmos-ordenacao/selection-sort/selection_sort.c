#include <stdio.h>
#include <time.h>

// macros:
typedef int Item;
#define SIZE 100000
#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define exch(A, B) {Item T = A; A = B; B = T;}


void selection_sort_recursivo(Item *v, int l, int r){
    if (l == r)
        return;
    int min = l;
    
    for(int j = l+1; j <= r; j++){
        if (less(v[j], v[min]))
            min = j;
    }       
    exch(v[min], v[l]);
    selection_sort_recursivo(v, l+1, r);
}


void selection_sort_iterativo(Item *v, int l, int r){
    for(int i = l; i < r; i++){
        int min = i;
        for(int j = i+1; j<=r; j++){
            if(less(v[j], v[min]))
                min = j;
        }
        exch(v[min], v[i]);
    }
}


int main(){
    srand(time(NULL));

    Item vetor1[SIZE];

    for (int i = 0; i < SIZE; i++) 
        vetor1[i] = rand() % SIZE + 1;

    clock_t start_time = clock();

    selection_sort_recursivo(vetor1, 0, SIZE-1);

    clock_t end_time = clock();

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor1[i]);

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nTempo execução Selection sort recursivo: %f segundos\n", time_taken);

    // ---------------------------------------------------------------------------------

    Item vetor2[SIZE];

    for (int i = 0; i < SIZE; i++) 
        vetor2[i] = rand() % SIZE + 1;
    
    clock_t start_time2 = clock();

    selection_sort_iterativo(vetor2, 0, SIZE-1);

    clock_t end_time2 = clock();

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor2[i]);
    
    double time_taken2 = (double)(end_time2 - start_time2) / CLOCKS_PER_SEC;

    printf("\nTempo execução Selection sort iterativo: %f segundos\n", time_taken2);

    return 0;
}

// conclusões: o iterativo se mostrou mais rápido que o recursivo, pelo menos nessa máquina.