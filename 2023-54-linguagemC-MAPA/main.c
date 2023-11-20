#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Struct para registro dos atendimentos 
struct registroAtend {
    char nome_cliente[50];
    int cpf_cliente[12];
    char atend_cliente[50];
};

struct registroAtend Vet[10];

//Sub-rotina para o menu principal, decidi colocar assim para poder chama-lo quando precisar
void menuPrincipal(){

    int escolha;

    printf("Bem vindo ao sistema de atendimento!\n");
    printf(" 1 - Solicitar Atendimento\n 2 - Listar Atendimentos Registrados\n 3 - Listar Atendimento por setor\n 4 - Sair");
    printf("\n");
    scanf("%d", &escolha);

    switch (escolha){
    case 1:
        solicitarAtend();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        printf("Desculpe! Acho que você digitou algo errado.\n");
        menuPrincipal();
        break;
    }
}

void solicitarAtend(){
    int escolha2;
    int confirmacao = 1;
    int i = 0;

    while (confirmacao == 1){

        printf("Iremos dar prosseguimento ao seu atendimento. Mas antes, preciso que você digite o seu nome:\n");
        gets(Vet[i].nome_cliente);
        printf("\n");
        printf("Certo. Agora preciso do seu CPF:\n");
        scanf(Vet[i].cpf_cliente);
        printf("\n");
        printf("Agora preciso que você escolha uma das opções abaixo para darmos proseguimento a sua solicitação:\n 1 - Abertura de Conta\n 2 - Caixa\n 3 - Gerente Pessoa Física\n 4 - Gerente Pessoa Jurídica\n 5 - Voltar ao menu principal\n");
        printf("\n");
        scanf("%d", &escolha2, &Vet[i].atend_cliente);

        i++;

        switch (escolha2){
        case 1:
            printf("Você deseja voltar ao menu para mais algum atendimento? (1-Sim/2-Não)\n");
            scanf("%d", &confirmacao);
            break;
        case 2:
            printf("Você deseja voltar ao menu para mais algum atendimento? (1-Sim/2-Não)\n");
            scanf("%d", &confirmacao);
            break;
        case 3:
            printf("Você deseja voltar ao menu para mais algum atendimento? (1-Sim/2-Não)\n");
            scanf("%d", &confirmacao);
            break;
        case 4:
            printf("Você deseja voltar ao menu para mais algum atendimento? (1-Sim/2-Não)\n");
            scanf("%d", &confirmacao);
            break;
        case 5:
            menuPrincipal();
        default:
            printf("Oops! Creio que tenha digitado algo errado.\n");
            printf("\n");
            printf("Você deseja voltar ao menu para mais algum atendimento? (1-Sim/2-Não)\n");
            scanf("%d", &confirmacao);
            break;
        }
    }
    menuPrincipal();
}

int main(){

    setlocale (LC_ALL, "portuguese");
    menuPrincipal();
}