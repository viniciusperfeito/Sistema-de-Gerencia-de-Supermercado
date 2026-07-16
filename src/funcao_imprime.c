#include "../include/supermercado.h"

void funcao_imprime_produtos(Produto produtos[], int total, int completo) {

    // Verifica se existem produtos cadastrados
    if (total == 0) {
        printf("Nenhum produto cadastrado no estoque\n");
        return;
    }

    printf("\n========================================\n");
    printf("       RELATORIO DE ESTOQUE\n");
    printf("========================================\n");

    for (int i = 0; i < total; i++) {

        if (completo) {
            // Imprime nome e demais dados do produto
            printf("%-4s %-20s %-12s %-12s %-15s %s\n", "ID", "Nome", "Quantidade", "Preco", "Faturamento", "Situacao");
            printf("--------------------------------------------------------------------\n");
            for (int i = 0; i < total; i++) {
                printf("%-4d %-20s %-12d R$ %-9.2f R$ %-12.2f %s\n",
                       i, produtos[i].nome, produtos[i].quantidade, produtos[i].preco,
                       produtos[i].faturamento, (produtos[i].situacao == 0) ? "REPOSICAO" : "OK");
            }
            puts("");
        } else {
            // Imprime somente o nome do produto
            printf("ID: %d | Nome: %s\n", i, produtos[i].nome);
            puts("");
        }
    }
}
