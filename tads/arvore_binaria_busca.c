#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *esq, *dir;
}No;

No* criaNo(int num){
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = num;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* insereArvore(No *raiz, int num){
    if (raiz == NULL)
        return criaNo(num);
    else{
        if (num < raiz->dado)
            raiz->esq = insereArvore(raiz->esq, num);
        else
            raiz->dir = insereArvore(raiz->dir, num);
    }
    return raiz;
}

void inordem(No *raiz){
    if (raiz != NULL){
        inordem(raiz->esq);
        printf("%d ", raiz->dado);
        inordem(raiz->dir);
    }
}

void preordem(No *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->dado);
        preordem(raiz->esq);
        preordem(raiz->dir);
    }
}

void posordem(No *raiz){
    if(raiz != NULL){
        posordem(raiz->esq);
        posordem(raiz->dir);
        printf("%d ", raiz->dado);
    }
}

No* busca(No *raiz, int num){
    if (raiz == NULL)
        return raiz;
    else{
        if (raiz->dado == num)
            return raiz;
        else{
            if(num < raiz->dado)
                return busca(raiz->esq, num);
            else
                return busca(raiz->dir, num);
        }
    }
}

No* remover(No *raiz, int valor){
    if (raiz == NULL){
        printf("Valor não encontrado. \n");
        return NULL;
    }
    else{
        if(raiz->dado == valor){
            if(raiz->esq == NULL && raiz->dir == NULL){
                free(raiz);
                printf("Elemento removido: %d\n", valor);
                return NULL;
            }
            else if(raiz->esq != NULL && raiz->dir != NULL){ // 2 filhos:
                No *aux = raiz->dir;
                while(aux->esq != NULL){
                    aux = aux->esq;
                }
                raiz->dado = aux->dado;
                aux->dado = valor;
                raiz->dir = remover(raiz->dir, valor);
                return raiz;
            }
            else{ // 1 filho:
                No* aux = raiz->dir;
                if (raiz->esq == NULL)
                    aux = raiz->dir;
                else
                    aux = raiz->esq;
                free(raiz);
                return aux;
            }
        }
        else{
            if (valor < raiz->dado)
                raiz->esq = remover(raiz->esq, valor);
            else
                raiz->dir = remover(raiz->dir, valor);
            return raiz;
        }
    }
}

int menor(No *raiz){
    int men = raiz->dado;
    if (raiz->esq == NULL)
        return men;
    else
        return menor(raiz->esq);
}

int maior(No *raiz){
    int max = raiz->dado;
    if (raiz->dir == NULL)
        return max;
    else
        return maior(raiz->dir);
}

int qtdNo(No *raiz){
    if (raiz == NULL)
        return 0;
    return 1 + qtdNo(raiz->esq) + qtdNo(raiz->dir);
}

int altura(No *raiz){
    if(raiz == NULL)
        return -1;
    else{
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);

        if (esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int main(){
    No *raiz = NULL, *buscador;
    int opcao, num;

    do
    {
        printf("\n1. Inserir elemento\n2. Remover elemento\n3. Buscar elemento\n4. Imprimir árvore\n5. Altura da árvore\n6. Maior elemento da árvore\n7. Menor elemento da árvore\n8. Quantidade de nós da árvore\n0. Sair\nOpção: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 1:
            printf("Digite o número que deseja inserir: ");
            scanf("%d", &num);
            raiz = insereArvore(raiz, num);
            break;
        case 2:
            printf("Digite o número que deseja remover: ");
            scanf("%d", &num);
            remover(raiz, num);
            break;
        case 3:
            printf("Digite o número que deseja buscar: ");
            scanf("%d", &num);
            buscador = busca(raiz, num);
                if(buscador)
                    printf("O número %d foi encontrado na lista.\n", num);
                else
                    printf("O número %d não foi encontrado na lista.\n", num);
            break;
        case 4:
            printf("Árvore em ordem: ");
            inordem(raiz);
            printf("\nÁrvore em pré-ordem: ");
            preordem(raiz);
            printf("\nÁrvore em pós-ordem: ");
            posordem(raiz);
            printf("\n");
            break;
        case 5:
            printf("Altura da árvore = %d\n", altura(raiz));
            break;
        case 6:
            printf("Maior elemento da árvore = %d\n", maior(raiz));
            break;
        case 7:
            printf("Menor elemento da árvore = %d\n", menor(raiz));
            break;
        case 8:
            printf("Quantidade de nós na árvore = %d\n", qtdNo(raiz));
            break;
        default:
            if(opcao != 0)
                printf("Opção inválida!\n");
            break;
        }
    } while (opcao != 0);
    free(raiz);
    printf("Saindo...\n");
    return 0;
}