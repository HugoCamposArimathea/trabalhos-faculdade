#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

//Struct para registro dos atendimentos 
struct registroAtend {
    char nome_cliente[50];
    char sobrenome_cliente[50];
    char atendEscolhido[50];
    char cpf_cliente[15];
    int atend_cliente; 
};

struct registroAtend Vet[10];

//Sub-rotina para o menu principal, decidi colocar assim para poder chama-lo quando precisar
int menuPrincipal(){

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
        printf("Desculpe! Acho que você digitou algo errado.\n");
        menuPrincipal();
        break;
    }
}

//Sub-rotina para a escolha um do menu principal - Solicitar Atendimento, usarei como variável de controle aqui dentro o j, pois assim não interfere em outras sub-rotinas
int j = -1;
int solicitarAtend(){
    int escolha2;
    int confirmacao = 1;

    while (confirmacao == 1){

        j++;
        printf("\n");
        printf("Iremos dar prosseguimento ao seu atendimento. Mas antes, preciso que você digite o seu nome:\n");
        fflush(stdin);
        scanf("%s", Vet[j].nome_cliente);
        printf("\n");
        printf("Agora o seu sobrenome:\n");
        fflush(stdin);
        scanf("%s", Vet[j].sobrenome_cliente);
        printf("\n");
        printf("Certo. Agora preciso do seu CPF:\n");
        fflush(stdin);
        scanf("%s", Vet[j].cpf_cliente);
        //Verificação de quantidade de números do CPF
        if(strlen(Vet[j].cpf_cliente)!=11){
            printf("\n");
            printf("Desculpe, mas creio que tenha digitado números a mais ou números a menos. Por favor verifique!\n");
            printf("Digite seu CPF novamente:\n");
            fflush(stdin);
            scanf("%s", Vet[j].cpf_cliente);
        }
        printf("\n");
        printf("Agora preciso que você escolha uma das opcoes abaixo para darmos proseguimento a sua solicitação:\n 1 - Abertura de Conta\n 2 - Caixa\n 3 - Gerente Pessoa Física\n 4 - Gerente Pessoa Jurídica\n 5 - Voltar ao menu principal\n");
        fflush(stdin);
        printf("\n");
        scanf("%d", &escolha2);
        Vet[j].atend_cliente = escolha2;
        
        //Formata nome do cliente para que sempre fique com a primeira letra maiúscula
        for(int i=0; i<strlen(Vet[j].nome_cliente)+1;i++){
            if (i == 0 || Vet[j].nome_cliente[i - 1] == ' ') {
                Vet[j].nome_cliente[i] = toupper(Vet[j].nome_cliente[i]);
            } else {
                Vet[j].nome_cliente[i] = Vet[j].nome_cliente[i];
            }
        }
         
        //Formata sobrenome do cliente para que sempre fique com a primeira letra maiúscula
        for(int i=0; i<strlen(Vet[j].sobrenome_cliente)+1;i++){
            if (i == 0 || Vet[j].sobrenome_cliente[i - 1] == ' ') {
                Vet[j].sobrenome_cliente[i] = toupper(Vet[j].sobrenome_cliente[i]);
            } else {
                Vet[j].sobrenome_cliente[i] = Vet[j].sobrenome_cliente[i];
            }
        }

        switch(escolha2){
        case 1:
            printf("Você escolheu opção 1: Abertura de Conta. Muito obrigado! \n");
            menuPrincipal();
            break;
        case 2:
            printf("Você escolheu opção 2: Caixa. Muito obrigado! \n");
            menuPrincipal();
            break;
        case 3:
            printf("Você escolheu opção 3: Gerente de Pessoa Física. Muito obrigado! \n");
            menuPrincipal();
            break;
        case 4:
            printf("Você escolheu opção 4: Gerente Pessoa Jurídica. Muito obrigado! \n");
            menuPrincipal();
            break;
        case 5:
            menuPrincipal();
        default:
            printf("Oops! Creio que tenha digitado algo errado.\n");
            printf("\n");
            printf("Você deseja voltar ao menu para mais algum atendimento? (1-Sim/2-Nao)\n");
            scanf("%d", &confirmacao);
            break;
        }
    }
    menuPrincipal();
}

//Sub-rotina para listagem dos registros de atendimento
int solicitarAtendRegist() {

    printf("\n");
    printf("-------------------------------------\n");
    printf("Listagem dos atendimentos realizados:\n");
    printf("-------------------------------------\n");

    for (int i = 0; i < 10; i++)
    {
        if(Vet[i].atend_cliente>0){
            printf("\n");
            printf("-------------------------------------\n");
            printf("-------------------------------------\n");
            printf("Nome: %s", Vet[i].nome_cliente);
            printf(" %s\n", Vet[i].sobrenome_cliente);
            printf("CPF: %.3s.%.3s.%.3s-%.2s\n", Vet[i].cpf_cliente, Vet[i].cpf_cliente + 3, Vet[i].cpf_cliente + 6, Vet[i].cpf_cliente + 9);
            if(Vet[i].atend_cliente == 1){
                printf("Tipo de Atendimento: 1 - Abertura de Conta\n");
            }else if(Vet[i].atend_cliente == 2){
                printf("Tipo de Atendimento: 2 - Caixa\n");
            }else if(Vet[i].atend_cliente == 3){
                printf("Tipo de Atendimento: 3 - Gerente de Pessoa Física\n");
            }else if(Vet[i].atend_cliente == 4){
                printf("Tipo de Atendimento: 4 - Gerente de Pessoa Jurídica\n");
            }
        } 
    }
    menuPrincipal();
}

//Sub-Rotina para filtragem de busca dos atendimentos realizados
int listagemAtend() {
    int termBusca;

    printf("\n");
    printf("Digite o número do atendimento realizado que você deseja filtrar:\n");
    scanf("%d", &termBusca);
    for(int i=0;i<10;i++){
        if(Vet[i].atend_cliente == termBusca){
            printf("\n");
            printf("-------------------------------------\n");
            printf("Nome: %s", Vet[i].nome_cliente);
            printf(" %s\n", Vet[i].sobrenome_cliente);
            printf("CPF: %.3s.%.3s.%.3s-%.2s\n", Vet[i].cpf_cliente, Vet[i].cpf_cliente + 3, Vet[i].cpf_cliente + 6, Vet[i].cpf_cliente + 9);
            if(termBusca==1){
                printf("Tipo de Atendimento: 1 - Abertura de Conta\n");
            }else if(termBusca==2){
                printf("Tipo de Atendimento: 2 - Caixa\n");
            }else if(termBusca==3){
                printf("Tipo de Atendimento: 3 - Gerente Pessoa Física\n");
            }else if(termBusca==4){
                printf("Tipo de Atendimento: 4 - Gerente Pessoa Jurídica\n");
            }
        }
    }
    menuPrincipal();
}

int main(){

    setlocale (LC_ALL, "Portuguese");
    menuPrincipal();
}