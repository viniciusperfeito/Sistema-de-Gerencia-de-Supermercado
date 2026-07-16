#include "../include/supermercado.h"

void funcao_controle_estoque(Produto produtos[], int total) {
    printf("\n========================================\n");
    printf("          CONTROLE DE ESTOQUE\n");
    printf("========================================\n");

    int algum_baixo = 0;
    for (int i = 0; i < total; i++) {
        if (produtos[i].quantidade <= 5) {
            printf("%s%s%s - Quantidade: %d\n", VERMELHO, produtos[i].nome, RESET, produtos[i].quantidade);
            algum_baixo = 1;
        }
    }

    if (!algum_baixo) {
        printf("%sNenhum produto com estoque baixo.%s\n", VERDE, RESET);
    }
    printf("========================================\n");
}
