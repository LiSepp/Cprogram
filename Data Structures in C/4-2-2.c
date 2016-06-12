/*4-1-2 单链表的操作2*/
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
/*链表结点的删除*/
void delete(List_Node **ptr,List_Node *trail);
/*链表的输出*/
void print_list(List_Node *ptr);
/*链表的长度*/
int length(List_Node *ptr);

int main(int argc, char const *argv[])
{
	ptr = create2();
	insert(&ptr,ptr);
	delete(&ptr,NULL);
	// delete(&ptr,ptr);
	print_list(ptr);
	printf("%d\n", length(ptr));
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

/*链表中间值删除*/
void delete(List_Node **ptr,List_Node *trail)
{
	if(trail)
	{
		trail->link = trail->link->link;
	}
	else
	{
		*ptr = (*ptr)->link;
	}
}

int length(List_Node *ptr)
{
	int len=0;
	while(ptr)
	{
		len++;
		ptr=ptr->link;
	}
	return len;
}

/*表的输出*/
void print_list(List_Node *ptr)
{
	printf("The list contains: ");
	for(; ptr; ptr=ptr->link)
		printf("%d->", ptr->data);
	printf("\n");
}