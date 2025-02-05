#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;

#define key(A) A
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t=A; A=B; B=t; }
#define compexch(A, B) if(less(B, A)) exch(A, B)

#define MAXSTRING 101
#define BITSBYTE 8
#define BYTESWORD 4
#define R (1 << BITSBYTE) // 2^8 = 256
#define digit(N, D) (((N) >> ((D) * BITSBYTE)) & (R - 1))

void show(Item v[][MAXSTRING], int l, int r) {
    for (int i = l; i <= r; i++) {
        printf("%s ", v[i]);
    }
    printf("\n");
}

// Ordena pelo d-ésimo caractere
void radixMSD(char a[][MAXSTRING], int l, int r, int d) { 
    if (r <= l) return;
    
    char aux[r - l + 1][MAXSTRING];
    int count[R + 1] = {0}; // Inicializa com zeros

    for (int i = l; i <= r; i++)
        count[a[i][d] + 1]++; // Frequência do d-ésimo caractere
    
    for (int i = 1; i < R; i++)
        count[i] += count[i - 1]; // Encontra as posições
    
    for (int i = l; i <= r; i++) 
        strcpy(aux[count[a[i][d]]++], a[i]); // Ordena em aux

    for (int i = l; i <= r; i++)
        strcpy(a[i], aux[i - l]); // Copia para o original
    
    for (int i = 1; i < R; i++) {
        radixMSD(a, l + count[i - 1], l + count[i] - 1, d + 1);
    }
}

// Ordenação LSD para strings de tamanho w
void radixLSD(char a[][MAXSTRING], int l, int r, int w) { 
    char aux[r - l + 1][MAXSTRING];
    int count[R + 1];

    for (int d = w - 1; d >= 0; d--) { // Percorre os caracteres da direita para a esquerda
        memset(count, 0, sizeof(count));

        for (int i = l; i <= r; i++)
            count[a[i][d] + 1]++;
    
        for (int i = 1; i < R; i++)
            count[i] += count[i - 1];

        for (int i = l; i <= r; i++)
            strcpy(aux[count[a[i][d]]++], a[i]);

        for (int i = l; i <= r; i++)
            strcpy(a[i], aux[i - l]); 
    }
}

// Ordenação LSD para inteiros
void radixLSDI(int *v, int l, int r) {
    int *aux = malloc((r - l + 1) * sizeof(int));
    int count[R + 1];

    for (int w = 0; w < BYTESWORD; w++) {
        memset(count, 0, sizeof(count));

        for (int i = l; i <= r; i++)
            count[digit(v[i], w) + 1]++;
        
        for (int i = 1; i < R; i++)
            count[i] += count[i - 1];
        
        for (int i = l; i <= r; i++)
            aux[count[digit(v[i], w)]++] = v[i];

        for (int i = l; i <= r; i++)
            v[i] = aux[i - l]; 
    }

    free(aux);
}

int main() {
    char a[5][MAXSTRING] = {"cavalo", "bexiga", "nabo", "praca", "cafe"};
    char b[5][MAXSTRING] = {"caro", "beta", "nabo", "pera", "cafe"};

    show(b, 0, 4);
    radixLSD(b, 0, 4, 4);
    show(b, 0, 4);

    show(a, 0, 4);
    radixMSD(a, 0, 4, 0); 
    show(a, 0, 4);

    int v[16] = {3, 2, 3, 5, 1, 6, 8, 2, 4, 7, 1, 3, 8, 6, 8, 9};
    
    for (int i = 0; i < 16; i++) printf("%d ", v[i]);
    printf("\n");

    radixLSDI(v, 0, 15);

    for (int i = 0; i < 16; i++) printf("%d ", v[i]);
    printf("\n");

    return 0;
}