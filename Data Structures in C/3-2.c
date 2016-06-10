/*3-2队列：先进先出*/
/*实现队列的创建*/
/*实现队列的添加*/
/*实现队列的删除*/
/*判断队列是否为空*/
/*判断队列是否已满*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 5  /*队列的最大容量*/
/*建立队列的域*/
typedef struct element
{
	int key;
}element;
/*创建全局变量*/
element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

/*队列的入队*/
void addq(int *rear,element item);
/*队列的出队*/
element deleteq(int *front,int rear);
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
				addq(&rear,item);
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
/*入队*/
void addq(int *rear,element item)
{
	if(*rear == MAX_QUEUE_SIZE-1)   /*是否满了*/
	{
		queue_full();
		return;
	}
	queue[++*rear] = item;
}
/*出队*/
/*此处有很大的漏洞*/
/*只是单纯的返回删除的单元*/
/*实际上并未删除,而是改变头的值*/
element deleteq(int *front,int rear)
{
	if(*front == rear)     /*是否空*/
	{
		queue_empty();
		return;
	}
	return queue[++*front];
}
/*是否满了*/
void queue_full()
{
	fprintf(stderr, "The queue is full!\n");
}
/*是否空*/
void queue_empty()
{
	fprintf(stderr, "The queue is emtpy!\n");
}



