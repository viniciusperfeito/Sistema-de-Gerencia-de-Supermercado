#include "../include/supermercado.h"

int funcao_busca_produtos(Produto produtos[], int total, char nome[], int silencioso) {

    for (int i = 0; i < total; i++) {

        if (strcmp(produtos[i].nome, nome) == 0) {

            if (!silencioso) {
                printf("\nProduto encontrado no ID %d\n", i);
                funcao_imprime_produtos(&produtos[i], 1, 1);
            }
            return i;
        }
    }

    if (!silencioso) {
        printf("\n✘ Produto nao encontrado.\n");
    }
    return -1;
}
