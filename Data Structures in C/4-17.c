/*4-17 翻转单链表*/
/*例如 1->2->3->4->NULL*/
/*翻转 4->3->2->1->NULL*/
#include <stdio.h>
#include <stdlib.h>
/*定义链表是否为空*/
#define IS_EMPTY(ptr) (!(ptr))
#define IS_FULL(ptr) (!(ptr))
/*C语言里的特殊用法，可以定义尚不存在的类型的指针*/
typedef struct list_node *list_pointer;
typedef struct list_node
{
	int data;
	list_pointer link;
}list_node;
/*建立空链表*/
list_pointer ptr = NULL;
/*建立链表*/
list_pointer create4();
/*输出链表*/
void print_list(list_pointer ptr);
/*转置链表*/
list_pointer invert(list_pointer lead);

int main()
{
	list_pointer item1;
	// list_pointer item2;
	ptr = create4();
	print_list(ptr);
	/*item = invert(ptr)*/
	item1 = invert(ptr);
	print_list(item1);
	// item2 = invert(item1);
	// print_list(item2);
	/*改变了ptr*/
	print_list(ptr);
	free(ptr);
	return 0;
}

list_pointer create4()
{
	list_pointer first,second,thrid,four;
	first = (list_pointer)malloc(sizeof(list_node));
 	second = (list_pointer)malloc(sizeof(list_node));
	thrid = (list_pointer)malloc(sizeof(list_node));
 	four = (list_pointer)malloc(sizeof(list_node));
 	first->data = 1;
 	second->data = 2;
 	thrid->data = 3;
 	four->data = 4;
 	first->link = second;
 	second->link = thrid;
 	thrid->link = four;
 	four->link = NULL;
 	return first;
}
/*转置：从头到尾遍历原链表，每遍历一个结点，将其摘下放在新链表的最前端。*/
list_pointer invert(list_pointer lead)
{
	/*middle: 转置后的新链表*/
	/*trail: */
	list_pointer middle,trail;

	middle = NULL;
	while(lead)
	{
		trail = middle;
		middle = lead;
		/*遍历lead*/
		lead = lead->link;
		middle->link = trail;
	}
	return middle;
}

/*输出*/
void print_list(list_pointer ptr)
{
	printf("The list contains: ");
	for(; ptr; ptr=ptr->link)
		printf("%d->", ptr->data);
	printf("\n");
}