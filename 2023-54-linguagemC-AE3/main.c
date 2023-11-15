#include <stdio.h>
#include <stdlib.h>

void validarMeta(int dia1[3][3], int dia2[3][3]){
    int meta;
    int matrizTotal[3][3];
    int i, j = 0;

    //Leitura da meta por setor para verificação
    printf("Digite qual é a meta por setor");
    scanf("%d", &meta);

    //Soma das duas matrizes
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            matrizTotal[i][j] = dia1[i][j] + dia2[i][j];
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
            printf("Digite o total de pessoas do setor %d de %d\n", (i+1), (j+1));
            scanf("%d", &dia1[i][j]);
        }
    }

    printf("\n");

    //Leitura da matriz no segundo dia
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("Digite o total de pessoas no setor %d de %d\n", (i+1), (j+1));
        }
    }

    validarMeta(dia1, dia2);
}