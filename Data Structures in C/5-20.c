/*5-20 二叉树计数*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node *tree_pointer;
typedef struct node
{
	int data;
	tree_pointer left_child,right_child;
}Node;



