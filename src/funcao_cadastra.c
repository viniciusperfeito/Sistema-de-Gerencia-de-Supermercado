#include "../include/supermercado.h"

void funcao_cadastra_produtos(Produto produtos[], int *total) {

    if (*total >= MAX_PRODUTOS) {
        printf("%sErro: Limite maximo de produtos atingido%s\n", VERMELHO, RESET);
        return;
    }

    char nome_temp[50];

    printf("\nNome do produto: ");
    scanf(" %49[^\n]", nome_temp);

    int indice = funcao_busca_produtos(produtos, *total, nome_temp, 1);

    if (indice != -1) {
        int qtd_adicional;
        printf("%sProduto ja cadastrado.%s Quantidade atual: %d\n", AMARELO, RESET, produtos[indice].quantidade);
        printf("Quantidade a adicionar: ");
        scanf("%d", &qtd_adicional);

        produtos[indice].quantidade += qtd_adicional;
        produtos[indice].situacao = (produtos[indice].quantidade <= 5) ? 0 : 1;

        printf("%sEstoque atualizado com sucesso!%s\n", VERDE, RESET);
        funcao_imprime_produtos(&produtos[indice], 1, 1);
        return;
    }

    strcpy(produtos[*total].nome, nome_temp);

    printf("Quantidade: ");
    scanf("%d", &produtos[*total].quantidade);

    printf("Preco: ");
    scanf("%f", &produtos[*total].preco);

    produtos[*total].faturamento = 0;
    produtos[*total].situacao = (produtos[*total].quantidade <= 5) ? 0 : 1;

    (*total)++;

    printf("%sProduto cadastrado com sucesso!%s\n", VERDE, RESET);
    funcao_imprime_produtos(&produtos[*total - 1], 1, 1);
}
