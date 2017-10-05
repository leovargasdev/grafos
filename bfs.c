/*
    Universidade Federal da Fronteira Sul - UFFS
    Campus Chapecó
    Ciência da Computação - CC
    GEN039 - Grafos (Matutino - 2017/2)
    Docente: Doglas André Finco
    Alunos: João Marcos Campagnolo e Leonardo Vargas
*/

// INCLUDES:
#include <stdio.h>
#include <stdlib.h>

// DEFINES:
#define INFINITE 123456789 // Definição de Infinito para uso como custo máximo. (MAIOR_CUSTO_POSSIVEL)
#define VERTEX_NUM 21 // Definição do número de vértices do grafo que será processado pela BFS. (BFS_NUM_VERTICES)
#define vFinal 10
#define WHITE 1 // Definição da cor Branca. (BRANCO)
#define GREY 2 // Definição da cor Cinza. (CINZA)
#define BLACK 3 // Definição da cor Preta. (PRETO)

// VARIÁVEIS DE CONTROLE DO PROGRAMA:
char numVertex[VERTEX_NUM] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','z'};
int end = -1;
int top = -1;
int distance[VERTEX_NUM];
int previousVertex[VERTEX_NUM];
int status[VERTEX_NUM];
int list[VERTEX_NUM];

// REPRESENTAÇÃO DO GRAFO 01:
int ADJ_Graph[VERTEX_NUM][VERTEX_NUM] = {
	//   A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  Z
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // A
		{1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // B
		{0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // C
		{0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // D
		{0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // E
		{0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // F
		{0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // G
		{0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // H
		{0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // I
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // J
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // K
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // L
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // M
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // N
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0}, // O
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, // P
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0}, // Q
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, // R
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1}, // S
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0}, // T
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1}, // Z
	};

// FUNÇÕES DE CONTROLE DO ALGORITMO BFS:
void BFS_ListInsert(int vertex, int vertexNum){
	if(end == vertexNum - 1){
		printf("[E] List Overflow.\n"); // Não é possível inserir na fila um número maior de vértices que o número máximo de vértices do grafo.
    } else {
		if(top == -1)
			top = 0;
		end = end + 1; // Incrementa o fim da fila, informando que um novo vértice foi inserido.
		list[end] = vertex; // Insere o vértice atual no final da lista, para fins de procura.
	}
}

int BFS_EmptyList(){
	if(top == -1 || top > end)
        return 1; // Lista está vazia.
    return 0; // Lista não está vazia.
}

int BFS_DeleteFromList(){
	int itemToDelete;
	if(BFS_EmptyList()){ // Caso a lista esteja vazia, não é possível excluir um elemento.
		printf("[E] List Underflow.\n");
		exit(1);
	}
	itemToDelete = list[top]; // O primeiro da lista será deletado.
	top = top + 1; // Incremenda o começo da lista para a próxima iteração.
	return itemToDelete; // Retorna o elemento que será deletado.
}

void BFS_Run(int vertexNum, int fromVertex){
	int i, v = fromVertex;
	distance[v] = 0; // A distância do primeiro vértice inicial sempre será zero.
	BFS_ListInsert(v, vertexNum); // Insere o primeiro vértice encontrado na lista de busca.
	status[v] = GREY; // Seu status recebe GREY, já que ele foi encontrado.
	while(!BFS_EmptyList()){
		v = BFS_DeleteFromList(); // Remove o vértice atual da lista.
		status[v] = BLACK; // Marca o elemento como BLACK, pois já foi vizitado.
		for(i = 0; i < vertexNum; i++){
			if(ADJ_Graph[v][i] == 1 && status[i] == WHITE){
				BFS_ListInsert(i, vertexNum);
				status[i] = GREY; // Quando encontrado, é marcado como GREY.
				previousVertex[i] = v;
				distance[i] = distance[v] + 1; // Como o grafo não possui carga nas arestas, a distância sempre será incrementada em 1.
			}
		}
	}
	printf("\n");
}

void BFS_Initialize(){
	for(int v = 0; v < VERTEX_NUM; v++){
		status[v] = WHITE; // Inicialmente, todos os vértices são marcados como WHITE.
		previousVertex[v] = distance[v] = -1; // Todas as distâncias e os vértices são zerados. -1 significa que ainda não sofreu nenhuma alteração.
	}
}

void BFS_Backtracking(){
	int size = distance[vFinal]; // Size recebe a distância do vértice até o vértice inicial.
    int i;
	char auxList[size]; // Lista auxiliar para navegação.
	int previous = previousVertex[vFinal]; // O vértice anterior do atual é armazenado na variável auxiliar.
	printf("\n[B] Vértice: %c. Backtracking: %c ", numVertex[vFinal], numVertex[vFinal]);
	for(i = 0; i < size; i++){
		auxList[i] = numVertex[previous]; // A lista sempre receberá o vértice anterior do vértice anterior, possibilitando o backtracking.
		previous = previousVertex[previous];
	}
	for(i = 0; i < size; i++)
		printf("<- %c ", auxList[i]); // Imprime os vértices na sequencia inversa.
}

void BFS_Process(int vertexNum, int fromVertex){
	BFS_Initialize(); // Inicializando todos os controles da BFS.
	BFS_Run(vertexNum, fromVertex); // Executando a BFS a partir do vértice inicial.
    // Printando a TABELA final:
    printf("\n[T] Vértice:         ");
	for(int i = 0; i < vertexNum; i++)
		printf(" %2c", numVertex[i]);
    printf("\n[T] Distância:       ");
	for(int k = 0; k < vertexNum; k++)
		printf(" %2d", distance[k]);
    printf("\n[T] Vértice Anterior:");
	for(int j = 0; j < vertexNum; j++)
		printf(" %2c", numVertex[previousVertex[j]]);
	printf("\n");
    // Printando o Backtracking da execução da BFS:
	BFS_Backtracking();
}
int main(void){
	printf("[S] Iniciando o Programa:\n");
	printf("[1] Executando os Processos da BFS para o Grafo 1:\n");
	BFS_Process(VERTEX_NUM, 0);
	printf("\n\n[E] Final da Execução do Programa.\n");
	return 0;
}
