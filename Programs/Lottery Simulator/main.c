#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMEROS 6
#define MAX_VALOR 60

void escolherNumeros(int* numerosEscolhidos) {
    printf("Escolha %d numeros entre 1 e %d:\n", MAX_NUMEROS, MAX_VALOR);
    for (int i = 0; i < MAX_NUMEROS; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numerosEscolhidos[i]);
        while (numerosEscolhidos[i] < 1 || numerosEscolhidos[i] > MAX_VALOR) {
            printf("Numero invalido! Escolha um numero entre 1 e %d: ", MAX_VALOR);
            scanf("%d", &numerosEscolhidos[i]);
        }
    }
}

void gerarNumerosVencedores(int* numerosVencedores) {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUMEROS; i++) {
        numerosVencedores[i] = rand() % MAX_VALOR + 1;
    }
}

int verificarAcertos(int* numerosEscolhidos, int* numerosVencedores) {
    int acertos = 0;
    for (int i = 0; i < MAX_NUMEROS; i++) {
        for (int j = 0; j < MAX_NUMEROS; j++) {
            if (numerosEscolhidos[i] == numerosVencedores[j]) {
                acertos++;
                break;
            }
        }
    }
    return acertos;
}

void exibirResultados(int* numerosEscolhidos, int* numerosVencedores, int acertos) {
    printf("\nNumeros escolhidos: ");
    for (int i = 0; i < MAX_NUMEROS; i++) {
        printf("%d ", numerosEscolhidos[i]);
    }
    printf("\nNumeros vencedores: ");
    for (int i = 0; i < MAX_NUMEROS; i++) {
        printf("%d ", numerosVencedores[i]);
    }
    printf("\nVoce acertou %d numero(s)!\n", acertos);
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Simulador de Loteria ---\n");
        printf("1. Jogar\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int numerosEscolhidos[MAX_NUMEROS];
                int numerosVencedores[MAX_NUMEROS];
                escolherNumeros(numerosEscolhidos);
                gerarNumerosVencedores(numerosVencedores);
                int acertos = verificarAcertos(numerosEscolhidos, numerosVencedores);
                exibirResultados(numerosEscolhidos, numerosVencedores, acertos);
                break;
            }
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 2);
}

int main() {
    menu();
    return 0;
}
