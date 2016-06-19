/*5-17 二叉查找树的插入*/
#include <stdio.h>
#include <stdlib.h>
#define IS_FULL(temp) (!(temp))
#define FALSE 0
#define TRUE 1
typedef struct node *tree_pointer;
typedef struct node
{
	int data;
	tree_pointer left_child,right_child;
}Node;
/*插入，传递地址*/
void insert_node(tree_pointer *node,int num);
void create(tree_pointer *tree);
void inorder(tree_pointer ptr);
/*查找*/
tree_pointer modified_search(tree_pointer ptr,int num);

int main(int argc, char const *argv[])
{
	int num;
	tree_pointer tree;
	create(&tree);
	inorder(tree);
	printf("\n");
	printf("Please enter a integer: ");
	while(scanf("%d",&num)==1)
	{
		insert_node(&tree,num);
		inorder(tree);
		printf("\n");
		printf("Please enter a integer: ");
	}
	return 0;
}
/*创建*/
void create(tree_pointer *tree)
{
	int data;
	scanf("%d",&data);
	while(getchar()!='\n')
		continue;
	if(data == 0)
		*tree = NULL;
	else
	{
		(*tree) = (tree_pointer)malloc(sizeof(Node));
		(*tree)->data = data;
		(*tree)->left_child = NULL;
		(*tree)->right_child = NULL;
		create(&(*tree)->left_child);
		create(&(*tree)->right_child);
	}
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
/*插入*/
void insert_node(tree_pointer *node, int num)
{
	tree_pointer ptr,temp = modified_search(*node,num);
	if(temp || !(*node))
	{
		ptr = (tree_pointer)malloc(sizeof(Node));
		if(IS_FULL(ptr))
		{
			fprintf(stderr, "The memory is full\n");
			exit(1);
		}
		ptr->data = num;
		ptr->left_child = ptr->right_child = NULL;
		if(*node)
		{
			if(num < temp->data)
				temp->left_child = ptr;
			else
				temp->right_child = ptr;
		}
		else
			*node = ptr;
	}	
}
/*查找*/
tree_pointer modified_search(tree_pointer tree,int key)
{
	if(!tree)
		return NULL;
	while(tree)
	{
		if(key == tree->data)
			return NULL;
		if(key < tree->data)
			tree = tree->left_child;
		else
			tree = tree->right_child;
		return tree;
	}
}
