/*4-23 寻找等价类的程序*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 24
#define IS_FULL(ptr) (!(ptr))
#define FALSE 0
#define TRUE 1
typedef struct node *node_pointer;
typedef struct node
{
	int data;
	node_pointer link;
}node;

int main()
{
	short int out[MAX_SIZE];
	node_pointer seq[MAX_SIZE];
	node_pointer x,y,top;
	int i,j,n;

	printf("Enter the size (<= %d) ", MAX_SIZE);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		out[i] = TRUE;
		seq[i] = NULL;
	}
	printf("Enter a pair of numbers (-1 -1 to quit): ");
	scanf("%d%d",&i,&j);
	while(i>=0)
	{
		x = (node_pointer)malloc(sizeof(node));
		if(IS_FULL(x))
		{
			fprintf(stderr, "The memory is full\n");
			exit(1);
		}
		x->data = j;
		x->link = seq[i];
		seq[i] = x;
		x = (node_pointer)malloc(sizeof(node));
		if(IS_FULL(x))	
		{
			fprintf(stderr, "The memory is full\n");
			exit(1);
		}
		x->data = i;
		x->link = seq[j];
		seq[j] = x;
		printf("Enter a pair of numbers (-1 -1 quit): ");
		scanf("%d%d",&i,&j);
	}

	for(i=0;i<n;i++)
	{
		if(out[i])
		{
			printf("\nNew class: %5d",i);
			out[i] = FALSE;
			x = seq[i];
			top = NULL;
			for(;;)
			{
				while(x)
				{
					j = x->data;
					if(out[j])
					{
						printf("%5d", j);
						out[j] = FALSE;
						y = x->link;
						x->link = top;
						top = x;
						x = y;
					}
					else
					{
						x = x->link;
					}
				}
				if(!top)
					break;
				x=seq[top->data];
				top = top->link;
			}
		}
	}
	return 0;
}