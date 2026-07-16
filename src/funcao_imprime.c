#include "../include/supermercado.h"

void funcao_imprime_produtos(Produto produtos[], int total, int completo) {
    if (total == 0) {
        printf("%sNenhum produto cadastrado no estoque%s\n", AMARELO, RESET);
        return;
    }

    printf("\n RELATORIO DE ESTOQUE \n");

    if (completo) {
        printf("%-4s %-20s %-12s %-12s %-15s %s\n", "ID", "Nome", "Quantidade", "Preco", "Faturamento", "Situacao");
        printf("--------------------------------------------------------------------\n");
    }

    for (int i = 0; i < total; i++) {
        if (completo) {
            char situacao_str[40];
            if (produtos[i].situacao == 0) {
                sprintf(situacao_str, "%sREPOSICAO%s", VERMELHO, RESET);
            } else {
                sprintf(situacao_str, "%sOK%s", VERDE, RESET);
            }
            printf("%-4d %-20s %-12d R$ %-9.2f R$ %-12.2f %s\n",
                   i, produtos[i].nome, produtos[i].quantidade, produtos[i].preco,
                   produtos[i].faturamento, situacao_str);
        } else {
            printf("ID: %d | Nome: %s\n", i, produtos[i].nome);
        }
    }
}
