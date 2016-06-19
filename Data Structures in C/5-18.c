/*5-18 二叉查找树的创建，删除和查找*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15	

typedef struct node *tree_pointer;
typedef struct node
{
	int data;
	tree_pointer left_child,right_child;
}node;
/*初始化树*/
tree_pointer root = NULL;
/*显示结点数据*/
void show_all(tree_pointer root);
/*插入数据*/
tree_pointer insert(tree_pointer root,int data);
/*查找某一个结点*/
tree_pointer search(tree_pointer root,int data);
/*删除*/
void delete(int data);

int main(int argc, char const *argv[])
{
	
	return 0;
}
/*显示数据*/
void show_all(tree_pointer root)
{
	if(root)
	{
		show_all(root->left_child);
		printf("%d->", root->data);
		show_all(root->right_child);
	}
}
/*插入*/
tree_pointer insert(tree_pointer node,int data)
{
	if(node == NULL)
	{
		node = (tree_pointer)malloc(sizeof(node));
		node->data = data;
		node->left_child = NULL;
		node->right_child = NULL;
		if(root == NULL)
			root = node;
	}
	else
	{
		if(data < node->data)
			node->left_child = insert(node->left_child,data);
		else
			node->right_child = insert(node->right_child,data);
	}
	return node;
}
/*查找*/
tree_pointer search(tree_pointer root,int data)
{
	while(root)
	{
		if(data == root->data)
			return root;
		if(data < root->data)
			root = root->left_child;
		else
			root = root->right_child;
	}
	return NULL;
}
/*删除*/
void delete(int data)
{
	tree_pointer parent = find_parent(root,)
}


