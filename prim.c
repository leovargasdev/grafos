// ALGORITMO PRIM:
#include <stdio.h>
#include <stdbool.h>
#define espelho 8 //numero de vertices
#define vInicial 0
int result[espelho][2]; // result[][0] = custo, esult[][1] = v. anterior
int visitados[espelho];
int matrix[espelho][espelho] = {
                                {0,2,0,6,5,0,0,0},
                                {2,0,7,7,0,0,0,0},
                                {0,7,0,0,6,2,0,0},
                                {6,7,0,0,0,0,0,0},
                                {5,0,6,0,0,0,4,5},
                                {0,0,2,0,0,0,4,6},
                                {0,0,0,0,4,4,0,1},
                                {0,0,0,0,5,6,1,0}};
void prim(int v) {
    result[v][1] = result[v][0] = 0;
    do{
        int aux = 12345;
        visitados[v] = 1;
        for(int u = 0; u < espelho; u++){
            if(matrix[v][u] < result[u][0] && matrix[v][u] && visitados[u] != 1){
                result[u][0] = matrix[v][u];
                result[u][1] = v;
            }
        }
        for(int a = 0; a < espelho; a++) // buscando o vertice com o menor total e não visitado ainda
            if(visitados[a] != 1)
                if(result[a][0] < aux){
                    v = a;
                    aux = result[a][0];
                }
        if(visitados[v] == 1) return;
    }while(true);
}
int main(){
    for(int g = 0; g < espelho; g++){
        result[g][0] = 12345;
        visitados[g] = result[g][1] = -1;
    }
    prim(vInicial);
    printf("Caminho: ");
    for(int a = 0; a < espelho; a++){
        printf("(%d, %d), ", a, result[a][1]);
    }
    printf("\n\nTABELA:\nvertices   : ");
    for(int a = 0; a < espelho; a++)
        printf("%3d  |", a);
    printf("\ndistancia  : ");
    for(int a = 0; a < espelho; a++)
        printf("%3d  |", result[a][0]);
    printf("\nv. anterior: ");
    for(int a = 0; a < espelho; a++)
        printf("%3d  |", result[a][1]);
    printf("\n\n");
    return 0;
}
