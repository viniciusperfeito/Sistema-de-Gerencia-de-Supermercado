#include "../include/supermercado.h"

void funcao_venda_produtos(Produto produtos[], Venda vendas[], int total, int *total_vendas) {
    char nome[50];
    int quantidade;
    float preco;
    int encontrado = 0;
    printf("\n========================================\n");
    printf("           VENDA DE PRODUTOS\n");
    printf("========================================\n");

    printf("Você fará a venda de qual produto?\n");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    for (int j = 0; j < total; j++) {
        if (strcmp(produtos[j].nome, nome) == 0) {
            printf("%sProduto encontrado:%s %s\n", VERDE, RESET, produtos[j].nome);
            encontrado = 1;
            printf("Informações do produto:\n");
            if (produtos[j].quantidade == 0) {
                printf("%sProduto indisponível%s\n", VERMELHO, RESET);
                return;
            } else {
                printf("Quantidade disponível: %d\n", produtos[j].quantidade);
            }
            printf("Preço: R$ %.2f\n", produtos[j].preco);
            printf("Digite a quantidade desejada: ");
            scanf("%d", &quantidade);
            preco = produtos[j].preco;
            if (quantidade <= produtos[j].quantidade) {
                produtos[j].quantidade -= quantidade;
                printf("Digite a data da venda (dd/mm/yyyy): ");
                scanf("%d/%d/%d", &vendas[*total_vendas].data[0], &vendas[*total_vendas].data[1], &vendas[*total_vendas].data[2]);
                printf("Digite o metodo de pagamento (crédito, débito ou dinheiro): ");
                scanf("%s", vendas[*total_vendas].metodo_pagamento);
                vendas[*total_vendas].valor = preco * quantidade;
                produtos[j].faturamento += preco * quantidade;
                strcpy(vendas[*total_vendas].nome, nome);
                vendas[*total_vendas].quantidade = quantidade;
                (*total_vendas)++;
                produtos[j].situacao = (produtos[j].quantidade <= 5) ? 0 : 1;
                printf("%sVenda realizada com sucesso!%s\n", VERDE, RESET);
            } else {
                printf("%sQuantidade insuficiente%s\n", VERMELHO, RESET);
                produtos[j].situacao = (produtos[j].quantidade <= 5) ? 0 : 1;
            }
            break;
        }
    }
    if (!encontrado) {
        printf("%sProduto não encontrado%s\n", VERMELHO, RESET);
    }
}
