#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    struct no *prox;
    int dado;
}No;

typedef struct f{
    struct no *topo;
    int tam;
}Pilha;

void criaPilha(Pilha *p){
    p->tam = 0;
    p->topo = NULL;
}

void empilha(Pilha *p, int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->tam++;
}

void imprimePilha(Pilha *p){
    if (p->topo == NULL){
        printf("Pilha vazia\n");
        return;
    }
    else{
        No *aux = p->topo;
        printf("Pilha: ");
        while(aux != NULL){
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
        printf("\n");
        free(aux);
    }
}

void tam(Pilha *p){
    printf("Tamanho da pilha: %d", p->tam);
}

void desempilha(Pilha *p){
    if(p->topo == NULL){
        printf("pilha vazia\n");
        return;
    }
    else{
        No *aux = p->topo;
        p->topo = aux->prox;
        p->tam--;
        printf("elemento desempilhado: %d\n", aux->dado);
        free(aux);
    }
}

int main(){ 
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    int opcao, num;
    criaPilha(p);
    
    do
    {
        printf("\n1. Empilhar\n2. Desempilhar\n3. Imprimir pilha\n4. Tamanho da pilha\n0. Sair\nOpção: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("Digite o número: ");
            scanf("%d", &num);
            empilha(p, num);
            break;
        case 2:
            desempilha(p);
            break;
        case 3:
            imprimePilha(p);
            break;
        case 4:
            tam(p);
            break;
        default:
            if(opcao != 0)
                printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);
    printf("Saindo...\n");
    free(p); 
    return 0;
}