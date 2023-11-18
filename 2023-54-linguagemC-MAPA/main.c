#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void solicitarAtend(){
    char nome[50];
    int cpf;
    int escolha;

    printf("Iremos dar prosseguimento ao seu atendimento. Mas antes, preciso que voc� digite o seu nome:\n");
    scanf("%s", &nome);
    printf("\n");
    printf("Certo %s. Agora preciso do seu CPF:\n", nome);
    scanf("%d", &cpf);
    printf("\n");
    printf("Agora preciso que voc� escolha uma das op��es abaixo para darmos proseguimento a sua solicita��o:\n 1 - Abertura de Conta\n 2 - Caixa\n 3 - Gerente Pessoa F�sica\n 4 - Gerente Pessoa Jur�dica\n");
    printf("\n");
    scanf("%d", &escolha);

    switch (escolha){
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    case 4:
        return 4;
        break;
    default:
        printf("Oops! Creio que tenha digitado algo errado.\n");
        break;
    }
}

int main(){

    setlocale (LC_ALL, "portuguese");

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
        printf("Desculpe! Acho que voc� digitou algo errado.\n");
        break;
    }
}