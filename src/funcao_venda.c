#include "../include/supermercado.h"

void funcao_venda_produtos(Produto produtos[], Venda vendas[], int total, int *total_vendas) {
    char nome[50];
    int quantidade;
    float preco;
    printf("Venda de Produtos\n");

    printf("Você fará a venda de qual produto?\n");
    scanf("%s", nome);
    for (int j = 0; j < total; j++) {
        if (strcmp(produtos[j].nome, nome) == 0) {
            printf("Produto encontrado: %s\n", produtos[j].nome);
            printf("Informações do produto:\n");
            if (produtos[j].quantidade == 0) {
                printf("Produto indisponível\n");
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
                vendas[*total_vendas].valor = preco * quantidade;
                strcpy(vendas[*total_vendas].nome, nome);
                vendas[*total_vendas].quantidade = quantidade;
                (*total_vendas)++;
            } else {
                printf("Quantidade insuficiente\n");
            }
            break;
        } else {
            printf("Produto não encontrado\n");
        }
    }
}
