#include "../include/supermercado.h"

void funcao_faturamento(Venda vendas[], int total_vendas) {
    printf("\n========================================\n");
    printf("             FATURAMENTO\n");
    printf("========================================\n");

    int opcao;
    int data[3];
    double faturamento_total = 0;

    printf("Digite a data de hoje (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &data[0], &data[1], &data[2]);

    printf("\nPeriodo de faturamento:\n");
    printf("  1. Diario\n");
    printf("  2. Mensal\n");
    printf("  3. Anual\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    if (opcao < 1 || opcao > 3) {
        printf("\nOpcao invalida\n");
        return;
    }

    const char *periodos[] = {"DIARIO", "MENSAL", "ANUAL"};
    printf("\n--- Relatorio %s ---\n", periodos[opcao - 1]);
    printf("%-6s %-12s %-15s %s\n", "Venda", "Valor", "Pagamento", "Data");
    printf("------------------------------------------------\n");

    int alguma_venda = 0;
    for (int i = 0; i < total_vendas; i++) {
        int bate = 0;
        if (opcao == 1) {
            bate = (vendas[i].data[0] == data[0] && vendas[i].data[1] == data[1] && vendas[i].data[2] == data[2]);
        } else if (opcao == 2) {
            bate = (vendas[i].data[1] == data[1] && vendas[i].data[2] == data[2]);
        } else {
            bate = (vendas[i].data[2] == data[2]);
        }

        if (bate) {
            printf("%-6d R$ %-9.2f %-15s %02d/%02d/%04d\n",
                   i + 1, vendas[i].valor, vendas[i].metodo_pagamento,
                   vendas[i].data[0], vendas[i].data[1], vendas[i].data[2]);
            faturamento_total += vendas[i].valor;
            alguma_venda = 1;
        }
    }

    if (!alguma_venda) {
        printf("Nenhuma venda encontrada nesse periodo.\n");
    }

    printf("------------------------------------------------\n");
    printf("Faturamento total: R$ %.2f\n", faturamento_total);
    printf("========================================\n");
}
