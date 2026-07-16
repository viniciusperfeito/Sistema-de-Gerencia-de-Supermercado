#include "../include/supermercado.h"

void funcao_imprime_produtos(Produto produtos[], int total, int completo) {

    // Verifica se existem produtos cadastrados
    if (total == 0) {
        printf("Nenhum produto cadastrado no estoque\n");
        return;
    }

    printf("\n RELATORIO DE ESTOQUE \n");

    for (int i = 0; i < total; i++) {

        if (completo) {
            // Imprime nome e demais dados do produto
            printf("ID: %d | Nome: %s | Quantidade: %d | Preco: R$ %.2f | Faturamento: R$ %.2f | Situacao: %s\n",
                   i, produtos[i].nome, produtos[i].quantidade, produtos[i].preco,
                   produtos[i].faturamento, (produtos[i].situacao == 0) ? "REPOSICAO" : "OK");
        } else {
            // Imprime somente o nome do produto
            printf("ID: %d | Nome: %s\n", i, produtos[i].nome);
        }
    }
}
