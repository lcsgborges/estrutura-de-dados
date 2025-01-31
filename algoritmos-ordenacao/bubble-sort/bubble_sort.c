#include <stdio.h>
#include <time.h>

// macros:
typedef int Item;
#define SIZE 100000
#define Key(A) (A)
#define less(A, B) (Key(A) < Key(B))
#define exch(A,B) {Item T = A; A = B; B = T;}


void bubble_sort1(Item *v, int l, int r){
    for(int i = l; i <r; i++){
        for (int j = l; j < r; j++){
            if (less(v[j+1], v[j]))
                exch(v[j+1], v[j]);
        }
    }
}


void bubble_sort2(Item *v, int l, int r){

    while (r > l){
        for (int i = l; i < r; i++){
            if (less(v[i+1],v[i]))
                exch(v[i], v[i+1]);
        }
        r--;
    }
}


void bubble_sort_adptavel(Item *v, int l, int r){

    int swap = 1;
    while (r>1 && swap){
        swap = 0;
        for (int i = l; i < r; i++){
            if less(v[i+1], v[i]){
                exch(v[i], v[i+1])
                swap = 1;
            }
        }
        r--;
    }
}

int main(){
    srand(time(NULL));
    Item vetor1[SIZE];

    for(int i = 0; i < SIZE; i++)
        vetor1[i] = rand() % SIZE + 1;
    
    clock_t start_time = clock();

    bubble_sort1(vetor1, 0, SIZE -1);

    clock_t end_time = clock();

    double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    for(int i = 0; i < SIZE; i++)
        printf("%d ", vetor1[i]);
    
    printf("\nTempo execução Bubble Sort: %f segundos\n", time_taken);

    // ---------------------------------------------------------------------------------

    Item vetor2[SIZE];

    for (int i = 0; i < SIZE; i++) 
        vetor2[i] = rand() % SIZE + 1;
    
    clock_t start_time2 = clock();

    bubble_sort2(vetor2, 0, SIZE-1);

    clock_t end_time2 = clock();

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor2[i]);
    
    double time_taken2 = (double)(end_time2 - start_time2) / CLOCKS_PER_SEC;

    printf("\nTempo execução Bubble Sort 2: %f segundos\n", time_taken2);

    // ---------------------------------------------------------------------------------

    Item vetor3[SIZE];

    for (int i = 0; i < SIZE; i++) 
        vetor3[i] = rand() % SIZE + 1;
    
    clock_t start_time3 = clock();

    bubble_sort_adptavel(vetor3, 0, SIZE-1);

    clock_t end_time3 = clock();

    for (int i = 0; i < SIZE; i++)
        printf("%d ", vetor3[i]);
    
    double time_taken3 = (double)(end_time3 - start_time3) / CLOCKS_PER_SEC;

    printf("\nTempo execução Bubble Sort executável: %f segundos\n", time_taken3);

    return 0;
}