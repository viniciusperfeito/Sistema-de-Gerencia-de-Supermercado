#include "../include/supermercado.h"

void funcao_cadastra_produtos(Produto produtos[], int *total) {

    // Verifica se o estoque atingiu o limite máximo
    if (*total >= MAX_PRODUTOS) {
        printf("Erro: Limite maximo de produtos atingido\n");
        return;
    }

    char nome_temp[50];

    printf("\nNome do produto: ");
    scanf(" %49[^\n]", nome_temp);

    // Verifica se o produto ja existe usando a funcao busca (modo silencioso)
    int indice = funcao_busca_produtos(produtos, *total, nome_temp, 1);

    if (indice != -1) {
        // Produto ja cadastrado, apenas atualiza a quantidade
        int qtd_adicional;
        printf("Produto ja cadastrado. Quantidade atual: %d\n", produtos[indice].quantidade);
        printf("Quantidade a adicionar: ");
        scanf("%d", &qtd_adicional);

        produtos[indice].quantidade += qtd_adicional;
        produtos[indice].situacao = (produtos[indice].quantidade <= 5) ? 0 : 1;

        funcao_imprime_produtos(&produtos[indice], 1, 1);
        return;
    }

    // Produto novo, armazena os dados
    strcpy(produtos[*total].nome, nome_temp);

    printf("Quantidade: ");
    scanf("%d", &produtos[*total].quantidade);

    printf("Preco: ");
    scanf("%f", &produtos[*total].preco);

    produtos[*total].faturamento = 0;
    produtos[*total].situacao = (produtos[*total].quantidade <= 5) ? 0 : 1;

    (*total)++;

    // Mostra o produto recem-cadastrado usando a funcao imprime
    funcao_imprime_produtos(&produtos[*total - 1], 1, 1);
}
