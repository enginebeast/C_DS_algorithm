#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Data structure
typedef struct poly_node {
	float coef;
	int expon;
	struct poly_node* link;
}poly_node;

typedef poly_node* poly_ptr;
poly_ptr aHead, aTail, bHead, bTail, result;


//udf
void insertPoly(poly_ptr* poly_head, poly_ptr* poly_tail, float coef, int expon);
void printPoly(poly_ptr poly_head);


int main(void){
	//Basic variable declaration
	int termNum;
	float coefficient;
	int exponent;

	//First polynomial
	aHead = aTail = NULL;
	printf("Please input a number of terms of first polynomial: ");
	scanf("%d", &termNum);
	//Input terms
	for (int i = 0; i < termNum; i++) {
		printf("Please input coefficient: ");
		scanf("%f", &coefficient);
		printf("Please input exponent: ");
		scanf("%d", &exponent);
		insertPoly(&aHead, &aTail, coefficient, exponent);
	}
	printPoly(aHead);
	printf("\n");
	
	//Second polynomial
	bHead = bTail = NULL;
	printf("Please input a number of terms of second polynomial: ");
	scanf("%d", &termNum);
	for (int i = 0; i < termNum; i++) {
		printf("Please input coefficient: ");
		scanf("%f", &coefficient);
		printf("Please input exponent: ");
		scanf("%d", &exponent);
		insertPoly(&bHead, &bTail, coefficient, exponent);
	}

	//Get result and print it
	result = addPoly(aHead, bHead);
	printPoly(result);
    
	return 0;
}


//UDF
void insertPoly(poly_ptr* poly_head, poly_ptr* poly_tail, float coef, int expon) {
	poly_ptr new_ptr = (poly_ptr)malloc(sizeof(poly_node));
	new_ptr->coef = coef;
	new_ptr->expon = expon;
	new_ptr->link = NULL;

	//Check if the queue is empty
	if (*poly_head == NULL) {
		*poly_head = new_ptr;
	}
	else {
		(*poly_tail)->link = new_ptr;
	}
	*poly_tail = new_ptr;
}

void printPoly(poly_ptr poly_head) {
	while (poly_head) {
		printf("%.2fx^%d ", poly_head->coef, poly_head->expon);
		poly_head = poly_head->link;
	}
}

poly_ptr addPoly(poly_ptr a, poly_ptr b) {
	poly_ptr head, tail, temp;
	float sum;
	tail = (poly_ptr)malloc(sizeof(poly_node));
	head = tail;
	while (a && b) {
		if (a->expon == b->expon){
			sum = a->coef + b->coef;
			if (sum)
				attach(sum, a->expon, &tail);
			a = a->link;
			b = b->link;
			break;
		}

		else if (a->expon == b->expon) {}
		
		else {}
	}
}