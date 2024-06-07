#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5

typedef struct {
    int linhas;
    int colunas;
    char grade[TAMANHO][TAMANHO];
    int tesouro_linha;
    int tesouro_coluna;
} Tabuleiro;

void inicializarTabuleiro(Tabuleiro *tab) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tab->grade[i][j] = '~'; // '~' representa terra
        }
    }
}

void exibirTabuleiro(Tabuleiro *tab) {
    printf("  ");
    for (int j = 0; j < TAMANHO; j++) {
        printf("%d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tab->grade[i][j]);
        }
        printf("\n");
    }
}

void esconderTesouro(Tabuleiro *tab) {
    srand(time(NULL));
    tab->tesouro_linha = rand() % TAMANHO;
    tab->tesouro_coluna = rand() % TAMANHO;
    tab->grade[tab->tesouro_linha][tab->tesouro_coluna] = 'T'; // 'T' representa o tesouro
}

int verificarProximidade(Tabuleiro *tab, int linha, int coluna) {
    int lin_diff = abs(linha - tab->tesouro_linha);
    int col_diff = abs(coluna - tab->tesouro_coluna);
    int distancia = lin_diff + col_diff;
    return distancia;
}

void jogar() {
    Tabuleiro tab;
    inicializarTabuleiro(&tab);
    esconderTesouro(&tab);

    int linha, coluna;
    while (1) {
        printf("\nTabuleiro:\n");
        exibirTabuleiro(&tab);

        printf("Entre com a linha e a coluna para procurar o tesouro: ");
        scanf("%d %d", &linha, &coluna);
        linha--;
        coluna--;

        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
            printf("Coordenadas invalidas. Tente novamente.\n");
            continue;
        }

        int distancia = verificarProximidade(&tab, linha, coluna);
        if (distancia == 0) {
            printf("Parabens! Voce encontrou o tesouro!\n");
            break;
        } else {
            printf("Voce esta a uma distancia de %d do tesouro.\n", distancia);
        }
    }
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Caca ao Tesouro ---\n");
        printf("1. Jogar\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                jogar();
                break;
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 2);
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    menu();
    return 0;
}
