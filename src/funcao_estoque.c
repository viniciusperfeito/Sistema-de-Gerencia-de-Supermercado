#include "../include/supermercado.h"

void funcao_controle_estoque(Produto produtos[], int total) {
    printf("\n========================================\n");
    printf("       CONTROLE DE ESTOQUE\n");
    printf("========================================\n");
    printf("Produtos com estoque baixo:\n");
    int algum_baixo = 0;
    for (int i = 0; i < total; i++) {
        if (produtos[i].quantidade <= 5) {
            printf("%s - Quantidade: %d\n", produtos[i].nome, produtos[i].quantidade);
            puts("");
        }
    }
    if (!algum_baixo) {
        printf("Nenhum produto com estoque baixo.\n");
        puts("");
    }
}
