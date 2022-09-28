#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX 50

typedef struct Aluno {

    char nome[MAX], cpf[36];
    int id, dia, mes, ano, situacao;

} TAluno;

void cadastrar(TAluno estudantes[], int posicao) {

    int certo = 0, cpf_verifica;

    printf("\nEntre com o nome completo do aluno:\n");
    fgets(estudantes[posicao].nome, MAX-1, stdin);
    fgets(estudantes[posicao].nome, MAX-1, stdin);
    
    do {
        printf("\nEntre com seu CPF:\n");
        fgets(estudantes[posicao].cpf, MAX-1, stdin);
        cpf_verifica = strlen(estudantes[posicao].cpf);
        
        if (cpf_verifica != 12) {
            printf("CPF inválido!");
        } else {
            printf("\nCPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n", estudantes[posicao].cpf[0],estudantes[posicao].cpf[1],estudantes[posicao].cpf[2],
            estudantes[posicao].cpf[3],estudantes[posicao].cpf[4],estudantes[posicao].cpf[5],estudantes[posicao].cpf[6],
            estudantes[posicao].cpf[7],estudantes[posicao].cpf[8],estudantes[posicao].cpf[9],estudantes[posicao].cpf[10]);
            certo = 1;
        }
    } while (certo != 1);

    printf("\nEntre com a data de nascimento do aluno. ");

    do {
        printf("\nEntre com o dia:\n");
        scanf("%i", &estudantes[posicao].dia);

        if ((estudantes[posicao].dia < 0) || (estudantes[posicao].dia > 31)) {
            printf("\nDia inválido!");
        } else {
            certo = 1;
        }
    } while (certo != 1);

    certo = 0;

    do {
        printf("\nEntre com o mês:\n");
        scanf("%i", &estudantes[posicao].mes);

        if ((estudantes[posicao].mes > 12) || (estudantes[posicao].mes < 1)) {
            printf("\nMês inválido!");
        } else {
            certo = 1;
        }
    } while (certo != 1);

    certo = 0;

    do {
        printf("\nEntre com o ano:\n");
        scanf("%i", &estudantes[posicao].ano);

        if (estudantes[posicao].ano < 1) {
            printf("\nAno inválido!");
        } else {
            certo = 1;
        }
    } while (certo != 1);

    estudantes[posicao].id = posicao;
    estudantes[posicao].situacao = 1;

    printf("\nCadastro finalizado.");
    printf("\nNome: %s",estudantes[posicao].nome);
    printf("\nCPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n",estudantes[posicao].cpf[0],estudantes[posicao].cpf[1],estudantes[posicao].cpf[2],
    estudantes[posicao].cpf[3],estudantes[posicao].cpf[4],estudantes[posicao].cpf[5],estudantes[posicao].cpf[6],
    estudantes[posicao].cpf[7],estudantes[posicao].cpf[8],estudantes[posicao].cpf[9],estudantes[posicao].cpf[10]);
    printf("\nData de nascimento: %i/%i/%i",estudantes[posicao].dia,estudantes[posicao].mes,estudantes[posicao].ano);
    printf("\n\n");
}

int listar(TAluno estudantes[], int posicao) {

    int i;

    for(i = 1; i <= posicao; i++) {
        if ((estudantes[i].situacao) == 1) {
            printf("\nID: %i",estudantes[i].id);
            printf("\nNome: %s",estudantes[i].nome);
            printf("\nCPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n",estudantes[i].cpf[0],estudantes[i].cpf[1],estudantes[i].cpf[2],
            estudantes[i].cpf[3],estudantes[i].cpf[4],estudantes[i].cpf[5],estudantes[i].cpf[6],
            estudantes[i].cpf[7],estudantes[i].cpf[8],estudantes[i].cpf[9],estudantes[i].cpf[10]);
            printf("\nData de nascimento: %i/%i/%i",estudantes[i].dia,estudantes[i].mes,estudantes[i].ano);
        }
    }
}

void pesquisar(TAluno estudantes[],int posicao) {

    int i, existe = 0, certo = 0;
    char busca[MAX];

    do {
        printf("\nDigite o nome do estudante cujo cadastro deseja localizar: \n\n");
        fgets(busca, MAX-1, stdin);
        fgets(busca, MAX-1, stdin);
        for(i = 1; i <= posicao; i++) {
            if ((estudantes[i].situacao) == 1) {
                if (strcmp(busca,estudantes[i].nome) == 0) {
                    printf("\n\nID: %i\n\n",estudantes[i].id);
                    printf("\nNome: %s",estudantes[i].nome);
                    printf("\nCPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n",estudantes[i].cpf[0],estudantes[i].cpf[1],estudantes[i].cpf[2],
                    estudantes[i].cpf[3],estudantes[i].cpf[4],estudantes[i].cpf[5],estudantes[i].cpf[6],
                    estudantes[i].cpf[7],estudantes[i].cpf[8],estudantes[i].cpf[9],estudantes[i].cpf[10]);
                    printf("\nData de nascimento: %i/%i/%i",estudantes[i].dia,estudantes[i].mes,estudantes[i].ano);
                    existe = 1;
                }
            }
        }
        if (existe == 0) {
            printf("\nAluno não encontrado.");
        }
            
        printf("\nDeseja pesquisar novamente?");
        printf("\n1 - Não.    2 - Sim.\n");
        scanf("%i", &certo);

    } while (certo != 1);

}

void atualizar(TAluno estudantes[], int posicao) {

    int i, id, certo = 0, existe = 0;

    do {
        printf("\nInforme a ID do usuário que deseja alterar: \n");
        scanf("%i", &id);

        for(i = 0; i < posicao; i++) {
            if (id == estudantes[i].id) {
                existe = 1;
            }
        }

        if (existe == 1) {
            cadastrar(estudantes, id);
        }

        printf("\nDeseja alterar outro cadastro?");
        printf("\n1 - Não.    2 - Sim.\n");
        scanf("%i", &certo);
    }while(certo != 2);
}

void remover(TAluno estudantes[]) {

    int id;

    printf("\nEntre com a ID do aluno que deseja remover: \n\n");
    scanf("%i", &id);

    estudantes[id].situacao = 0;

    printf("\nAluno removido!");
}

int main() {

    setlocale(LC_ALL, "Portuguese");
    TAluno estudantes[MAX];
    int opcao, ponteiro = 1;

    printf("\n\n##### Cadastro de pessoas. #####\n\n");
    do {
        printf("\n[1] - Cadastrar.");
        printf("\n[2] - Listar.");
        printf("\n[3] - Pesquisar.");
        printf("\n[4] - Atualizar.");
        printf("\n[5] - Remover.");
        printf("\n[0] - Sair.\n");
        scanf("%i", &opcao);

        switch(opcao) {

            case 1:
                if (ponteiro > 50) {
                    printf("\nLimite de cadastros atingidos! Não é mais possível cadastrar.");
                } else {
                    cadastrar(estudantes, ponteiro);
                    ponteiro++;
                }
                break;

            case 2:
                listar(estudantes, ponteiro);
                break;

            case 3:
                pesquisar(estudantes, ponteiro);
                break;

            case 4:
                atualizar(estudantes, ponteiro);
                break;

            case 5:
                remover(estudantes);
                break;

            case 0:
                printf("\nCadastro finalizado!\n");
                break;

            default:
                printf("\nOpção inválida!");

        }
    } while (opcao != 0);
    
    return 0;
}