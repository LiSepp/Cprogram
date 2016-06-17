/*5-4 二叉树的其他操作*/
/*实现二叉树的复制*/
#include <stdio.h>
#include <stdlib.h>
#define IS_FULL(temp) (!(temp))

/*定义结构*/
typedef struct node *tree_pointer;
typedef struct node
{
	int data;
	tree_pointer left_child,right_child;
}Node;

tree_pointer original = NULL;

tree_pointer create();
void postorder(tree_pointer original);
tree_pointer copy(tree_pointer original);

int main(int argc, char const *argv[])
{
	tree_pointer tree = NULL;
	original = create();
	postorder(original);
	printf("\n");
	tree = copy(original);
	postorder(tree);
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
/*递归后序遍历*/
void postorder(tree_pointer original)
{
	if(original)
	{
		postorder(original->left_child);
		postorder(original->right_child);
		printf("%d->", original->data);
	}
}
/*二叉树的复制*/
tree_pointer copy(tree_pointer original)
{
	tree_pointer temp;
	if(original)
	{
		temp = (tree_pointer)malloc(sizeof(Node));
		if(IS_FULL(temp))
		{
			fprintf(stderr, "The memory is full\n");
			exit(1);
		}
		temp->left_child = copy(original->left_child);
		temp->right_child = copy(original->right_child);
		temp->data = original->data;
		return temp;
	}
	return NULL;
}