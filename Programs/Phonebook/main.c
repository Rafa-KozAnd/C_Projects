#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
    int id;
    char nome[50];
    char telefone[15];
} Contato;

Contato contatos[MAX_CONTATOS];
int numContatos = 0;

void adicionarContato() {
    if (numContatos >= MAX_CONTATOS) {
        printf("Limite de contatos atingido!\n");
        return;
    }

    Contato c;
    c.id = numContatos + 1;
    printf("Nome: ");
    scanf(" %[^\n]", c.nome);
    printf("Telefone: ");
    scanf(" %[^\n]", c.telefone);

    contatos[numContatos++] = c;
    printf("Contato adicionado com sucesso! ID do contato: %d\n", c.id);
}

void visualizarContatos() {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        Contato c = contatos[i];
        printf("ID: %d\n", c.id);
        printf("Nome: %s\n", c.nome);
        printf("Telefone: %s\n", c.telefone);
        printf("\n");
    }
}

void editarContato() {
    int id;
    printf("ID do contato a ser editado: ");
    scanf("%d", &id);

    if (id < 1 || id > numContatos) {
        printf("ID de contato invalido!\n");
        return;
    }

    Contato *c = &contatos[id - 1];
    printf("Novo nome: ");
    scanf(" %[^\n]", c->nome);
    printf("Novo telefone: ");
    scanf(" %[^\n]", c->telefone);
    printf("Contato editado com sucesso!\n");
}

void excluirContato() {
    int id;
    printf("ID do contato a ser excluido: ");
    scanf("%d", &id);

    if (id < 1 || id > numContatos) {
        printf("ID de contato invalido!\n");
        return;
    }

    for (int i = id - 1; i < numContatos - 1; i++) {
        contatos[i] = contatos[i + 1];
    }
    numContatos--;
    printf("Contato excluido com sucesso!\n");
}

void buscarContato() {
    char nome[50];
    printf("Nome do contato a buscar: ");
    scanf(" %[^\n]", nome);

    printf("Resultados da busca:\n");
    for (int i = 0; i < numContatos; i++) {
        if (strstr(contatos[i].nome, nome) != NULL) {
            Contato c = contatos[i];
            printf("ID: %d\n", c.id);
            printf("Nome: %s\n", c.nome);
            printf("Telefone: %s\n", c.telefone);
            printf("\n");
        }
    }
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Agenda Telefonica ---\n");
        printf("1. Adicionar Contato\n");
        printf("2. Visualizar Contatos\n");
        printf("3. Editar Contato\n");
        printf("4. Excluir Contato\n");
        printf("5. Buscar Contato\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                visualizarContatos();
                break;
            case 3:
                editarContato();
                break;
            case 4:
                excluirContato();
                break;
            case 5:
                buscarContato();
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
