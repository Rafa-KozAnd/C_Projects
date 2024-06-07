#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTES 100

typedef struct {
    int id;
    char nome[50];
    float saldo;
} Cliente;

Cliente clientes[MAX_CLIENTES];
int numClientes = 0;

void cadastrarCliente() {
    if (numClientes >= MAX_CLIENTES) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    Cliente c;
    c.id = numClientes + 1;
    printf("Nome do cliente: ");
    scanf(" %[^\n]", c.nome);
    c.saldo = 0.0;

    clientes[numClientes++] = c;
    printf("Cliente cadastrado com sucesso! ID do cliente: %d\n", c.id);
}

void consultarSaldo() {
    int id;
    printf("ID do cliente: ");
    scanf("%d", &id);

    if (id < 1 || id > numClientes) {
        printf("ID de cliente invalido!\n");
        return;
    }

    Cliente c = clientes[id - 1];
    printf("Saldo do cliente %s (ID %d): R$ %.2f\n", c.nome, c.id, c.saldo);
}

void depositar() {
    int id;
    float valor;
    printf("ID do cliente: ");
    scanf("%d", &id);

    if (id < 1 || id > numClientes) {
        printf("ID de cliente invalido!\n");
        return;
    }

    printf("Valor do deposito: R$ ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("Valor de deposito invalido!\n");
        return;
    }

    clientes[id - 1].saldo += valor;
    printf("Deposito realizado com sucesso!\n");
}

void sacar() {
    int id;
    float valor;
    printf("ID do cliente: ");
    scanf("%d", &id);

    if (id < 1 || id > numClientes) {
        printf("ID de cliente invalido!\n");
        return;
    }

    printf("Valor do saque: R$ ");
    scanf("%f", &valor);

    if (valor <= 0 || valor > clientes[id - 1].saldo) {
        printf("Valor de saque invalido!\n");
        return;
    }

    clientes[id - 1].saldo -= valor;
    printf("Saque realizado com sucesso!\n");
}

void transferir() {
    int idOrigem, idDestino;
    float valor;
    printf("ID do cliente de origem: ");
    scanf("%d", &idOrigem);

    if (idOrigem < 1 || idOrigem > numClientes) {
        printf("ID de cliente de origem invalido!\n");
        return;
    }

    printf("ID do cliente de destino: ");
    scanf("%d", &idDestino);

    if (idDestino < 1 || idDestino > numClientes) {
        printf("ID de cliente de destino invalido!\n");
        return;
    }

    printf("Valor da transferencia: R$ ");
    scanf("%f", &valor);

    if (valor <= 0 || valor > clientes[idOrigem - 1].saldo) {
        printf("Valor de transferencia invalido!\n");
        return;
    }

    clientes[idOrigem - 1].saldo -= valor;
    clientes[idDestino - 1].saldo += valor;
    printf("Transferencia realizada com sucesso!\n");
}

void menu() {
    int opcao;
    do {
        printf("\n--- Menu Caixa Eletronico ---\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Consultar Saldo\n");
        printf("3. Depositar\n");
        printf("4. Sacar\n");
        printf("5. Transferir\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                consultarSaldo();
                break;
            case 3:
                depositar();
                break;
            case 4:
                sacar();
                break;
            case 5:
                transferir();
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
