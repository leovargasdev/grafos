// Data: 13/09/2017
// ALGORITMO GULOSO: Dado um vertice inicial este algoritmo tenta percorre o maior número de vertices
//                      que conseguir, pegando sempre a menor aresta que vê pela frente.
#include <stdio.h>
#include <stdbool.h>
#define marmita 5 //numero de vertices
#define arestas 8
#define destino false
#define vInicial 0 // é sempre um valor a mais
#define vFinal 2
//parte 1 - > marmita = 5 arestas = 8
int matrix[marmita][marmita] = {
                                {0,30,-15,0,20},
                                {-30,0,-10,50,0},
                                {15,10,0,5,-10},
                                {0,50,-5,0,-30},
                                {-20,0,10,30,0}};
int matrixTWO[marmita][arestas] = {
                                {20,0,0,30,-15,0,0,0},
                                {0,0,50,-30,0,0,0,-10},
                                {0,0,0,0,15,-10,5,10},
                                {0,-30,50,0,0,0,-5,0},
                                {-20,30,0,0,0,10,0,0}};

// parte 2 - > marmita = 7 arestas = 9
// int matrix[marmita][marmita] = {
//                                 {0,2,0,4,12,0,0},
//                                 {-2,0,1,0,0,5,0},
//                                 {0,-1,0,0,0,0,40},
//                                 {-6,0,0,0,0,4,0},
//                                 {-12,0,0,0,0,0,30},
//                                 {0,-5,0,-4,0,0,8},
//                                 {0,0,-40,0,-30,-8,0}};
// int matrixTWO[marmita][arestas] = {
//                                 {2 ,6 ,12 ,0 ,0 ,0 ,0  ,0 ,0  },
//                                 {-2,0 ,0  ,1 ,5 ,0 ,0  ,0 ,0  },
//                                 {0 ,0 ,0  ,-1,0 ,0 ,40 ,0 ,0  },
// 								{0 ,-6,0  ,0 ,0 ,4 ,0  ,0 ,0  },
// 								{0 ,0 ,-12,0 ,0 ,0 ,0  ,0 ,30 },
// 								{0 ,0 ,0  ,0 ,-5,-4,0  ,8 ,0  },
//                                 {0 ,0 ,0  ,0 ,0 ,0 ,-40,-8,-30}};
int visitados[marmita];
int vertices[marmita]; // vai guardar a ordem dos vertices passados
int dist = 0;
bool verifica(){
    if(vInicial > marmita-1) return false;
    else if(vFinal > marmita-1 && destino) return false;
    return true;
}
void gulosoAdjacencia(int v, int d, bool objetivo) {
    int a = 0, position = 0;
    printf("Adjacencia: %d --> ", v+1);
    do{
        bool existe = false;
        int aux = 1234567;
        for(a = 0; a < marmita; a++){ // percore nas arestas do vertice selecionado
            if(visitados[a] == 1) // verifica se esse vertice já não foi visitado
                existe = true;
            if(matrix[v][a] < aux && matrix[v][a] > 0 && !existe){
                aux = matrix[v][a];
                position = a;  // salva o possivel novo vertice
            }
            existe = false;
        }
        visitados[v] = 1;
        v = position; // novo vertice
        if(objetivo && v == d){
            printf("%d Destino encontrado! Distância: %d\n", v+1, dist+aux);
            return;
        } else if(visitados[v] == 1){
            if(objetivo) printf("  Não foi possivel encontrar!\n");
            else printf("  Distância: %d\n",dist);
            return;
        }
        printf("%d --> ", v+1);
        dist += aux;
    }while(true);
}
void gulosoIncidencia(int v, int d, bool objetivo) {
    int y = 0, a = 0, position = 0, position2 = 0;
    printf("Incidendia: %d --> ", v+1);
    do{
        bool existe = false;
        int aux = 1234567;
        for(a = 0; a < arestas; a++){ // percore nas arestas do vertice selecionado
            for(y = 0; y < marmita; y++) // percore na coluna das arestas procurando o vertice destino
                if(matrixTWO[y][a] != 0 && y != v) // y != v pois seria ele mesmo
                    if(visitados[y] == 1)
                        existe = true;
            if(matrixTWO[v][a] < aux && matrixTWO[v][a] > 0 && !existe){
                aux = matrixTWO[v][a];
                position = a;
            }
            existe = false;
        }
        for(a = 0; a < marmita; a++) // procura o vertice destino dessa aresta
            if(matrixTWO[a][position] != 0 && a != v)
                position2 = a;
        visitados[v] = 1;
        v = position2;
        if(objetivo && v == d){
            printf("%d Destino encontrado! Distância: %d\n", v+1, dist+aux);
            return;
        } else if(visitados[v] == 1){
            if(objetivo) printf("  Não foi possivel encontrar!\n");
            else printf("  Distância: %d\n",dist);
            return;
        }
        printf("%d --> ", v+1);
        dist += aux;
    }while(true);
}
int main(){
    if(verifica()){
        int g = 0;
        for(g = 0; g < marmita; g++) visitados[g] = 0;
        gulosoAdjacencia(vInicial,vFinal,destino);
        dist = 0;
        for(g = 0; g < marmita; g++) visitados[g] = 0;
        gulosoIncidencia(vInicial,vFinal,destino);
    } else
        printf("Entradas invalidas \n");
    return 0;
}
