/*4-3-1动态链栈,在栈头(top)插入或删除一个结点*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACKS 10
#define IS_FULL(temp) (!(temp))
#define IS_EMPTY(temp) (!(temp))

typedef struct {
	int key;
}element;

typedef struct stack *stack_pointer;
typedef struct stack
{
	element item;
	stack_pointer link;
}stack;
stack_pointer top[MAX_STACKS];
/*链栈的加入*/
void add(stack_pointer *top,element item);
/*链栈的删除*/
element delete(stack_pointer *top);

int main(int argc, char const *argv[])
{
	int i=0;
	int key;
	element item;
	printf("Please enter an integer: ");
	while(scanf("%d",&key)==1)
	{
		item.key = key;
		add(&top[0],item);
		printf("%d\n", top[0]->item.key);
		while(getchar()!='\n')
			continue;
		if(i==4)
			printf("%d\n",delete(&top[0]).key);
		printf("Please enter an integer: ");
		
		i++;
	}
	return 0;
}

/*加入*/
void add(stack_pointer *top,element item)
{
	stack_pointer temp = (stack_pointer)malloc(sizeof(stack));
	if(IS_FULL(temp))
	{
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	temp->item = item;
	/*互换*/
	/*添加的结点的下一个链接，为头指针*/
	temp->link = *top;
	/*头指针为添加的结点*/
	*top = temp;
}
/*删除*/
element delete(stack_pointer *top)
{
	stack_pointer temp = *top;
	element item;
	if(IS_EMPTY(temp))
	{
		fprintf(stderr, "The stack is empty\n");
		exit(1);
	}
	item = temp->item;
	*top = temp->link;
	free(temp);
	return item;
}