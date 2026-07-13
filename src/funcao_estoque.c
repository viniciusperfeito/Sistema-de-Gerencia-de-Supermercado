#include "../include/supermercado.h"

void funcao_controle_estoque(Produto produtos[], int total) {
    printf("Controle de Estoque\n");
    printf("Produtos com estoque baixo:\n");
    for (int i = 0; i < total; i++) {
        if (produtos[i].quantidade <= 5) {
            printf("%s - Quantidade: %d\n", produtos[i].nome, produtos[i].quantidade);
        }
        puts("");
    }
}
