/*4-3-2 链队列*/
#include <stdio.h>
#include <stdlib.h>
#define IS_FULL(temp) (!(temp))
#define IS_EMPTY(temp) (!(temp))
#define MAX_QUEUES 10

typedef struct element
{
	int key;
}element;

typedef struct queue *queue_pointer;
typedef struct queue {
	element item;
	queue_pointer link;
};
queue_pointer front[MAX_QUEUES],rear[MAX_QUEUES];

void addq(queue_pointer *front,queue_pointer *rear, element item);
element deleteq(queue_pointer *front);

int main()
{

	return 0;
}

void addq(queue_pointer *front,queue_pointer *rear, element item)
{
	queue_pointer temp = (queue_pointer)malloc(sizeof(queue));
	if(IS_FULL(temp))
	{
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	temp->item = item;
	temp->link = NULL;
	if(*front)
		(*rear)->link = temp;
	else
		*front = temp;
	*rear = temp;
}

element deleteq(queue_pointer *front)
{
	queue_pointer temp = *front;
	element item;
	if(IS_EMPTY(temp))
	{
		fprintf(stderr, "The queue is empty\n");
		exit(1);
	}
	item = temp->item;
	*front = temp->link;
	free(temp);
	return item;
}