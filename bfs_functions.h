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
#define INFINITE 9999 // Definição de Infinito para uso como custo máximo. (MAIOR_CUSTO_POSSIVEL)
#define VERTEX_NUM 21 // Definição do número de vértices do grafo que será processado pela BFS. (BFS_NUM_VERTICES)
#define WHITE 1 // Definição da cor Branca. (BRANCO)
#define GREY 2 // Definição da cor Cinza. (CINZA)
#define BLACK 3 // Definição da cor Preta. (PRETO)

// PROTÓTIPOS DAS FUNÇÕES:
void BFS_ListInsert(int vertex, int vertexNum);
int BFS_EmptyList();
int BFS_DeleteFromList();
void BFS_Run(int vertexNum, int fromVertex);
void BFS_Initialize(int vertexNum);
void BFS_Backtracking(int vertex);
void BFS_Process(int vertexNum, int fromVertex, int backtrackingIndex);

// FUNÇÕES DE CONTROLE DO ALGORITMO BFS:
void BFS_ListInsert(int vertex, int vertexNum){
	if(end == vertexNum - 1){
		printf("[E] List Overflow.\n"); // Não é possível inserir na fila um número maior de vértices que o número máximo de vértices do grafo.
    }
    else{
		if(top == -1){
			top = 0;
        }
		end = end + 1; // Incrementa o fim da fila, informando que um novo vértice foi inserido.
		list[end] = vertex; // Insere o vértice atual no final da lista, para fins de procura.
	}
}

int BFS_EmptyList(){
	if(top == -1 || top > end){
        return 1; // Lista está vazia.
    }
	else{
        return 0; // Lista não está vazia.
    }
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
	int i;
	int v = fromVertex;
	dist[v] = 0; // A distância do primeiro vértice inicial sempre será zero.
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

void BFS_Initialize(int vertexNum){
	int v;
	for(v = 0; v < vertexNum; v++)
		status[v] = WHITE; // Inicialmente, todos os vértices são marcados como WHITE.
	for(v = 0; v < vertexNum; v++)
		distance[v] = -1; // Todas as distâncias são zeradas. -1 significa que ainda não sofreu nenhuma alteração.
	for(v = 0; v < vertexNum; v++)
		previousVertex[v] = -1; // Todos os vértices recebem -1 como anterior, significando que a BFS ainda não foi rodada.
}

void BFS_Backtracking(int vertex){
	int size = distance[vertex]; // Size recebe a distância do vértice até o vértice inicial.
    int i;
	char auxList[size - 1]; // Lista auxiliar para navegação.
	int previous = previousVertex[vertex]; // O vértice anterior do atual é armazenado na variável auxiliar.
	printf("\n[B] Vertex: %c. Backtracking: %c ", numVertex[vertex], numVertex[vertex]);
	for(i = 0; i < size; i++){
		auxList[i] = numVertex[previous]; // A lista sempre receberá o vértice anterior do vértice anterior, possibilitando o backtracking.
		previous = previousVertex[previous];
	}
	for(i = 0; i < size; i++){
		printf("<- %c ", auxList[i]); // Imprime os vértices na sequencia inversa.
	}
}

void BFS_Process(int vertexNum, int fromVertex, int backtrackingIndex){
	BFS_Initialize(vertexNum); // Inicializando todos os controles da BFS.
	BFS_Run(vertexNum, fromVertex); // Executando a BFS a partir do vértice inicial.
    // Printando a TABELA final:
    printf("\n[T] Vértice:");
	for(int i = 0; i < vertexNum; i++){
		printf(" %2c", numVertex[i]);
	}
    printf("\n[T] Distância:");
	for(int k = 0; k < vertexNum; k++){
		printf(" %2d", distance[k]);
	}
    printf("\n[T] Vértice Anterior:");
	for(j = 0; j < vertexNum; j++){
		printf(" %2c", numVertex[previousVertex[j]]);
	}
	printf("\n");
    // Printando o Backtracking da execução da BFS:
	BFS_Backtracking(backtrackingIndex);
}
