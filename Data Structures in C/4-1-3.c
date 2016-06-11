/*4-1-2 单链表的建立*/
#include <stdio.h>
#include <stdlib.h>
/*定义链表是否为空*/
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(ptr) (!(ptr))

typedef struct list_node
{
	// char data[4];
	int data;
	struct list_node *link;
}List_Node;
/*建立空链表*/
List_Node *ptr = NULL;
/*建立一个空链表*/
List_Node *create2();
/*函数的调用  insert(&ptr,ptr)*/
void insert(List_Node **ptr,List_Node *node);

int main(int argc, char const *argv[])
{
	ptr = create2();
	insert(&ptr,ptr);
	while(ptr)
	{
		printf("%d->", ptr->data);
		ptr = ptr->link;
	}
	free(ptr);
	return 0;
}

/*链表的建立,建立两个结点*/
List_Node *create2()
{
	List_Node *first,*second;
	first = (List_Node *)malloc(sizeof(List_Node));
	second = (List_Node *)malloc(sizeof(List_Node));
	first->data = 10;
	first->link = second;
	second->data = 20;
	second->link = NULL;
	return first;
}

/*链表的前端插入*/
void insert(List_Node **ptr,List_Node *node)
{
	List_Node *temp;
	temp = (List_Node *)malloc(sizeof(List_Node));
	if(IS_FULL(temp))
	{
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	temp->data = 50;
	if(*ptr)
	{
		temp->link = node->link;
		node->link = temp;
	}
	/*链表为空*/
	else
	{
		temp->link = NULL;
		*ptr = temp;
	}
}
