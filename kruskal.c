// ALGORITMO KRUSKAL:
#include <stdio.h>
#include <stdbool.h>
// Exemplo: Trabalho Questão 01:
#define tapete 11 //numero de arestas
#define cachecol 8 //numero de vertices
int matrixArestas[3][tapete] ={   {2,3,3,4,4,7,7,7,8,8,8}, // pesos
                                    {6,0,0,0,5,4,4,5,2,2,3}, // vertice saida
                                    {7,1,3,2,6,6,7,7,4,5,5}};// vertice chegada
int visitados[cachecol];

// Exemplo: Eliminar Concorrência de Árvores:
//#define tapete 12 //numero de arestas
//#define cachecol 9 //numero de vertices
// int matrixArestas[3][tapete] = {{1,2,2,2,3,5,8,10,11,12,16,17}, // pesos
//                                         {3,0,6,5,0,4,4,0,2,2,5,5}, // vertice saida
//                                         {5,1,7,8,2,6,7,3,8,4,6,7}};// vertice chegada
//int visitados[cachecol] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};

bool verificaFinal(){
    int flag = 0;
    for(int a = 0; a < cachecol; a++)
        if(visitados[a] < 0) flag++;
    if(flag == 1) return true; // finalizar software
    return false;
}

int achaRaiz(int arvore){
    int raiz = arvore;
    while(true){
        raiz = arvore;
        arvore = visitados[arvore];
        if(arvore < 0)
            break;
    }
    return raiz;
}

void kruskal() {
    for(int w = 0; w < tapete; w++){
        if(verificaFinal()) break;
        int arvore = 0;
        int saida = matrixArestas[1][w];
        int chegada = matrixArestas[2][w];
        if(visitados[saida] == -1 && visitados[chegada] == -1){ // cria nova arvore
            visitados[chegada] --;
            visitados[saida] = matrixArestas[2][w];
            printf("(%d, %d) ", saida, chegada);
        } else if(visitados[saida] == -1 || visitados[chegada] == -1){
            if(visitados[chegada] == -1){
                if(visitados[saida] < 0) visitados[chegada] = saida;
                else visitados[chegada] = visitados[saida];
                arvore = visitados[saida];
                visitados[arvore] --;
            } else {
                if(visitados[chegada] < 0)visitados[saida] = chegada;
                else visitados[saida] = visitados[chegada];
                arvore = visitados[chegada];
                visitados[arvore] --;
            }
            printf("(%d, %d) ", saida, chegada);
        } else if(visitados[saida] >= 0 && visitados[chegada] >= 0){
            if(visitados[saida] != visitados[chegada]){
                int raiz1 = achaRaiz(visitados[saida]);
                int raiz2 = achaRaiz(visitados[chegada]);
                if(raiz1 != raiz2){
                    int arvore1 = visitados[visitados[saida]];
                    int arvore2 = visitados[visitados[chegada]];
                    if(arvore1 < arvore2){
                        visitados[visitados[saida]] += visitados[visitados[chegada]];
                        visitados[visitados[chegada]] = visitados[saida];
                    } else {
                        visitados[visitados[chegada]] += visitados[visitados[saida]];
                        visitados[visitados[saida]] = visitados[chegada];
                    }
                    printf("(%d, %d) ", saida, chegada);
                }
            }
        }
    }
}
int main(){
    for(int y = 0; y < cachecol; y++) visitados[y] = -1;
    printf("Arvore Geradora Mínima: ");
    kruskal();
    printf("\n\nvertices: ");
    for(int a = 0; a < cachecol; a++)
        printf("%3d  |", a);
    printf("\nvalor   : ");
    for(int a = 0; a < cachecol; a++)
        printf("%3d  |", visitados[a]);
    printf("\n");
    return 0;
}
