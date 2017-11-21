// ALGORITMO PRIM:
#include <stdio.h>
#include <stdbool.h>
#define AZUL 1
#define CINZA 2
#define VERDE 3
#define pneu 11 //numero de vertices
int graus[pneu]; // result[][0] = custo, esult[][1] = v. anterior
int cor[pneu];
int matrix[pneu][pneu] = {
                                {0,1,0,0,0,0,0,1,0,0,0},
                                {1,0,0,1,0,0,0,0,0,0,0},
                                {0,0,0,1,0,0,0,0,0,0,0},
                                {0,1,1,0,0,0,0,0,1,0,1},
                                {0,0,0,0,0,1,0,0,0,0,1},
                                {0,0,0,0,1,0,1,0,0,0,0},
                                {0,0,0,0,0,1,0,1,0,0,1},
                                {1,0,0,0,0,0,1,0,1,1,1},
                                {0,0,0,1,0,0,0,1,0,1,0},
                                {0,0,0,0,0,0,0,1,1,0,1},
                                {0,0,0,1,1,0,1,1,0,1,0}};
void achaGraus(){
    for(int a = 0; a < pneu; a++)
        for(int k = 0; k < pneu; k++)
            if(matrix[a][k] == 1)
                graus[a]++;
}
void welshPowell(){
    int v, aux;
    do{
        aux = 0;
        for(int a = 0; a < pneu; a++) // buscando o vertice com o menor total e não visitado ainda
            if(cor[a] == 0)
                if(graus[a] > aux){
                    v = a;
                    aux = graus[a];
                }
        if(cor[v] == 0){
            for(int t = 0; t < pneu; t++)
                matrix[v][t]
        }

    }while(true);
}
int main(){
    for(int g = 0; g < pneu; g++)
        cor[g] = graus[g] = 0;
    achaGraus();
    printf("graus: \n");
    for(int a = 0; a < pneu; a++){
        printf("(%d, %d)\n", a+1, graus[a]);
    }
    // welshPowell();









    // printf("Caminho: ");
    // for(int a = 0; a < espelho; a++){
    //     printf("(%d, %d), ", a, result[a][1]);
    // }
    // printf("\n\nTABELA:\nvertices   : ");
    // for(int a = 0; a < espelho; a++)
    //     printf("%3d  |", a);
    // printf("\ndistancia  : ");
    // for(int a = 0; a < espelho; a++)
    //     printf("%3d  |", result[a][0]);
    // printf("\nv. anterior: ");
    // for(int a = 0; a < espelho; a++)
    //     printf("%3d  |", result[a][1]);
    // printf("\n\n");
    return 0;
}
