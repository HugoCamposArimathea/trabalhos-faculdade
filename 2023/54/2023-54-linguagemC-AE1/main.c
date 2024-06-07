#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{

    setlocale(LC_ALL, "");

    float valorInvestido = 0;
    float percentualRendimento = 0;
    float resultado;
    float montante;
    int periodo = 0;
    int qualMes = 1;

    printf("Digite o valor investido\n");
    scanf("%f", &valorInvestido);
    printf("Digite a quantidade de meses do investimento\n");
    scanf("%d", &periodo);
    printf("Digite o percentual de rendimento ao mes\n");
    scanf("%f", &percentualRendimento);

    montante = valorInvestido; 

    for (int i = 0; i < periodo; i++)
    {
        float taxa = percentualRendimento/100;
        resultado = valorInvestido*(1+taxa);
        valorInvestido = resultado;
        printf("O rendimento no mes %d foi: R$%.2f\n", qualMes, resultado);
        qualMes = qualMes + 1;
    }

    printf("\n");
    printf("O rendimento do seu investimento antes dos impostos ficou em: R$%.2f\n", resultado);
    printf("\n");
    printf("E necesario pagar 15 de imposto sobre o rendimento do seu investimento. Dessa forma, o resultado final do seu investimento ficou assim:");
    printf("\n\n");

    float rendimento = valorInvestido-montante;
    float imposto = rendimento*0.15;
    float resultadoFinal = valorInvestido-imposto;
    printf("R$%.2f\n", resultadoFinal);

}