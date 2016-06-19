/*5-13 二叉树的最大堆插入操作*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENS 200
#define HEAP_FULL(n) (n == MAX_ELEMENS -1)
#define HEAP_EMPTY(n) (!n)
typedef struct element
{
	int key;	
}element;
element heap[MAX_ELEMENS];
int n=0;

void insert_max_heap(element item, int *n);

int main(int argc, char const *argv[])
{
	
	return 0;
}

void insert_max_heap(element item, int *m)
{
	int i;
	if(HEAP_FULL(*n))
	{
		fprintf(stderr, "The heap is full.\n");
		exit(1);
	}
	i = ++(*n);
	while((i!=1) && (item.key > heap[i/2].key))
	{
		heap[i] = heap[i/2];
		i/=2;
	}
	heap[i] = item;
}