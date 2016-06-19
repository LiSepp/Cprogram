/*5-15 二叉查找树:迭代查找和递归查找*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node *tree_pointer;
typedef struct node
{
	int data;
	tree_pointer left_child,right_child;
}Node;
/*二叉查找树的建立*/
tree_pointer create();
/*二叉查找树的递归查找*/
tree_pointer search(tree_pointer root,int key);
tree_pointer search3(tree_pointer root,int key);
/*二叉查找树的迭代查找*/
tree_pointer search2(tree_pointer root,int key);
/*中序遍历*/
void inorder(tree_pointer root);

int main(int argc, char const *argv[])
{
	tree_pointer root = NULL;
	tree_pointer find = NULL;
	root = create();
	inorder(root);
	printf("\n");

	find = search3(root,10);
	if(find)
		printf("%d\n", find->data);
	else
		printf("None\n");
	return 0;
}
/*建立*/
tree_pointer create()
{
	tree_pointer first,second,third,four;
	first = (tree_pointer)malloc(sizeof(Node));
	second = (tree_pointer)malloc(sizeof(Node));
	third = (tree_pointer)malloc(sizeof(Node));
	four = (tree_pointer)malloc(sizeof(Node));
	first->data = 10;
	second->data = 5;
	third->data = 40;
	four->data = 2;
	first->left_child = second;
	first->right_child = third;
	second->left_child = four;
	second->right_child = NULL;
	third->left_child = NULL;
	third->right_child = NULL;
	four->left_child = NULL;
	four->right_child = NULL;
	return first;
}
/*查找*/
tree_pointer search(tree_pointer root, int key)
{
	if(!root)
		return NULL;
	if(key == root->data)
		return root;
	/*数值小于关键字，往左子叶递归*/
	if(key<root->data)
		return search(root->left_child,key);
	return search(root->right_child,key);
}
/*查找2*/
tree_pointer search2(tree_pointer tree,int key)
{
	while(tree)
	{
		if(key == tree->data)
			return tree;
		if(key < tree->data)
			tree = tree->left_child;
		else
			tree = tree->right_child;
	}
	return NULL;
}
/*查找3*/
tree_pointer search3(tree_pointer root,int key)
{
	tree_pointer result = NULL;
	if(root)
	{
		if(key == root->data)
			return root;
		if(key < root->data)
			result = search(root->left_child,key);
		else
			result = search(root->right_child,key);
	}
	return result;
}
/*中序遍历*/
void inorder(tree_pointer root)
{
	if(root)
	{
		inorder(root->left_child);
		printf("%d->", root->data);
		inorder(root->right_child);
	}
}

