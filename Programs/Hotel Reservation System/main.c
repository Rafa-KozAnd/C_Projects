#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOSPEDES 100
#define MAX_QUARTOS 50
#define MAX_RESERVAS 200

typedef struct {
    int id;
    char nome[50];
} Hospede;

typedef struct {
    int numero;
    char tipo[30];
    int disponivel;
} Quarto;

typedef struct {
    int idReserva;
    int idHospede;
    int numeroQuarto;
    char dataEntrada[11];
    char dataSaida[11];
} Reserva;

Hospede hospedes[MAX_HOSPEDES];
int numHospedes = 0;
Quarto quartos[MAX_QUARTOS];
int numQuartos = 0;
Reserva reservas[MAX_RESERVAS];
int numReservas = 0;

void cadastrarHospede() {
    if (numHospedes >= MAX_HOSPEDES) {
        printf("Limite de hospedes atingido!\n");
        return;
    }
    
    Hospede h;
    h.id = numHospedes + 1;
    printf("Nome do hospede: ");
    scanf(" %[^\n]", h.nome);
    
    hospedes[numHospedes++] = h;
    printf("Hospede cadastrado com sucesso!\n");
}

void cadastrarQuarto() {
    if (numQuartos >= MAX_QUARTOS) {
        printf("Limite de quartos atingido!\n");
        return;
    }
    
    Quarto q;
    q.numero = numQuartos + 1;
    printf("Tipo do quarto: ");
    scanf(" %[^\n]", q.tipo);
    q.disponivel = 1;
    
    quartos[numQuartos++] = q;
    printf("Quarto cadastrado com sucesso!\n");
}

void realizarReserva() {
    if (numReservas >= MAX_RESERVAS) {
        printf("Limite de reservas atingido!\n");
        return;
    }
    
    Reserva r;
    r.idReserva = numReservas + 1;
    
    printf("ID do hospede: ");
    scanf("%d", &r.idHospede);
    if (r.idHospede < 1 || r.idHospede > numHospedes) {
        printf("ID de hospede invalido!\n");
        return;
    }
    
    printf("Numero do quarto: ");
    scanf("%d", &r.numeroQuarto);
    if (r.numeroQuarto < 1 || r.numeroQuarto > numQuartos || !quartos[r.numeroQuarto - 1].disponivel) {
        printf("Numero de quarto invalido ou indisponivel!\n");
        return;
    }
    
    printf("Data de entrada (dd/mm/yyyy): ");
    scanf("%s", r.dataEntrada);
    printf("Data de saida (dd/mm/yyyy): ");
    scanf("%s", r.dataSaida);
    
    quartos[r.numeroQuarto - 1].disponivel = 0;
    reservas[numReservas++] = r;
    printf("Reserva realizada com sucesso!\n");
}

void exibirReservas() {
    for (int i = 0; i < numReservas; i++) {
        Reserva r = reservas[i];
        Hospede h = hospedes[r.idHospede - 1];
        Quarto q = quartos[r.numeroQuarto - 1];
        
        printf("Reserva %d\n", r.idReserva);
        printf("Hospede: %s\n", h.nome);
        printf("Quarto: %d (%s)\n", q.numero, q.tipo);
        printf("Data de entrada: %s\n", r.dataEntrada);
        printf("Data de saida: %s\n", r.dataSaida);
        printf("\n");
    }
}

void menu() {
    int opcao;
    do {
        printf("1. Cadastrar Hospede\n");
        printf("2. Cadastrar Quarto\n");
        printf("3. Realizar Reserva\n");
        printf("4. Exibir Reservas\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarHospede();
                break;
            case 2:
                cadastrarQuarto();
                break;
            case 3:
                realizarReserva();
                break;
            case 4:
                exibirReservas();
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
