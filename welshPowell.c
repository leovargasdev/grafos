// Data: 21/11/2017
// ALGORITMO WELSH POWELL:
#include <stdio.h>
#include <stdbool.h>
#define pneu 11 //numero de vertices
int pintar = 1;
int graus[pneu];
int cor[pneu];
char vertices[pneu] = {'A','B','C','D','E','F','G','H','I','J','K'};
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
void achaGr4ul(){
    for(int a = 0; a < pneu; a++)
        for(int k = 0; k < pneu; k++)
            if(matrix[a][k] == 1)
                graus[a]++;
}
int pintarV(int caraParaPintar){
    for(int j = 0; j < pneu; j++)
        if(matrix[caraParaPintar][j])
            if(cor[j] == pintar)
                return pintar + 1;
    return pintar;
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
        if(cor[v] == 0)
            cor[v] = pintar;
        else break; //todos os vertices estão pintados
        for(int y = 0; y < pneu; y++)
            if(matrix[v][y] == 0 && cor[y] == 0)
                cor[y] = pintarV(y);
        pintar++;
    }while(true);
}
int main(){
    for(int g = 0; g < pneu; g++)
        cor[g] = graus[g] = 0;
    achaGr4ul(); // funcção do GR4UL
    welshPowell();
    for(int a = 0; a < pneu; a++){
        printf("vertice(%c), ", vertices[a]);
        if(cor[a] == 1) printf("cor: azul\n");
        else if(cor[a] == 2) printf("cor: cinza\n");
        else if(cor[a] == 3) printf("cor: amarelo\n");
        else printf("cor: vermelho\n");
    }
    return 0;
}
