// Merge Sort -> complexidade O(n.logn):

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef int Item;
#define SIZE 100000
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {Item T = A; A = B; B = T}

void merge(Item *v, int l, int meio, int r){
    Item *v2 = malloc(sizeof(Item) * (r-l + 1));

    int k = 0, i = l, j = meio+1;

    while(i <= meio && j <= r){
        if (less(v[i], v[j]))
            v2[k++] = v[i++];
        else    
            v2[k++] = v[j++];
    }
    while(i <= meio)
        v2[k++] = v[i++];
    while(j <= r)
        v2[k++] = v[j++];
    
    k = 0;
    for (i = l; i <= r; i++){
        v[i] = v2[k++];
    }
    free(v2);
}


void merge_sort(Item *v, int l, int r){
     
     if(l >= r)
        return;
    
    int meio = (r+l) / 2;

    merge_sort(v, l, meio);
    merge_sort(v, meio+1, r);
    merge(v, l, meio, r);
}


int main(){
    srand(time(NULL));
    Item v[SIZE];

    for (int i = 0; i < SIZE; i++)
        v[i] = rand() % SIZE + 1;
    
    clock_t start_time = clock();

    merge_sort(v, 0, SIZE -1);

    clock_t end_time = clock();

    double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    for (int i = 0; i < SIZE; i++)
        printf("%d ", v[i]);

    printf("\nTempo execução Merge Sort: %f segundos\n", time_taken);

    return 0;
}