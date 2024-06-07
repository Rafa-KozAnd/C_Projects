#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATOS 10

typedef struct {
    int id;
    char nome[50];
    int votos;
} Candidato;

Candidato candidatos[MAX_CANDIDATOS];
int numCandidatos = 0;

void cadastrarCandidato() {
    if (numCandidatos >= MAX_CANDIDATOS) {
        printf("Limite de candidatos atingido!\n");
        return;
    }

    Candidato c;
    c.id = numCandidatos + 1;
    printf("Nome do candidato: ");
    scanf(" %[^\n]", c.nome);
    c.votos = 0;

    candidatos[numCandidatos++] = c;
    printf("Candidato cadastrado com sucesso! ID do candidato: %d\n", c.id);
}

void registrarVoto() {
    int id;
    printf("ID do candidato: ");
    scanf("%d", &id);

    if (id < 1 || id > numCandidatos) {
        printf("ID de candidato invalido!\n");
        return;
    }

    candidatos[id - 1].votos++;
    printf("Voto registrado com sucesso!\n");
}

void exibirResultados() {
    printf("Resultados da Votacao:\n");
    for (int i = 0; i < numCandidatos; i++) {
        Candidato c = candidatos[i];
        printf("ID: %d\n", c.id);
        printf("Candidato: %s\n", c.nome);
        printf("Votos: %d\n", c.votos);
        printf("\n");
    }
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Sistema de Votacao ---\n");
        printf("1. Cadastrar Candidato\n");
        printf("2. Registrar Voto\n");
        printf("3. Exibir Resultados\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCandidato();
                break;
            case 2:
                registrarVoto();
                break;
            case 3:
                exibirResultados();
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
