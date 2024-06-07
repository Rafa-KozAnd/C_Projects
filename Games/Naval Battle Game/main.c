#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5

typedef struct {
    int linhas;
    int colunas;
    char grade[TAMANHO][TAMANHO];
} Tabuleiro;

void inicializarTabuleiro(Tabuleiro *tab) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tab->grade[i][j] = '~'; // '~' representa água
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

void posicionarNavio(Tabuleiro *tab, int linha, int coluna) {
    tab->grade[linha][coluna] = 'N'; // 'N' representa um navio
}

int realizarAtaque(Tabuleiro *tab, int linha, int coluna) {
    if (tab->grade[linha][coluna] == 'N') {
        tab->grade[linha][coluna] = 'X'; // 'X' representa um navio atingido
        return 1;
    } else {
        tab->grade[linha][coluna] = '*'; // '*' representa um tiro na água
        return 0;
    }
}

int verificarVencedor(Tabuleiro *tab) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tab->grade[i][j] == 'N') {
                return 0; // Ainda há navios não atingidos
            }
        }
    }
    return 1; // Todos os navios foram atingidos
}

void jogar() {
    Tabuleiro jogador1, jogador2;
    inicializarTabuleiro(&jogador1);
    inicializarTabuleiro(&jogador2);

    // Posicionamento de navios para os jogadores (simples para o exemplo)
    posicionarNavio(&jogador1, 1, 1);
    posicionarNavio(&jogador1, 2, 2);
    posicionarNavio(&jogador2, 3, 3);
    posicionarNavio(&jogador2, 4, 4);

    int linha, coluna;
    int turno = 1; // 1 para Jogador 1, 2 para Jogador 2
    while (1) {
        printf("\nTabuleiro do Jogador %d:\n", turno);
        exibirTabuleiro(turno == 1 ? &jogador1 : &jogador2);

        printf("Jogador %d, entre com a linha e a coluna para atacar: ", turno);
        scanf("%d %d", &linha, &coluna);
        linha--;
        coluna--;

        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
            printf("Coordenadas invalidas. Tente novamente.\n");
            continue;
        }

        int resultado = realizarAtaque(turno == 1 ? &jogador2 : &jogador1, linha, coluna);
        if (resultado) {
            printf("Acertou!\n");
        } else {
            printf("Errou.\n");
        }

        if (verificarVencedor(turno == 1 ? &jogador2 : &jogador1)) {
            printf("Jogador %d venceu!\n", turno);
            break;
        }

        turno = turno == 1 ? 2 : 1;
    }
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Batalha Naval ---\n");
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
