/*5-3 二叉树的层序遍历*/
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


/*创建二叉树*/
tree_pointer create();
/*利用迭代函数遍历*/
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
	// printf("iter_postorder: ");
	// iter_postorder(node);
	// printf("\n");
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