#include <stdio.h>
#include <stdlib.h>
#define LENGTH 20
#define SIZE 100
typedef int datatype;
typedef struct node *tree_pointer;
typedef struct node
{
	datatype data;
	tree_pointer lchild;
	tree_pointer rchild;
}Node;

tree_pointer node = NULL;

typedef struct seqstack
{
	tree_pointer data[SIZE];
	int tag[SIZE];
	int top;
}seqstack;

void push(seqstack *s,tree_pointer t)
{
	if(s->top == SIZE)
		printf("The stack is full\n");
	else
	{
		s->top++;
		s->data[s->top] = t;
	}
}

tree_pointer pop(seqstack *s)
{
	if(s->top == -1)
		return NULL;
	else
	{
		s->top--;
		return s->data[s->top+1];
	}
}
tree_pointer create();
void postorder_dev(tree_pointer t);

int main(int argc, char const *argv[])
{
	node = create();
	postorder_dev(node); 
	return 0;
}
/*创建*/
tree_pointer create()
{
	tree_pointer first,second,third,four,five,six,seven;
	first = (tree_pointer)malloc(sizeof(Node));
	second = (tree_pointer)malloc(sizeof(Node));
	third = (tree_pointer)malloc(sizeof(Node));
	four = (tree_pointer)malloc(sizeof(Node));
	five = (tree_pointer)malloc(sizeof(Node));
	six = (tree_pointer)malloc(sizeof(Node));
	seven = (tree_pointer)malloc(sizeof(Node));
	first->data = 10;
	second->data = 20;
	third->data = 30;
	four->data = 40;
	five->data = 50;
	six->data = 60;
	seven->data = 70;
	first->lchild = second;
	first->rchild = third;
	second->lchild = four;
	second->rchild = five;
	third->lchild = six;
	third->rchild = seven;
	four->lchild = NULL;
	four->rchild = NULL;
	five->lchild = NULL;
	six->lchild = NULL;
	six->rchild = NULL;
	seven->lchild = NULL;
	seven->rchild = NULL;
	five->rchild = NULL;
	return first;
}
/*迭代后序遍历*/
void postorder_dev(tree_pointer t)
{
	seqstack s;
	s.top=-1;
	if(!t)
	{
		printf("The stack is emtpy!\n");
	}
	else
	{
		while(t || s.top!=-1)
		{
			while(t)
			{
				push(&s,t);
				s.tag[s.top] = 0;
				t=t->lchild;
			}
			if(s.tag[s.top] == 0)
			{
				t=s.data[s.top];
				s.tag[s.top]=1;
				t=t->rchild;
			}
			else
			{
				while(s.tag[s.top] == 1)
				{
					t=pop(&s);
					printf("%d->", t->data);
				}
				t = NULL;
			}
		}
	}
}



