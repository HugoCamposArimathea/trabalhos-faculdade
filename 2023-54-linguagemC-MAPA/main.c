#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Struct para registro dos atendimentos 
struct registroAtend {
    char nome_cliente[50];
    char sobrenome_cliente[50];
    char atendEscolhido[50];
    long long int cpf_cliente;
    int atend_cliente; 
};

struct registroAtend Vet[10];

//Sub-rotina para o menu principal, decidi colocar assim para poder chama-lo quando precisar
void menuPrincipal(){

    int escolha;

    printf("\n\n");
    printf("Bem vindo ao sistema de atendimento!\n");
    printf(" 1 - Solicitar Atendimento\n 2 - Listar Atendimentos Registrados\n 3 - Listar Atendimento por setor\n 4 - Sair");
    printf("\n");
    scanf("%d", &escolha);

    switch (escolha){
    case 1:
        solicitarAtend();
        break;
    case 2:
        solicitarAtendRegist();
        break;
    case 3:
        listagemAtend();
        break;
    case 4:
        exit("int status");
        break;
    default:
        printf("Desculpe! Acho que voce digitou algo errado.\n");
        menuPrincipal();
        break;
    }
}

//Sub-rotina para a escolha um do menu principal - Solicitar Atendimento
int j = -1;
void solicitarAtend(){
    int escolha2;
    int confirmacao = 1;

    while (confirmacao == 1){

        j++;
        printf("Iremos dar prosseguimento ao seu atendimento. Mas antes, preciso que voce digite o seu nome:\n");
        fflush(stdin);
        scanf("%s", &Vet[j].nome_cliente);
        printf("\n");
        printf("Agora o seu sobrenome:\n");
        fflush(stdin);
        scanf("%s", &Vet[j].sobrenome_cliente);
        printf("\n");
        printf("Certo. Agora preciso do seu CPF:\n");
        fflush(stdin);
        scanf("%llu", &Vet[j].cpf_cliente);
        printf("\n");
        printf("Agora preciso que voce escolha uma das opcoes abaixo para darmos proseguimento a sua solicitacao:\n 1 - Abertura de Conta\n 2 - Caixa\n 3 - Gerente Pessoa Fisica\n 4 - Gerente Pessoa Juridica\n 5 - Voltar ao menu principal\n");
        fflush(stdin);
        printf("\n");
        scanf("%d", &escolha2);
        Vet[j].atend_cliente = escolha2;

        switch (escolha2){
        case 1:
            printf("Você escolheu opcao 1: Abertura de Conta. Muito obrigado! \n");
            menuPrincipal();
            break;
        case 2:
            printf("Você escolheu opcao 2: Caixa. Muito obrigado! \n");
            menuPrincipal();
            break;
        case 3:
            printf("Você escolheu opcao 3: Gerente de Pessoa Fisica. Muito obrigado! \n");
            menuPrincipal();
            break;
        case 4:
            printf("Você escolheu opcao 4: Gerente Pessoa Juridica. Muito obrigado! \n");
            menuPrincipal();
            break;
        case 5:
            menuPrincipal();
        default:
            printf("Oops! Creio que tenha digitado algo errado.\n");
            printf("\n");
            printf("Voce deseja voltar ao menu para mais algum atendimento? (1-Sim/2-Nao)\n");
            scanf("%d", &confirmacao);
            break;
        }
    }
    menuPrincipal();
}

//Sub-rotina para os registros de atendimento
void solicitarAtendRegist() {

    printf("\n");
    printf("-------------------------------------\n");
    printf("Listagem dos atendimentos realizados:\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < 10; i++)
    {
        if(Vet[i].cpf_cliente>0){
            printf("\n");
            printf("-------------------------------------\n");
            printf("Nome: %s", Vet[i].nome_cliente);
            printf(" %s\n", Vet[i].sobrenome_cliente);
            printf("CPF: %llu\n", Vet[i].cpf_cliente);
            if(Vet[i].atend_cliente == 1){
                printf("Tipo de Atendimento: 1 - Abertura de Conta\n");
            }else if(Vet[i].atend_cliente == 2){
                printf("Tipo de Atendimento: 2 - Caixa\n");
            }else if(Vet[i].atend_cliente == 3){
                printf("Tipo de Atendimento: 3 - Gerente de Pessoa Fisica\n");
            }else if(Vet[i].atend_cliente == 4){
                printf("Tipo de Atendimento: 4 - Gerente de Pessoa Juridica\n");
            }else if(Vet[i].atend_cliente == 5){
                printf("Tipo de Atendimento: 5 - Voltar ao Menu Principal\n");
            }
        } 
    }
    menuPrincipal();
}

//Sub-Rotina para filtragem de busca dos atendimentos realizados
void listagemAtend() {
    int termBusca;

    printf("\n");
    printf("Digite o nnumero do atendimento realizado que voce deseja filtra:\n");
    scanf("%d", &termBusca);
    for(int i=0;i<10;i++){
        if(Vet[i].atend_cliente == termBusca){
            if(Vet[i].atend_cliente == 1){
                printf("Tipo de Atendimento: 1 - Abertura de Conta\n");
            }else if(Vet[i].atend_cliente == 2){
                printf("Tipo de Atendimento: 2 - Caixa\n");
            }else if(Vet[i].atend_cliente == 3){
                printf("Tipo de Atendimento: 3 - Gerente de Pessoa Fisica\n");
            }else if(Vet[i].atend_cliente == 4){
                printf("Tipo de Atendimento: 4 - Gerente de Pessoa Juridica\n");
            }else if(Vet[i].atend_cliente == 5){
                printf("Tipo de Atendimento: 5 - Voltar ao Menu Principal\n");
            }
        }
    }
    menuPrincipal();
}

int main(){

    setlocale (LC_ALL, "Portuguese");
    menuPrincipal();
}