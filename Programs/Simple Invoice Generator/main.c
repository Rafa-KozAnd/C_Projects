#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_NOTAS 100
#define MAX_ITENS 10

typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

typedef struct {
    int numero;
    char cliente[50];
    Produto itens[MAX_ITENS];
    int quantidade[MAX_ITENS];
    int numItens;
    float total;
} NotaFiscal;

Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;
NotaFiscal notas[MAX_NOTAS];
int numNotas = 0;

void cadastrarProduto() {
    if (numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }
    
    Produto p;
    p.codigo = numProdutos + 1;
    printf("Nome do produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Preco do produto: ");
    scanf("%f", &p.preco);
    
    produtos[numProdutos++] = p;
    printf("Produto cadastrado com sucesso!\n");
}

void emitirNotaFiscal() {
    if (numNotas >= MAX_NOTAS) {
        printf("Limite de notas fiscais atingido!\n");
        return;
    }

    NotaFiscal nf;
    nf.numero = numNotas + 1;
    nf.total = 0;
    nf.numItens = 0;
    
    printf("Nome do cliente: ");
    scanf(" %[^\n]", nf.cliente);

    int continuar = 1;
    while (continuar) {
        printf("Codigo do produto (1 a %d): ", numProdutos);
        int codigo;
        scanf("%d", &codigo);
        if (codigo < 1 || codigo > numProdutos) {
            printf("Codigo invalido!\n");
            continue;
        }
        
        Produto p = produtos[codigo - 1];
        nf.itens[nf.numItens] = p;
        printf("Quantidade: ");
        scanf("%d", &nf.quantidade[nf.numItens]);
        nf.total += p.preco * nf.quantidade[nf.numItens];
        nf.numItens++;
        
        printf("Deseja adicionar mais um item? (1-Sim, 0-Nao): ");
        scanf("%d", &continuar);
    }

    notas[numNotas++] = nf;
    printf("Nota fiscal emitida com sucesso!\n");
}

void exibirHistoricoNotas() {
    for (int i = 0; i < numNotas; i++) {
        NotaFiscal nf = notas[i];
        printf("Nota Fiscal %d\n", nf.numero);
        printf("Cliente: %s\n", nf.cliente);
        printf("Itens:\n");
        for (int j = 0; j < nf.numItens; j++) {
            printf("%d x %s (R$ %.2f)\n", nf.quantidade[j], nf.itens[j].nome, nf.itens[j].preco);
        }
        printf("Total: R$ %.2f\n\n", nf.total);
    }
}

void menu() {
    int opcao;
    do {
        printf("1. Cadastrar Produto\n");
        printf("2. Emitir Nota Fiscal\n");
        printf("3. Exibir Historico de Notas Fiscais\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                emitirNotaFiscal();
                break;
            case 3:
                exibirHistoricoNotas();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
}

int main() {
    menu();
    return 0;
}
