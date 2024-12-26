#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constant
#define MAX_VERTICES 1000

//Data structure
typedef struct link_node {
	int data, weight;
	struct link_node* link;
}link_node;

typedef link_node* node_ptr;
node_ptr graph[MAX_VERTICES];
short visited[MAX_VERTICES] = { 0 };


//udf
void insertEdge(int u, int v, int weight);


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

	//Select minimum or maximum
	char routeType[10][10] = { "Minimum", "Maximum" };
	char selection[10];
	while (1) {
		printf("Please input minimum or maximum: ");
		scanf("%s", selection);
		
		//Minimum case
		if (strcmp(selection, routeType[0]) == 0) {
			break;
		}

		//Maximum case
		else if (strcmp(selection, routeType[1]) == 0) {
			break;
		}

		//Exception
		else
			printf("Please input right option: ");
	}
	
	return 0;
}


//UDF
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