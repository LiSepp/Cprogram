/*4-19 循环表，在表前端插入结点*/
#include <stdio.h>
#include <Stdlib.h>
#define IS_EMPTY(temp) (!(temp))

typedef struct list_node *list_pointer;
typedef struct list_node
{
	int data;
	list_pointer link;
}list_node;

list_pointer ptr = NULL;
/*创建循环链表*/
list_pointer create();
/*在表前端插入结点*/
void insert_front(list_pointer *ptr,list_pointer node);


int main(int argc, char const *argv[])
{
	// int i;
	list_pointer node = (list_pointer)malloc(sizeof(list_node));
	node->data = 40;
	node->link = NULL;
	ptr = create();
	insert_front(&ptr,node);
	for(;ptr;ptr = ptr->link)
	{
		printf("%d\n", ptr->data);
	}
	free(ptr);
	free(node);
	return 0;
}
/*创建循环链表*/
list_pointer create()
{
	list_pointer first,second,third;
	first = (list_pointer)malloc(sizeof(list_node));
	second = (list_pointer)malloc(sizeof(list_node));
	third = (list_pointer)malloc(sizeof(list_node));
	first->data = 10;
	second->data = 20;
	third->data = 30;
	first->link = second;
	second->link = third;
	third->link = first;
	return first;
}
/*在表前端插入结点*/
void insert_front(list_pointer *ptr,list_pointer node)
{
	/*循环表为空，则直接设置node我头结点*/
	if(IS_EMPTY(*ptr))
	{
		*ptr = node;
		node->link = node;
	}
	else
	{
		/*书上源码，在第二个结点加入*/
		/*node->link = (*ptr)->link;
		(*ptr)->link = node;*/

		/*在头加入，是不是很蠢*/
		node->link = *ptr;
		(*ptr)->link->link->link = node;
	}
}
