#include <stdio.h>
#include <time.h>

// Arrays são vetores que permitem apenas um tipo de dados (int, float, char, etc) - tem tamanho fixo;

// Algumas operações comuns:

// verificar se o elemento 'x' está no vetor 'vet[]' de tamanho 'tam':

int busca_vetor(int vet[], int tam, int x){ 
    int i = 0;
    while ( i < tam){
        if (x == vet[i])
            return i; // retorna o indice em que o elemento x está presente
        i++;
    }
    return -1; // retorna -1 se o x não está presente no vetor
}

int remove_elemento(){
    // implementar depois
}

void adiciona_elemento(){
    // implementar depois
}

int main(){
    srand(time(NULL));
    int vetor[100];

    for (int i = 0; i < 100; i++){
        vetor[i] = rand() % (100 + 1);
    }
    
    for (int i = 0; i < 100; i++){
        printf("%d ", vetor[i]);
    }
    
    int achou = busca_vetor(vetor, 100, 1);

    printf("\n\n\t%d\n\n", achou);
    return 0;
}