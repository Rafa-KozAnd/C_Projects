#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100
#define MAX_NOME 50

typedef struct {
    int id;
    char nome[MAX_NOME];
    int presencas;
    int totalAulas;
} Aluno;

Aluno alunos[MAX_ALUNOS];
int numAlunos = 0;

void cadastrarAluno() {
    if (numAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    Aluno a;
    a.id = numAlunos + 1;
    printf("Nome do aluno: ");
    scanf(" %[^\n]", a.nome);
    a.presencas = 0;
    a.totalAulas = 0;

    alunos[numAlunos++] = a;
    printf("Aluno cadastrado com sucesso! ID do aluno: %d\n", a.id);
}

void registrarPresenca() {
    int id;
    printf("ID do aluno: ");
    scanf("%d", &id);

    if (id < 1 || id > numAlunos) {
        printf("ID de aluno invalido!\n");
        return;
    }

    alunos[id - 1].presencas++;
    alunos[id - 1].totalAulas++;
    printf("Presenca registrada com sucesso!\n");
}

void visualizarFrequencia() {
    printf("Lista de Frequencia:\n");
    for (int i = 0; i < numAlunos; i++) {
        Aluno a = alunos[i];
        printf("ID: %d\n", a.id);
        printf("Nome: %s\n", a.nome);
        printf("Presencas: %d\n", a.presencas);
        printf("Total de Aulas: %d\n", a.totalAulas);
        printf("Frequencia: %.2f%%\n", a.totalAulas == 0 ? 0.0 : (a.presencas / (float)a.totalAulas) * 100);
        printf("\n");
    }
}

void gerarRelatorio() {
    char nomeArquivo[MAX_NOME];
    printf("Nome do arquivo de relatorio: ");
    scanf("%s", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }

    fprintf(arquivo, "Relatorio de Frequencia:\n");
    for (int i = 0; i < numAlunos; i++) {
        Aluno a = alunos[i];
        fprintf(arquivo, "ID: %d\n", a.id);
        fprintf(arquivo, "Nome: %s\n", a.nome);
        fprintf(arquivo, "Presencas: %d\n", a.presencas);
        fprintf(arquivo, "Total de Aulas: %d\n", a.totalAulas);
        fprintf(arquivo, "Frequencia: %.2f%%\n", a.totalAulas == 0 ? 0.0 : (a.presencas / (float)a.totalAulas) * 100);
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Relatorio gerado com sucesso!\n");
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Controle de Frequencia Escolar ---\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Registrar Presenca\n");
        printf("3. Visualizar Frequencia\n");
        printf("4. Gerar Relatorio\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                registrarPresenca();
                break;
            case 3:
                visualizarFrequencia();
                break;
            case 4:
                gerarRelatorio();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);
}

int main() {
    menu();
    return 0;
}
