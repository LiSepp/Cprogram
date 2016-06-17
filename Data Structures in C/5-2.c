/*5-2 二叉树，构建和迭代实现中序遍历，后序遍历，前序遍历*/
/*后序遍历待完成*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
/*定义二叉树的结构*/
typedef struct node *tree_pointer;
typedef struct node
{
	int data;
	tree_pointer left_child,right_child;
}Node;

tree_pointer node = NULL;

int top = -1;
tree_pointer stack[MAX_STACK_SIZE];
/*记录进出栈的情况，进为0，出为1*/
// int k[MAX_STACK_SIZE];
int k[MAX_STACK_SIZE];

/*typedef struct seqstack
{
	tree_pointer stack[MAX_STACK_SIZE];
	int top;
	int k[MAX_STACK_SIZE];
}seqstack;*/

/*创建二叉树*/
tree_pointer create();
/*利用迭代函数遍历*/
void iter_inorder(tree_pointer node);
void iter_preorfer(tree_pointer node);
void iter_postorder(tree_pointer node);
/*向堆栈添加*/
void add(int *top,tree_pointer node);
/*向堆栈删除*/
tree_pointer delete(int *top);
/*定义堆栈为空，已满*/
void stack_full();
void stack_empty();

int main(int argc, char const *argv[])
{
	node = create();
	printf("iter_inorder: ");
	iter_inorder(node);
	printf("\n");
	printf("iter_preorfer: ");
	iter_preorfer(node);
	printf("\n");
	printf("iter_postorder: ");
	iter_postorder(node);
	printf("\n");
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
	first->left_child = second;
	first->right_child = third;
	second->left_child = four;
	second->right_child = five;
	third->left_child = six;
	third->right_child = seven;
	four->left_child = NULL;
	four->right_child = NULL;
	five->left_child = NULL;
	six->left_child = NULL;
	six->right_child = NULL;
	seven->left_child = NULL;
	seven->right_child = NULL;
	five->right_child = NULL;
	return first;
}
/*迭代的中序遍历,每次出栈的时候输出一次*/
void iter_inorder(tree_pointer node)
{
	while(node||top!=-1)
	{
		for(;node;node=node->left_child)
		{
			add(&top,node);
		}
		node = delete(&top);
		printf("%d->", node->data);
		node = node->right_child;
	}
}
/*迭代的前序遍历，每次进栈输出一次*/
void iter_preorfer(tree_pointer node)
{
	while(node||top!=-1)
	{
		for(;node;node=node->left_child)
		{
			printf("%d->", node->data);
			add(&top,node);
		}
		node = delete(&top);
		node = node->right_child;
	}
}
/*迭代的后序遍历，每次进栈，出栈，到下一次进栈之前，输出*/
void iter_postorder(tree_pointer node)
{
	while(node || top != -1)
	{
		for(;node;node=node->left_child)
		{
			/*进栈*/
			add(&top,node);
			/*设置访问标记，0为第一次访问，1为第二次访问 */
			k[top] = 0;
		}
		if(k[top] == 0)
		{
			node = stack[top];
			k[top] = 1;
			node = node->right_child;
		}
		else
		{
			while(k[top] == 1)
			{
				/*出栈*/
				node = delete(&top);
				printf("%d->", node->data);
			}
			node = NULL;
		}
	}
}
/*堆栈添加*/
void add(int *top,tree_pointer node)
{
	if(*top >= MAX_STACK_SIZE-1)
	{
		stack_full();
		return;
	}
	stack[++(*top)] = node;
}
/*堆栈减少*/
tree_pointer delete(int *top)
{
	if(*top == -1)
	{
		stack_empty();
		return NULL;
	}
	/*返回减少的堆栈*/
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