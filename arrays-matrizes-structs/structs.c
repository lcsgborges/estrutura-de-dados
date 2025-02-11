#include <stdio.h>

// Struct é um tipo de dado heterogêneo, capaz de armazenar mais de um tipo de dado e não possui um tamanho fixo.

// exemplo: criando uma pessoa usando struct:

typedef struct data{
    int dia, mes, ano;
} Data;

typedef struct p{
    Data data_nascimento;
    char nome[50];
    float altura;
} Pessoa;

Pessoa cria_pessoa(Pessoa p){
    printf("Digite seu nome: ");
    scanf("%49[^\n]", p.nome);

    printf("Digite sua data de nascimento no fomarto DD/MM/AAAA, não use barras, apenas espaços: ");
    scanf("%d%d%d", &p.data_nascimento.dia, &p.data_nascimento.mes, &p.data_nascimento.ano);

    printf("Digite sua altura em metros: ");
    scanf("%f", &p.altura);

    return p;
}

void imprime_pessoa(Pessoa p){
    printf("Informações do indivíduo: \n");
    printf("Nome: %s\n", p.nome);
    printf("Data de nascimento: %02d/%02d/%04d\n", p.data_nascimento.dia, p.data_nascimento.mes, p.data_nascimento.ano);
    printf("Altura: %.2f\n", p.altura);
}

int main(){
    Pessoa p = cria_pessoa(p);
    imprime_pessoa(p);

    printf("%lu\n", sizeof(p)); // 68 bytes (50 do nome, 4 da altura, 12 da data de nascimento)

    return 0;
}