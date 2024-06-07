#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rolarDado() {
    return rand() % 6 + 1;
}

void jogar() {
    int jogador1, jogador2;

    printf("Jogador 1, pressione Enter para rolar o dado...");
    getchar();
    jogador1 = rolarDado();
    printf("Jogador 1 rolou: %d\n", jogador1);

    printf("Jogador 2, pressione Enter para rolar o dado...");
    getchar();
    jogador2 = rolarDado();
    printf("Jogador 2 rolou: %d\n", jogador2);

    if (jogador1 > jogador2) {
        printf("Jogador 1 vence!\n");
    } else if (jogador2 > jogador1) {
        printf("Jogador 2 vence!\n");
    } else {
        printf("Empate!\n");
    }
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Jogo de Dados ---\n");
        printf("1. Jogar\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Para consumir a nova linha deixada pelo scanf

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
