#include "/home/viniciusperfeito/Documents/Repositorios/Sistema-de-Supermercado/include/supermercado.h"

void funcao_faturamento(Venda vendas[], int total_vendas) {
    printf("Faturamento\n");
    int opcao;
    int data[3];
    int faturamento_total = 0;
    // Pergunta a data de hoje para filtrar as vendas
    printf("Digite a data de hoje (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &data[0], &data[1], &data[2]);
    // Pergunta a opção de período de faturamento
    printf("Você deseja ter acesso a qual período de faturamento?\n");
    printf("1. Diário\n");
    printf("2. Semanal\n");
    printf("3. Mensal\n");
    printf("4. Anual\n");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            printf("Diário\n");
            for (int i = 0; i < total_vendas; i++) {
                // Verifica se a venda foi realizada na data informada
                if (vendas[i].data[0] == data[0] && vendas[i].data[1] == data[1] && vendas[i].data[2] == data[2]) {
                    printf("Venda %d: R$ %.2f\n", i + 1, vendas[i].valor);
                    faturamento_total += vendas[i].valor;
                }

            }
            break;
        case 2:
            printf("Semanal\n");
            for (int i = 0; i < total_vendas; i++) {
                // Cria uma variável para armazenar o número da semana
                int semanal = vendas[i].data[1] / 7;
                // Verifica se a venda foi realizada na data informada
                if (semanal == data[1] / 7 && vendas[i].data[2] == data[2]) {
                    printf("Venda %d: R$ %.2f\n", i + 1, vendas[i].valor);
                    faturamento_total += vendas[i].valor;
                }
            }
            break;
        case 3:
            printf("Mensal\n");
            for (int i = 0; i < total_vendas; i++) {
                // Verifica se a venda foi realizada na data informada
                if (vendas[i].data[1] == data[1] && vendas[i].data[2] == data[2]) {
                    printf("Venda %d: R$ %.2f\n", i + 1, vendas[i].valor);
                    faturamento_total += vendas[i].valor;
                }
            }
            break;
        case 4:
            printf("Anual\n");
            for (int i = 0; i < total_vendas; i++) {
                // Verifica se a venda foi realizada na data informada
                if (vendas[i].data[2] == data[2]) {
                    printf("Venda %d: R$ %.2f\n", i + 1, vendas[i].valor);
                    faturamento_total += vendas[i].valor;
                }
            }
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
}
