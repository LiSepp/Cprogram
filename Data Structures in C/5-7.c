/*5-7判断二叉树是否相等*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree_pointer;
typedef struct node
{
	int data;
	tree_pointer left_child,right_child;
}Node;

tree_pointer create();
/*函数1*/
int equal(tree_pointer first,tree_pointer second);
/*函数2*/
int is_equal(tree_pointer first,tree_pointer second);

int main(int argc, char const *argv[])
{
	tree_pointer first,second;
	first = create();
	second = create();
	if(equal(first,second))	
	{
		printf("The tree is equal!\n");
	}
	else
	{
		printf("The tree is not equal!\n");
	}
	return 0;
}
/*创建，懒得每次输入*/
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
/*是否相等1*/
int equal(tree_pointer first,tree_pointer second)
{
	return ((!first && !second) || (first && second && (first->data == second->data) && equal(first->left_child,second->left_child) && equal(first->right_child,second->right_child)));
}
/*是否相等2*/
int is_equal(tree_pointer first,tree_pointer second)
{
	if(!first && !second)
	{
		return 1;
	}
	if(first && second && (first->data == second->data))
	{
		if(is_equal(first->left_child,second->left_child))
		{
			if(is_equal(first->right_child,second->right_child))
				return 1;
		}
	}
	return 0;
}