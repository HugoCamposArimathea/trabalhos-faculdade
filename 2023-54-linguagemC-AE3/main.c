#include <stdio.h>
#include <stdlib.h>

void validarMeta(int dia1[3][3], int dia2[3][3]){
    int meta;
    int matrizTotal[3][3];
    int i, j = 0;

    //Leitura da meta por setor para verificação
    printf("Digite qual e a meta por setor \n");
    scanf("%d", &meta);

    printf("\n");

    //Soma das duas matrizes
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            matrizTotal[i][j] = dia1[i][j] + dia2[i][j];
        }
    }
    
    //Escrita da matriz total na tela
    printf("A matriz total e: \n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ", matrizTotal[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    //Verificação de quais setores bateram a meta
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(matrizTotal[i][j] >= meta){
                printf("O setor %d de %d alcancou a meta!\n", (i+1), (j+1));
            } else if(matrizTotal[i][j] < meta) {
                printf("O setor %d de %d nao alcancou a meta!\n", (i+1), (j+1));
            }
        }
    }
}

int main() {
    int dia1[3][3];
    int dia2[3][3];
    int i, j = 0;

    //Leitura da matriz no primeiro dia
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Digite o total de pessoas do setor %d de %d no dia 1\n", (i+1), (j+1));
            scanf("%d", &dia1[i][j]);
        }
    }

    printf("\n");

    //Leitura da matriz no segundo dia
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Digite o total de pessoas no setor %d de %d no dia 2\n", (i+1), (j+1));
            scanf("%d", &dia2[i][j]);
        }
    }

    printf("\n");

    validarMeta(dia1, dia2);
}