// ALGORITMO DIJKSTRA:
#include <stdio.h>
#include <stdbool.h>
#define chinelo 3 //numero de blas

// Exemplo: Trabalho Questão 01:
#define chinelo2 11 //numero de arestas
#define chinelo3 8 //numero de vertices
int matrixArestas[chinelo][chinelo2] = {{2,3,3,4,4,7,7,7,8,8,8}, // pesos
                                        {6,0,0,0,5,4,4,5,2,2,3}, // vertice saida
                                        {7,1,3,2,6,6,7,7,4,5,5}};// vertice chegada
int matrixVisitados[chinelo3] = {-1,-1,-1,-1,-1,-1,-1,-1};

// Exemplo: Eliminar Concorrência de Árvores:
//#define chinelo2 12 //numero de arestas
//#define chinelo3 9 //numero de vertices
// int matrixArestas[chinelo][chinelo2] = {{1,2,2,2,3,5,8,10,11,12,16,17}, // pesos
//                                         {3,0,6,5,0,4,4,0,2,2,5,5}, // vertice saida
//                                         {5,1,7,8,2,6,7,3,8,4,6,7}};// vertice chegada
//int matrixVisitados[chinelo3] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};

bool verificaFinal(){
    int flag = 0;
    for(int a = 0; a < chinelo3; a++){
        if(matrixVisitados[a] < 0) flag++;
    }
    if(flag == 1) return true; // finalizar sotfware
    return false;
}
int achaRaiz(int arvore){
    int raiz = arvore;
    while(true){
        raiz = arvore;
        arvore = matrixVisitados[arvore];
        if(arvore < 0){
            break;
        }
    }
    return raiz;
}
void kruskal() {
    for(int w = 0; w < chinelo2; w++){
        if(verificaFinal()) break;
        int arvore = 0;
        int saida = matrixArestas[1][w];
        int chegada = matrixArestas[2][w];
        if(matrixVisitados[saida] == -1 && matrixVisitados[chegada] == -1){ // cria nova arvore
            matrixVisitados[chegada] --;
            matrixVisitados[saida] = matrixArestas[2][w];
            printf("(%d, %d) ", saida, chegada);
        } else if(matrixVisitados[saida] == -1 || matrixVisitados[chegada] == -1){
            if(matrixVisitados[chegada] == -1){
                if(matrixVisitados[saida] < 0) matrixVisitados[chegada] = saida;
                else matrixVisitados[chegada] = matrixVisitados[saida];
                arvore = matrixVisitados[saida];
                matrixVisitados[arvore] --;
            } else {
                if(matrixVisitados[chegada] < 0)matrixVisitados[saida] = chegada;
                else matrixVisitados[saida] = matrixVisitados[chegada];
                arvore = matrixVisitados[chegada];
                matrixVisitados[arvore] --;
            }
            printf("(%d, %d) ", saida, chegada);
        } else if(matrixVisitados[saida] >= 0 && matrixVisitados[chegada] >= 0){
            if(matrixVisitados[saida] != matrixVisitados[chegada]){
                int raiz1 = achaRaiz(matrixVisitados[saida]);
                int raiz2 = achaRaiz(matrixVisitados[chegada]);
                if(raiz1 != raiz2){
                    int arvore1 = matrixVisitados[matrixVisitados[saida]];
                    int arvore2 = matrixVisitados[matrixVisitados[chegada]];
                    if(arvore1 < arvore2){
                        matrixVisitados[matrixVisitados[saida]] += matrixVisitados[matrixVisitados[chegada]];
                        matrixVisitados[matrixVisitados[chegada]] = matrixVisitados[saida];
                    } else {
                        matrixVisitados[matrixVisitados[chegada]] += matrixVisitados[matrixVisitados[saida]];
                        matrixVisitados[matrixVisitados[saida]] = matrixVisitados[chegada];
                    }
                    printf("(%d, %d) ", saida, chegada);
                }
            }
        }
    }
}
int main(){
    printf("Arvore Geradora Mínima: ");
    kruskal();
    printf("\n\nvertices: ");
    for(int a = 0; a < chinelo3; a++)
        printf("%3d  |", a);
    printf("\nvalor   : ");
    for(int a = 0; a < chinelo3; a++)
        printf("%3d  |", matrixVisitados[a]);
    printf("\n");
    return 0;
}
