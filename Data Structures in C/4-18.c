/*4-18 串接单链表*/
#include <stdio.h>
#include <Stdlib.h>
#define IS_FULL(temp) (!(temp))
#define IS_EMPTY(temp) (!(temp))

typedef struct list_node *list_pointer;
typedef struct list_node
{
	int data;
	list_pointer link;
}list_node;
list_pointer ptr1 = NULL;
list_pointer ptr2 = NULL;

/*链表的链接，并返回ptr1*/
list_pointer concatenate(list_pointer ptr1,list_pointer ptr2);
/*链表的创建*/
list_pointer create1();
list_pointer create2();
/*链表的输出*/
void print_list(list_pointer ptr);


int main(int argc, char const *argv[])
{
	ptr1 = create1();
	ptr2 = create2();
	concatenate(ptr1,ptr2);
	print_list(ptr1);
	free(ptr1);
	free(ptr2);
	return 0;
}

/*链接*/
list_pointer concatenate(list_pointer ptr1,list_pointer ptr2)
{
	list_pointer temp;
	if(IS_EMPTY(ptr1))
		return ptr2;
	else
	{
		if(!IS_EMPTY(ptr2))
		{
			/*遍历ptr1，使其指向最后一个结点*/
			for(temp = ptr1;temp->link;temp=temp->link)
				;
			temp->link = ptr2;
		}
		return ptr1;
	}
}
/*链表的创建*/
list_pointer create1(list_pointer ptr)
{
	list_pointer first,second;
	first = (list_pointer)malloc(sizeof(list_node));
	second = (list_pointer)malloc(sizeof(list_node));
	first->data =  10;
	second->data = 20;
	first->link = second;
	second->link = NULL;
	return first;
}
list_pointer create2(list_pointer ptr)
{
	list_pointer first,second;
	first = (list_pointer)malloc(sizeof(list_node));
	second = (list_pointer)malloc(sizeof(list_node));
	first->data =  30;
	second->data = 40;
	first->link = second;
	second->link = NULL;
	return first;
}
/*链表的输出*/
void print_list(list_pointer ptr)
{
	printf("The list contains: ");
	while(ptr)
	{
		printf("%d->",ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}