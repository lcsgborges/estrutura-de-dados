#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // para verificar se há erros no programa 

typedef int Item;

typedef struct no{
    Item info;
    struct no *prox;
}No;

typedef struct cabeca{
    int qtd_itens;
    No *prox;
    No *ant;
}Head;

Head *criar_lista(){
    Head *cabeca = malloc(sizeof(Head));
    cabeca->ant = NULL;
    cabeca->prox = NULL;
    cabeca->qtd_itens = 0;
    return cabeca;
}   

No *criar_no(Item valor){
    No *no = malloc(sizeof(No));
    no->info = valor;
    no->prox = NULL;
    return no;
}

int vazia(Head *cabeca){
    if (cabeca->qtd_itens == 0)
        return 1; // 1 se tiver vazia
    return 0; // 0 caso n esteja vazia
}


int tamanho(Head *cabeca){
    return cabeca->qtd_itens;
}

void inserir_depois(Head *cabeca, No *insere, No *depois){
    if (depois == NULL) {
        printf("Erro: Nó de referência é NULL\n");
        return;
    }

    insere->prox = depois->prox;
    depois->prox = insere;
    cabeca->qtd_itens++;

    if (insere->prox == NULL)
        cabeca->ant = insere;
}


void insere_inicio(Head *cabeca, No *no){
    if (cabeca->qtd_itens == 0){
        cabeca->qtd_itens++;
        cabeca->ant = no;
        cabeca->prox = no;
        return;
    }
    no->prox = cabeca->prox;
    cabeca->prox = no;
    cabeca->qtd_itens++;
}

void insere_fim(Head *cabeca, No *no){
    if (cabeca->qtd_itens == 0){
        cabeca->qtd_itens++;
        cabeca->ant = no;
        cabeca->prox = no;
        return;
    }
    cabeca->ant->prox = no;
    no->prox = NULL;
    cabeca->ant = no;
    cabeca->qtd_itens++;
}

No *remover_inicio(Head *cabeca){
    if (vazia(cabeca)) return NULL;  

    No *removido = cabeca->prox;  

    if (tamanho(cabeca) == 1) {  
        cabeca->prox = NULL;
        cabeca->ant = NULL;
    } else {
        cabeca->prox = removido->prox;
    }

    cabeca->qtd_itens--;
    return removido; 
}

No *remover_fim(Head *cabeca){
    if (vazia(cabeca)) return NULL;  

    No *removido = cabeca->ant; 

    if (tamanho(cabeca) == 1) {  
        cabeca->prox = NULL;
        cabeca->ant = NULL;
    } else {
        No *atual = cabeca->prox;  
        while (atual->prox != removido) {
            atual = atual->prox;
        }
        atual->prox = NULL;
        cabeca->ant = atual;
    }

    cabeca->qtd_itens--;
    return removido;  
}

No *remover_no(Head *cabeca, No *no) {
    if (vazia(cabeca) || no == NULL) return NULL;  

    No *removido = NULL;

    if (cabeca->prox == no) {
        cabeca->prox = no->prox; 
        if (cabeca->prox == NULL) { 
            cabeca->ant = NULL;
        }
        removido = no;
    } else {
        
        No *anterior = cabeca->prox;
        while (anterior->prox != NULL && anterior->prox != no) {
            anterior = anterior->prox;
        }

        if (anterior->prox == no) {
            anterior->prox = no->prox;
            removido = no;

            if (no == cabeca->ant) {
                cabeca->ant = anterior;
            }
        }
    }

    if (removido) {
        cabeca->qtd_itens--;
    }
    
    return removido;  
}

No *buscar(Head *cabeca, Item info) {
    if (cabeca == NULL) return NULL; 

    No *atual = cabeca->prox; 
    while (atual != NULL) {
        if (atual->info == info)
            return atual; 
        atual = atual->prox; 
    }
    return NULL; 
}

void imprimir_lista(Head *cabeca) {
    No *atual = cabeca->prox;
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}

// Teste 1 - Testa a inserção no início
void test1() {
    Head *cabeca = criar_lista();
    
    insere_inicio(cabeca, criar_no(10));
    insere_inicio(cabeca, criar_no(20));
    insere_inicio(cabeca, criar_no(30));

    // Esperado: 30 20 10
    imprimir_lista(cabeca);
    assert(tamanho(cabeca) == 3);
    printf("Teste de inserção no início passou!\n");
}

// Teste 2 - Testa a inserção no fim
void test2() {
    Head *cabeca = criar_lista();
    
    insere_fim(cabeca, criar_no(10));
    insere_fim(cabeca, criar_no(20));
    insere_fim(cabeca, criar_no(30));

    // Esperado: 10 20 30
    imprimir_lista(cabeca);
    assert(tamanho(cabeca) == 3);
    printf("Teste de inserção no fim passou!\n");
}

// Teste 3 - Testa a remoção do início
void test3() {
    Head *cabeca = criar_lista();
    
    insere_inicio(cabeca, criar_no(10));
    insere_inicio(cabeca, criar_no(20));
    insere_inicio(cabeca, criar_no(30));

    No *removido = remover_inicio(cabeca);
    free(removido);
    
    // Esperado: 20 10
    imprimir_lista(cabeca);
    assert(tamanho(cabeca) == 2);
    printf("Teste de remoção do início passou!\n");
}

// Teste 4 - Testa a remoção do fim
void test4() {
    Head *cabeca = criar_lista();
    
    insere_inicio(cabeca, criar_no(10));
    insere_inicio(cabeca, criar_no(20));
    insere_inicio(cabeca, criar_no(30));

    No *removido = remover_fim(cabeca);
    free(removido);
    
    // Esperado: 30 20
    imprimir_lista(cabeca);
    assert(tamanho(cabeca) == 2);
    printf("Teste de remoção do fim passou!\n");
}

// Teste 5 - Testa a busca
void test5() {
    Head *cabeca = criar_lista();
    
    insere_inicio(cabeca, criar_no(10));
    insere_inicio(cabeca, criar_no(20));
    insere_inicio(cabeca, criar_no(30));

    No *encontrado = buscar(cabeca, 20);
    assert(encontrado != NULL && encontrado->info == 20);
    
    encontrado = buscar(cabeca, 40);
    assert(encontrado == NULL);

    printf("Teste de busca passou!\n");
}

int main(){

    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}