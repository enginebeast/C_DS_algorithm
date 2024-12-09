#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Data structure
#define MAX_VERTICES 1000

typedef struct link_node {
	int data, weight;
	struct link_node* link;
}link_node;

typedef link_node* node_ptr;
node_ptr graph[MAX_VERTICES];
short visited[MAX_VERTICES] = { 0 };


//udf
void insertEdge(int u, int v, int weight);
void printGraph(int vertexNum);


int main(void) {
	//Input components
	int vertexNum, edgeNum, startVertex;
	printf("Please input the number of vertices: ");
	scanf("%d", &vertexNum);
	printf("Please input the number of edges: ");
	scanf("%d", &edgeNum);

	int u, v, weight;
	for (int i = 0; i < edgeNum; i++) {
		printf("Input %d\n", i + 1);
		printf("Please input the start vertex: ");
		scanf("%d", &u);
		printf("Please input the end vertex: ");
		scanf("%d", &v);
		printf("Please input the weight: ");
		scanf("%d", &weight);
		insertEdge(u, v, weight);
	}

	//Print graph
	printf("This is the form of undirected graph.\n");
	printGraph(vertexNum);

	return 0;
}


//udf
void insertEdge(int u, int v, int weight) {
	link_node* new_ptr = (link_node*)malloc(sizeof(link_node));
	new_ptr->data = v;
	new_ptr->weight = weight;

	if (graph[u] == NULL) {
		new_ptr->link = NULL;
	}
	else {
		new_ptr->link = graph[u];
	}
	graph[u] = new_ptr;
}

void printGraph(int vertexNum) {
	for (int i = 1; i <= vertexNum; i++) {
		printf("%d\n", i);

		int flag = 0;
		for (node_ptr w = graph[i]; ; w = w->link) {
			if (w == NULL){
				if (flag == 0)
					printf("Empty");
				break;
			}
			printf("(End vertex: %d, Weight: %d) ", w->data, w->weight);
			flag = 1;
		}
		printf("\n");
	}
}