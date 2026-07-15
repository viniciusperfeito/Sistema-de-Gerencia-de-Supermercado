# Sistema de Gerência de Supermercado

Trabalho da disciplina de Algoritmos e Programação de Computadores I (APC1) — UFCAT, desenvolvido em dupla.

## Descrição

Sistema em linguagem C para gerenciamento de um supermercado, incluindo controle de estoque, cadastro de produtos, vendas e relatórios de faturamento.

## Funcionalidades

- Cadastro de produtos (com verificação de duplicidade)
- Controle de estoque (identifica produtos com quantidade baixa)
- Impressão de produtos (nome apenas, ou dados completos)
- Busca de produtos por nome
- Venda de produtos (crédito, débito ou dinheiro)
- Relatório de faturamento (diário, mensal ou anual)

## Estrutura do projeto

```
include/supermercado.h   - structs e protótipos das funções
src/main.c               - menu principal
src/*.c                  - implementação de cada função
```

### Compilação e execução
```
gcc src/*.c -Iinclude -o supermercado
```
# Linux/Mac:
```
./supermercado
```
# Windows (cmd/PowerShell):
```
supermercado.exe
```
## Licença

Este projeto está sob a licença MIT — veja o arquivo LICENSE.
