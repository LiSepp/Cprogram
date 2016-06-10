/*3-2-1 循环队列*/
/*实现循环队列的创建*/
/*实现循环队列的删除*/
/*判断队列是否为空*/
/*判断队列是否已满*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef struct element
{
	int key;
}element;

element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

void addq(int front, int *rear, element item);
element deleteq(int *front, int rear);
void queue_full();
void queue_empty();

int main(int argc, char const *argv[])
{
	char choice;
	while(1)
	{
		int i;
		element item;
		printf("There are some oparetions:   \n");
		printf("a) add            d) delete\n");
		printf("Your choice: ");
		scanf("%c",&choice);
		switch(choice)
		{
			case 'a':
				printf("Please enter an integer: ");
				scanf("%d",&item.key);
				addq(front,&rear,item);
				break;
			case 'd':
				deleteq(&front,rear);
				break;
		}
		/*消除 \n */
		while(getchar() != '\n')
			continue;
		if(rear>=0)
		{
			for(i=0;i<=rear;i++)
			{
				printf("%d->",queue[i].key);
			}
		}
		printf("\n");
	}
	return 0;
}

void addq(int front, int *rear, element item)
{
	*rear = (*rear + 1) %MAX_QUEUE_SIZE;
	if(front == *rear)
	{
		queue_full();
		return;
	}
	queue[*rear] = item;
}

element deleteq(int *front,int rear)
{
	element item;
	if(*front == rear)
	{
		queue_empty();
		return;
	}
	*front = (*front +1) % MAX_QUEUE_SIZE;
	return queue[*front];
}

void queue_full()
{
	fprintf(stderr, "The queue is full!\n");
}

void queue_empty()
{
	fprintf(stderr, "The queue is empty!\n");
}