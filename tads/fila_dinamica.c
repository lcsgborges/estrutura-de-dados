#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no *prox;
    int dado;
} No;

typedef struct fila{
    struct no *primeiro;
    struct no *ultimo;
    int tam;
} Fila;

void criaFila(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tam = 0;
}

void tamFila(Fila*fila){
    printf("tamanho fila: %d\n", fila->tam);
}

void primeiroElemento(Fila *fila){
    if (fila == NULL){
        printf("FILA VAZIA\n");
        return ;
    }
    printf("primeiro elemento : %d\n", fila->primeiro->dado);
}

void ultimoElemento(Fila *fila){
    if (fila == NULL){
        printf("FILA VAZIA\n");
        return;
    }
    printf("ultimo elemento: %d\n", fila->ultimo->dado);
}

void enfileirar(Fila *fila, int valor){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }
    novo->dado = valor;
    novo->prox = NULL;
    if (fila->primeiro == NULL) {
        fila->primeiro = novo;
        fila->ultimo = novo;
    } else {
        fila->ultimo->prox = novo;
        fila->ultimo = novo;
    }
        fila->tam++;
}

void desenfileira(Fila *fila){
    if (fila->primeiro == NULL) {
        printf("Fila vazia.\n");
        return;
    }
    No *aux = fila->primeiro;
    fila->primeiro = aux->prox;
    if (fila->primeiro == NULL) {
        fila->ultimo = NULL;
    }
    fila->tam--;
    printf("Retirando o número %d da fila\n", aux->dado);
    free(aux);
}

void imprimeFila(Fila *fila){
    if(fila->primeiro == NULL){
        printf("fila vazia\n");
        return;
    }
    else{
        No *aux = fila->primeiro;
        printf("Fila: ");
        while(aux != NULL){
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
        printf("\n");
    }
}

int main(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    int opcao, num;
    criaFila(fila);

    do
    {
        printf("\n1. Enfileirar\n2. Desenfileirar\n3. Imprimir fila\n4. Consultar tamanho da fila\n5. Consultar primeiro elemento\n6. Consultar último elemento\n0. Sair\nOpção: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("Digite o número: ");
            scanf("%d", &num);
            enfileirar(fila, num);
            break;
        case 2:
            desenfileira(fila);
            break;
        case 3:
            imprimeFila(fila);
            break;
        case 4:
            tamFila(fila);
            break;
        case 5:
            primeiroElemento(fila);
            break;  
        case 6:
            ultimoElemento(fila);
            break;
        default:
            if(opcao != 0)
                printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);
    printf("Saindo...\n");
    free(fila); 
    return 0;
}