#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;

void cadastrarProduto() {
    if (numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto p;
    p.id = numProdutos + 1;
    printf("Nome do produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Preco do produto: ");
    scanf("%f", &p.preco);
    p.quantidade = 0;

    produtos[numProdutos++] = p;
    printf("Produto cadastrado com sucesso! ID do produto: %d\n", p.id);
}

void entradaProduto() {
    int id, quantidade;
    printf("ID do produto: ");
    scanf("%d", &id);

    if (id < 1 || id > numProdutos) {
        printf("ID de produto invalido!\n");
        return;
    }

    printf("Quantidade de entrada: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade invalida!\n");
        return;
    }

    produtos[id - 1].quantidade += quantidade;
    printf("Entrada de produto realizada com sucesso!\n");
}

void saidaProduto() {
    int id, quantidade;
    printf("ID do produto: ");
    scanf("%d", &id);

    if (id < 1 || id > numProdutos) {
        printf("ID de produto invalido!\n");
        return;
    }

    printf("Quantidade de saida: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0 || quantidade > produtos[id - 1].quantidade) {
        printf("Quantidade invalida!\n");
        return;
    }

    produtos[id - 1].quantidade -= quantidade;
    printf("Saida de produto realizada com sucesso!\n");
}

void verificarEstoque() {
    int id;
    printf("ID do produto: ");
    scanf("%d", &id);

    if (id < 1 || id > numProdutos) {
        printf("ID de produto invalido!\n");
        return;
    }

    Produto p = produtos[id - 1];
    printf("Produto: %s\n", p.nome);
    printf("Quantidade em estoque: %d\n", p.quantidade);
    printf("Preco: R$ %.2f\n", p.preco);
}

void exibirRelatorio() {
    printf("Relatorio de Estoque:\n");
    for (int i = 0; i < numProdutos; i++) {
        Produto p = produtos[i];
        printf("ID: %d\n", p.id);
        printf("Produto: %s\n", p.nome);
        printf("Quantidade em estoque: %d\n", p.quantidade);
        printf("Preco: R$ %.2f\n", p.preco);
        printf("\n");
    }
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Gerenciador de Estoque ---\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Entrada de Produto\n");
        printf("3. Saida de Produto\n");
        printf("4. Verificar Estoque\n");
        printf("5. Exibir Relatorio de Estoque\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                entradaProduto();
                break;
            case 3:
                saidaProduto();
                break;
            case 4:
                verificarEstoque();
                break;
            case 5:
                exibirRelatorio();
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);
}

int main() {
    menu();
    return 0;
}
