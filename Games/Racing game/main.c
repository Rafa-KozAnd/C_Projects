#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int posicao;
} Corredor;

void inicializarCorredor(Corredor *corredor) {
    corredor->posicao = 0;
}

void moverCorredor(Corredor *corredor) {
    corredor->posicao += rand() % 6 + 1; // Avança uma quantidade aleatória de casas (1-6)
}

int verificarVencedor(Corredor *jogador, Corredor *adversario) {
    if (jogador->posicao >= 100 && jogador->posicao > adversario->posicao) {
        return 1; // Jogador venceu
    } else if (adversario->posicao >= 100 && adversario->posicao > jogador->posicao) {
        return -1; // Adversário venceu
    }
    return 0; // Ninguém venceu ainda
}

void jogar() {
    Corredor jogador, adversario;
    inicializarCorredor(&jogador);
    inicializarCorredor(&adversario);

    while (1) {
        moverCorredor(&jogador);
        moverCorredor(&adversario);

        printf("Jogador: %d\n", jogador.posicao);
        printf("Adversario: %d\n", adversario.posicao);

        int resultado = verificarVencedor(&jogador, &adversario);
        if (resultado == 1) {
            printf("Voce venceu!\n");
            break;
        } else if (resultado == -1) {
            printf("Voce perdeu!\n");
            break;
        }

        printf("Pressione Enter para continuar...");
        getchar(); // Aguarda a entrada do jogador para continuar
    }
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Jogo de Corrida ---\n");
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
