/*4-20 循环链表，求链表的长度？？？*/
#include <stdio.h>
#include <stdlib.h>
#define IS_EMPTY(temp) (!(temp))

typedef struct list_node *list_pointer;
typedef struct list_node
{
	int data;
	list_pointer link;
}list_node;

list_pointer ptr = NULL;
/*创建链表*/
list_pointer create5();
/*循环链表长度*/
int length(list_pointer ptr);

int main(int argc, char const *argv[])
{
	int len;
	ptr = create5();
	len = length(ptr);
	printf("%d\n", len);
	return 0;
}
/*创建链表*/
list_pointer create5()
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
/*链表的长度*/
int length(list_pointer ptr)
{
	list_pointer temp;
	int count = 0;
	if(ptr)
	{
		temp = ptr;
		do{
			count++;
			temp = temp->link;
		}while(temp != ptr);
	}
	return count;
}