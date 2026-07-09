#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#define MAX_PRODUTOS 3000

typedef struct {
    char nome[50];
    int quantidade;
    float preco;
    float faturamento;
    int situacao;
} Produto;

void funcao_cadastra_produtos(Produto produtos[], int *total);

#endif
