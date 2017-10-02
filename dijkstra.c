// ALGORITMO DIJKSTRA:
#include <stdio.h>
#include <stdbool.h>
#define chinelo 7 //numero de vertices
#define vInicial 0
int visitados[chinelo];
// matriz de Adjacencia
int matrix[chinelo][chinelo] = {
                                {0,7,0,5,0,0,0},
                                {7,0,8,9,7,0,0},
                                {0,8,0,0,5,0,0},
                                {5,9,0,0,15,6,0},
                                {0,7,5,15,0,8,9},
                                {0,0,0,6,8,0,11},
                                {0,0,0,0,9,11,0}};
int result[chinelo][2];
// Linha 1: vertice anterior.
// Linha 2: total.

void dijstraAdjacencia(int v) {
    int a = 0, aux, auxTotal;
    // printf("Adjacencia: %d --> ", v+1);
    do{
        aux = 1234567;
        visitados[v] = 1;
        for(a = 0; a < chinelo; a++){ // fazendo o somatorio na tabela
            auxTotal = result[a][1] + matrix[v][a] + result[v][1];
            if(matrix[v][a] != 0 && visitados[a] != 1 && (result[a][1] == 0 || auxTotal < result[a][1])){
                printf("entrou!! valor ant: %d, novo: %d, no vertice: %d\n", result[a][1], auxTotal, v);
                result[a][0] = v;
                result[a][1] = auxTotal;
            }
        }
        minhaTable();
        for(a = 0; a < chinelo; a++){ // buscando o vertice com o menor total e não visitado ainda
            if(visitados[a] != 1){
                if(result[a][1] < aux && result[a][1] > 0){
                    v = a;
                    aux = result[a][1];
                }
            }
        }
        printf("proximo vertice: %d, valor: %d \n", v, result[v][1]);
        if(visitados[v] == 1) return;
    }while(true);
}
void minhaTable(){
    int g;
    printf("Vertices anteriores: ");
    for(g = 0; g < chinelo; g++)
        printf("%d  |  ", result[g][0]);
    printf("\nTotal              : ");
    for(g = 0; g < chinelo; g++)
        printf("%d  |  ", result[g][1]);
    printf("\n\n -------------------- \n\n");
    return;
}
int main(){
    int g;
    for(g = 0; g < chinelo; g++)
        result[g][1] = result[g][0] = visitados[g] = 0;
    dijstraAdjacencia(vInicial);
    return 0;
}
