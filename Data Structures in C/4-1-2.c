/*4-1-2 单链表的操作*/
#include <stdio.h>
#include <stdlib.h>
/*定义链表是否为空*/
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(ptr) (!(ptr))
/*C语言里的特殊用法，可以定义尚不存在的类型的指针*/
typedef struct list_node *list_pointer;
typedef struct list_node
{
	// char data[4];
	int data;
	list_pointer link;
}list_node;
/*建立空链表*/
list_pointer ptr = NULL;


/*建立一个空链表*/
list_pointer create2();
/*链表的前端增加，函数的调用  insert(&ptr,ptr)*/
void insert(list_pointer *ptr,list_pointer node);   
/*链表的删除，函数的调用  delete(&ptr,NULL,ptr->link)*/
void delete(list_pointer *ptr,list_pointer trail,list_pointer node);   
/*表的输出*/
void print_list(list_pointer ptr);


int main(int argc, char const *argv[])
{
	ptr = create2();
	insert(&ptr,ptr);
	/*两种不同的删除*/
	delete(&ptr,NULL,ptr);
	// delete(&ptr,ptr,ptr->link);
	print_list(ptr);
	free(ptr);
	return 0;
}
/*链表的建立,建立两个结点*/
list_pointer create2()
{
	list_pointer first,second;
	first = (list_pointer)malloc(sizeof(list_node));
	second = (list_pointer)malloc(sizeof(list_node));
	first->data = 10;
	first->link = second;
	second->data = 20;
	second->link = NULL;
	return first;
}
/*链表的前端插入*/
void insert(list_pointer *ptr,list_pointer node)
{
	list_pointer temp;
	temp = (list_pointer)malloc(sizeof(list_node));
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
/*表的删除*/
void delete(list_pointer *ptr,list_pointer trail,list_pointer node)
{
	if(trail)
		trail->link = node->link;
	else
		*ptr = (*ptr)->link;
	free(node);
}
/*表的输出*/
void print_list(list_pointer ptr)
{
	printf("The list contains: ");
	for(; ptr; ptr=ptr->link)
		printf("%d->", ptr->data);
	printf("\n");
}