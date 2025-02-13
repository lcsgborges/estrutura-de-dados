#include <stdio.h>
#include <time.h>

typedef int Item;
#define Key(A) (A)
#define exch(A, B) {Item t = A; A = B; B = t;}

// busca binaria -> vetor precisa estar ordenado.

#define SIZE 1000

int busca_binaria(int *v, int l, int r, int k){

    if (l > r) return -1;

    int meio = (r+l) /2 ;

    if (k == v[meio])
        return meio;
    else if (k < v[meio])
        return busca_binaria(v, l, meio - 1, k);
    else
        return busca_binaria(v, meio + 1, r, k);

}

void bubble_sort(int *v, int l, int r){

    while (r>l){
        for(int i = l; i < r; i++){
            if (v[i] > v[i+1])
                exch(v[i], v[i+1]);
        }
        r--;
    }
}




int main(){
    srand(time(NULL));

    int vetor[SIZE];

    for (int i = 0; i < SIZE; i++){
        vetor[i] = rand() % SIZE +1;
    }
    bubble_sort(vetor, 0, SIZE-1);

    int buscador = busca_binaria(vetor, 0, SIZE, 15);

    for (int i = 0; i < SIZE; i++){
        printf("%d ", vetor[i]);
    }

    printf("\nbuscador, indice = %d", buscador);
    return 0;
}