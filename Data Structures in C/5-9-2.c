/*5-9-2 二叉树交换每个结点的左，右儿子*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree_pointer;
typedef struct node
{
	int data;
	tree_pointer left_child,right_child;
}Node;

tree_pointer ptr = NULL; 

/*创建*/
tree_pointer create();
/*中序遍历*/
void inorder(tree_pointer ptr);
/*交换头结点的左右叶子*/
tree_pointer swap_tree1(tree_pointer ptr);
/*交换任意节点的左右子叶*/
tree_pointer swap_tree2(tree_pointer ptr);

int main(int argc, char const *argv[])
{
	ptr = create();
	inorder(ptr);
	printf("\n");
	inorder(swap_tree2(ptr));
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
/*中序遍历*/
void inorder(tree_pointer ptr)
{
	if(ptr)
	{
		inorder(ptr->left_child);
		printf("%d->", ptr->data);
		inorder(ptr->right_child);
	}
}
/*交换头结点左右子叶*/
tree_pointer swap_tree1(tree_pointer ptr)
{
	tree_pointer temp;
	if(ptr)
	{
		temp = ptr->left_child;
		ptr->left_child = ptr->right_child;
		ptr->right_child = temp;
	}
	return ptr;
}
/*交换所有子叶的左右*/
tree_pointer swap_tree2(tree_pointer ptr)
{
	tree_pointer tree;
	if(ptr)
	{
		tree = ptr->left_child;
		ptr->left_child = swap_tree1(ptr->right_child);
		ptr->right_child = swap_tree1(tree);
	}
	return ptr;
}