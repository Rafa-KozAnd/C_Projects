#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 100
#define MAX_USUARIOS 100
#define MAX_EMPRESTIMOS 100

typedef struct {
    int id;
    char titulo[100];
    char autor[50];
    int disponivel;
} Livro;

typedef struct {
    int id;
    char nome[50];
} Usuario;

typedef struct {
    int idEmprestimo;
    int idLivro;
    int idUsuario;
    char dataEmprestimo[11];
    char dataDevolucao[11];
} Emprestimo;

Livro livros[MAX_LIVROS];
int numLivros = 0;
Usuario usuarios[MAX_USUARIOS];
int numUsuarios = 0;
Emprestimo emprestimos[MAX_EMPRESTIMOS];
int numEmprestimos = 0;

void cadastrarLivro() {
    if (numLivros >= MAX_LIVROS) {
        printf("Limite de livros atingido!\n");
        return;
    }

    Livro l;
    l.id = numLivros + 1;
    printf("Titulo do livro: ");
    scanf(" %[^\n]", l.titulo);
    printf("Autor do livro: ");
    scanf(" %[^\n]", l.autor);
    l.disponivel = 1;

    livros[numLivros++] = l;
    printf("Livro cadastrado com sucesso! ID do livro: %d\n", l.id);
}

void cadastrarUsuario() {
    if (numUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuarios atingido!\n");
        return;
    }

    Usuario u;
    u.id = numUsuarios + 1;
    printf("Nome do usuario: ");
    scanf(" %[^\n]", u.nome);

    usuarios[numUsuarios++] = u;
    printf("Usuario cadastrado com sucesso! ID do usuario: %d\n", u.id);
}

void realizarEmprestimo() {
    if (numEmprestimos >= MAX_EMPRESTIMOS) {
        printf("Limite de emprestimos atingido!\n");
        return;
    }

    int idLivro, idUsuario;
    printf("ID do livro: ");
    scanf("%d", &idLivro);
    printf("ID do usuario: ");
    scanf("%d", &idUsuario);

    if (idLivro < 1 || idLivro > numLivros || !livros[idLivro - 1].disponivel) {
        printf("ID de livro invalido ou indisponivel!\n");
        return;
    }

    if (idUsuario < 1 || idUsuario > numUsuarios) {
        printf("ID de usuario invalido!\n");
        return;
    }

    Emprestimo e;
    e.idEmprestimo = numEmprestimos + 1;
    e.idLivro = idLivro;
    e.idUsuario = idUsuario;
    printf("Data de emprestimo (dd/mm/yyyy): ");
    scanf("%s", e.dataEmprestimo);
    printf("Data de devolucao (dd/mm/yyyy): ");
    scanf("%s", e.dataDevolucao);

    livros[idLivro - 1].disponivel = 0;
    emprestimos[numEmprestimos++] = e;
    printf("Emprestimo realizado com sucesso!\n");
}

void devolverLivro() {
    int idEmprestimo;
    printf("ID do emprestimo: ");
    scanf("%d", &idEmprestimo);

    if (idEmprestimo < 1 || idEmprestimo > numEmprestimos) {
        printf("ID de emprestimo invalido!\n");
        return;
    }

    Emprestimo e = emprestimos[idEmprestimo - 1];
    livros[e.idLivro - 1].disponivel = 1;
    printf("Livro devolvido com sucesso!\n");
}

void exibirHistoricoEmprestimos() {
    printf("Historico de Emprestimos:\n");
    for (int i = 0; i < numEmprestimos; i++) {
        Emprestimo e = emprestimos[i];
        Livro l = livros[e.idLivro - 1];
        Usuario u = usuarios[e.idUsuario - 1];
        printf("Emprestimo %d\n", e.idEmprestimo);
        printf("Livro: %s (ID %d)\n", l.titulo, l.id);
        printf("Usuario: %s (ID %d)\n", u.nome, u.id);
        printf("Data de emprestimo: %s\n", e.dataEmprestimo);
        printf("Data de devolucao: %s\n", e.dataDevolucao);
        printf("\n");
    }
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Gerenciamento de Biblioteca ---\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Cadastrar Usuario\n");
        printf("3. Realizar Emprestimo\n");
        printf("4. Devolver Livro\n");
        printf("5. Exibir Historico de Emprestimos\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarLivro();
                break;
            case 2:
                cadastrarUsuario();
                break;
            case 3:
                realizarEmprestimo();
                break;
            case 4:
                devolverLivro();
                break;
            case 5:
                exibirHistoricoEmprestimos();
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
