#include "../include/supermercado.h"

int main(void) {
    Produto produtos[MAX_PRODUTOS];     // Produto vetor e total
    Venda vendas[MAX_VENDAS];         // Venda vetor e total
    int total = 0;      // Total de produtos cadastrados
    int total_vendas = 0;   // Total de vendas realizadas
    printf("Sistema de Supermercado\n"); // Titulo do Menu
    int opcao = -1; // Variavel de opcao do usuario
    while (opcao != 0) {
        printf("Digite a opção desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Controle de Estoque\n");
        printf("3 - Mostrar nome dos produtos\n");
        printf("4 - Exiba os dados dos produtos\n");
        printf("5 - Realizar venda\n");
        printf("6 - Exibir relatório de vendas\n");
        scanf("%d", &opcao);
        // Switch para executar a opcao escolhida pelo usuario
        switch (opcao) {
            case 0:
                       printf("Encerrando o sistema...\n");
                       break;
            case 1:

            case 2:
                funcao_controle_estoque(produtos, total);
                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                funcao_venda_produtos(produtos, vendas, total, &total_vendas);
                break;
            case 6:
                funcao_faturamento(vendas, total_vendas);
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    }
}
