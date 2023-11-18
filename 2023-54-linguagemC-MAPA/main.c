#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void solicitarAtend(){
    char nome[50];
    int cpf;

    printf("Iremos dar prosseguimento ao seu atendimento. Mas antes, preciso que você digite o seu nome:\n");
    scanf("%s", &nome);
    printf("\n");
    printf("Certo %s. Agora preciso do seu CPF:\n", nome);
    scanf("%d", &cpf);
    printf("\n");
}

int main(){

    setlocale(LC_ALL, "");

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
        break;
    }
}