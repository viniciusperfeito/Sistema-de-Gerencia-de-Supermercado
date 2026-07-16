#include "../include/supermercado.h"

Produto produtos[MAX_PRODUTOS];     // Produto vetor e total
Venda vendas[MAX_VENDAS];           // Venda vetor e total

int main(void) {
    int total = 0;      // Total de produtos cadastrados
    int total_vendas = 0;   // Total de vendas realizadas

    printf("\n========================================\n");
    printf("%s       SISTEMA DE SUPERMERCADO%s\n", AZUL, RESET);
    printf("========================================\n");

    int opcao = -1; // Variavel de opcao do usuario
    while (opcao != 0) {
        printf("\nDigite a opção desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Controle de Estoque\n");
        printf("3 - Mostrar nome dos produtos\n");
        printf("4 - Exiba os dados dos produtos\n");
        printf("5 - Realizar venda\n");
        printf("6 - Exibir relatório de vendas\n");
        printf("7 - Buscar produto\n");
        scanf("%d", &opcao);
        while (getchar() != '\n');  // descarta o \n (e qualquer lixo) que sobrou no buffer

        switch (opcao) {
            case 0:
                printf("%sEncerrando o sistema...%s\n", AMARELO, RESET);
                break;
            case 1:
                funcao_cadastra_produtos(produtos, &total);
                break;
            case 2:
                funcao_controle_estoque(produtos, total);
                break;
            case 3:
                funcao_imprime_produtos(produtos, total, 0);
                break;
            case 4:
                funcao_imprime_produtos(produtos, total, 1);
                break;
            case 5:
                funcao_venda_produtos(produtos, vendas, total, &total_vendas);
                break;
            case 6:
                funcao_faturamento(vendas, total_vendas);
                break;
            case 7:
                {
                    char nome[50];
                    printf("Digite o nome do produto: ");
                    scanf(" %49[^\n]", nome);
                    funcao_busca_produtos(produtos, total, nome, 0);
                }
                break;
            default:
                printf("\n%sOpção inválida%s\n\n", VERMELHO, RESET);
                break;
        }
    }

    return 0;
}
