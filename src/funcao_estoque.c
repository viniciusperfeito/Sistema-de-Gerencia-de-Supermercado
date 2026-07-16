#include "../include/supermercado.h"

void funcao_controle_estoque(Produto produtos[], int total) {
    printf("\n========================================\n");
    printf("          CONTROLE DE ESTOQUE\n");
    printf("========================================\n");
    printf("Produtos com estoque baixo:\n");

    for (int i = 0; i < total; i++) {
        if (produtos[i].quantidade <= 5) {
            printf("%s%s%s - Quantidade: %d\n", VERMELHO, produtos[i].nome, RESET, produtos[i].quantidade);
            puts("");
        }
    }
    printf("========================================\n");
}
