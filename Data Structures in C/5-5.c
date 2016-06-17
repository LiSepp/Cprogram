/*5-5 二叉树的基本操作*/
/*实现创建,插入，比较，删除，遍历，摧毁，查找，深度，结点个数，复制*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define SIZE 100
#define IS_FULL(temp) (!(temp))
typedef char datatype;
typedef struct node *tree_pointer;
typedef struct node
{
	datatype data;
	tree_pointer left_child,right_child;
}Node;

/*创建*/
void create(tree_pointer *ptr);
/*遍历:三种递归遍历*/
void preorder(tree_pointer ptr); 
void inorder(tree_pointer ptr);
void postorder(tree_pointer ptr);
/*摧毁*/
void clear(tree_pointer *ptr);
/*比较*/
int equal(tree_pointer first,tree_pointer second);
/*删除:左右子树*/
void deleteLefttree(tree_pointer ptr);
void deleterighttree(tree_pointer ptr);
/*查找*/
tree_pointer search(tree_pointer ptr,int data);
/*深度*/
int tree_height(tree_pointer ptr);
/*节点个数*/
int tree_count(tree_pointer ptr);
/*复制*/	
tree_pointer copy(tree_pointer ptr);

int main(int argc, char const *argv[])
{
	tree_pointer root1;
	tree_pointer root2;
	printf("Enter the first tree: ");
	create(&root1);
	/*清除换行符号的影响*/
	while(getchar()!='\n')
		continue;
	printf("Enter the second tree: ");
	create(&root2);
	printf("The first: ");
	preorder(root1);
	printf("\n");
	printf("The second: ");
	preorder(root2);
	printf("\n");
	printf("The height:%d\n",tree_height(root1));
	printf("The height:%d\n",tree_height(root2));
	printf("The count: %d\n", tree_count(root1));
	clear(&root1);
	clear(&root2);
	return 0;
}
/*创建二叉树*/
/*void create(tree_pointer *ptr)
{
	int data;
	scanf("%d",&data);
	while(getchar()!='\n')
		continue;
	if(data)
	{
		*ptr = (tree_pointer)malloc(sizeof(Node));
		(*ptr)->data = data;
		(*ptr)->left_child = NULL;
		(*ptr)->right_child = NULL;
		create(&(*ptr)->left_child);
		create(&(*ptr)->right_child);	
	}
	else
	{
		*ptr = NULL;
	}
}*/
void create(tree_pointer *ptr)
{
	char data;
	data = getchar();
	if(data == '#')
	{
		*ptr = NULL;			
	}
	else
	{
		*ptr = (tree_pointer)malloc(sizeof(Node));
		(*ptr)->data = data;
		(*ptr)->left_child = NULL;
		(*ptr)->right_child = NULL;
		create(&(*ptr)->left_child);
		create(&(*ptr)->right_child);
	}
}
/*前序遍历*/
void preorder(tree_pointer ptr)
{
	if(ptr)
	{
		printf("%c->", ptr->data);
		// printf("%d->", ptr->data);
		preorder(ptr->left_child);
		preorder(ptr->right_child);
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
/*后序遍历*/
void postorder(tree_pointer ptr)
{
	if(ptr)
	{
		postorder(ptr->left_child);
		postorder(ptr->right_child);
		printf("%d->", ptr->data);
	}
}
/*摧毁*/
void clear(tree_pointer *ptr)
{
	tree_pointer pl,pr;
	if(*ptr == NULL)
		return;
	pl = (*ptr)->left_child;
	pr = (*ptr)->right_child;
	free(*ptr);
	*ptr = NULL;
	clear(&pl);
	clear(&pr);
}
/*相等*/
int equal(tree_pointer first,tree_pointer second)
{
	return((!first && !second)|| (first && second && (first->data == second->data) && equal(first->left_child,second->left_child) && equal(first->right_child,second->right_child)))
}
/*删除节点*/
void deleteLefttree(tree_pointer ptr)
{

}
void deleterighttree(tree_pointer ptr)
{

}
/*查找*/
/*tree_pointer search(tree_pointer ptr,int data)
{

}*/
/*二叉树的深度*/
int tree_height(tree_pointer ptr)
{
	int lheight,rheight;
	if(ptr == NULL)
		return 0;
	lheight = tree_height(ptr->left_child);
	rheight = tree_height(ptr->right_child);
	return (lheight > rheight) ? (1+lheight):(1+rheight);
}
/*所有节点个数*/
int tree_count(tree_pointer ptr)
{
	if(ptr==NULL)
		return 0;
	return tree_count(ptr->left_child) + tree_count(ptr->right_child) + 1;
}
/*复制*/
tree_pointer copy(tree_pointer ptr)
{
	tree_pointer temp;
	if(ptr)
	{
		temp = (tree_pointer)malloc(sizeof(Node));
		if(IS_FULL(temp))
		{
			fprintf(stderr, "The memory is full!\n");
			exit(1);
		}
		temp->left_child = copy(ptr->left_child);
		temp->right_child = copy(ptr->right_child);
		temp->data = ptr->data;
		return temp;
	}
	return NULL;
}