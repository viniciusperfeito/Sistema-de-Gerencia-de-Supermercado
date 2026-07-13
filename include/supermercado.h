#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#define MAX_PRODUTOS 3000
#define MAX_VENDAS 50000

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um produto
typedef struct {
    char nome[50];
    int quantidade;
    float preco;
    float faturamento;
    int situacao;
} Produto;
// Estrutura de data de vendas
typedef struct {
    int data[3];  // Exemplo: "dd/mm/yyyy"
    float valor;    // Valor total da venda
    char nome[50];  // Nome do produto vendido
    int quantidade; // Quantidade vendida
} Venda;

// Declaração das funções
void funcao_cadastra_produtos(Produto produtos[], int *total);
void funcao_controle_estoque(Produto produtos[], int total);
void funcao_imprime_produtos(Produto produtos[], int total);
void funcao_busca_produtos(Produto produtos[], int total, char nome[]);
void funcao_venda_produtos(Produto produtos[], Venda vendas[], int total, int *total_vendas);
void funcao_faturamento(Venda vendas[], int total_vendas);

#endif
