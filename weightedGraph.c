#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

typedef struct link_node {
	int data;
	struct link_node* link;
}link_node;

typedef link_node* node_ptr;
node_ptr graph[MAX_VERTICES];
short visited[MAX_VERTICES] = { 0 };


//udf
void insertEdge(int u, int v);
void printGraph(int vertexNum);


int main(void) {
	//Input components
	int vertexNum, edgeNum, startVertex;
	printf("Please input the number of vertices: ");
	scanf("%d", &vertexNum);
	printf("Please input the number of edges: ");
	scanf("%d", &edgeNum);

	int u, v;
	for (int i = 0; i < edgeNum; i++) {
		printf("Please input the start vertex and the end vertex: ");
		scanf("%d %d", &u, &v);
		insertEdge(u, v);
	}

	//Print graph
	printf("This is the form of undirected graph.\n");
	printGraph(vertexNum);

	return 0;
}


//udf
void insertEdge(int u, int v) {
	link_node* new_ptr = (link_node*)malloc(sizeof(link_node));
	new_ptr->data = v;
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
		printf("%d : ", i);
		for (node_ptr w = graph[i]; w; w = w->link)
			printf("%d ", w->data);
		printf("\n");
	}
}