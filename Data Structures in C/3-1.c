/*3-1堆栈*/
/*实现堆栈的创建*/
/*实现堆栈元素的加入*/
/*实现堆栈的删除*/
/*判断堆栈是否为空*/
/*判断堆栈是否已满*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*定义堆栈的最大容纳量*/
#define MAX_SIZE 3
/*定义堆栈域*/
typedef struct element
{
	int key;
}element;
/*定义全局，建立堆栈数组*/
element stack[MAX_SIZE];
int top =-1;

/*向栈添加元素*/
void add(int *top,element item);
/*删除堆栈单元*/
element delete(int *top);
/*是否满了*/
void stack_full();
/*是否空*/
void stack_empty();

int main(int argc, char const *argv[])
{
	char choice;
	stack_empty();
	// stack_empty();
	while(1)
	{
		element item;
		printf("There are some oparetions: \n");
		printf("a) add            d) delete\n");
		scanf("%c",&choice);
		switch(choice)
		{
			case 'a':
				printf("Please enter an integer: ");
				scanf("%d",&item.key);
				add(&top,item);
				break;
			case 'd':
				delete(&top);
				break;
		}
		/*消除 \n */
		while(getchar() != '\n')
			continue;
		printf("The array has %d integer\n", top+1);
		printf("\n");
	}
	return 0;
}
/*增加栈单元*/
void add(int *top,element item)
{
	if(*top >= MAX_SIZE-1)
	{
		stack_full();
		return;
	}
	stack[++*top] = item;
}
/*减少栈单元*/
element delete(int *top)
{
	if(*top == -1)
	{
		stack_empty();
		return;
	}
	return stack[(*top)--];
}
/*堆栈已满*/
void stack_full()
{
	fprintf(stderr, "The array is full!\n");
}
/*堆栈为空*/
void stack_empty()
{
	fprintf(stderr, "The array is empty!\n");
}