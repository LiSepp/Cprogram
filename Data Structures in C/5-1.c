/*5-1 二叉树，构建和递归实现中序遍历，后序遍历，前序遍历*/
#include <stdio.h>
#include <stdlib.h>
/*定义二叉树的结构*/
typedef struct node *tree_pointer;
typedef struct node
{
	int data;
	tree_pointer left_child,right_child;
}node;

tree_pointer ptr = NULL;

/*创建二叉树*/
tree_pointer create();
/*利用递归函数遍历*/
void inorder(tree_pointer ptr);
void preorder(tree_pointer ptr);
void postorder(tree_pointer ptr);


int main(int argc, char const *argv[])
{
	ptr = create();
	printf("inorder: ");
	inorder(ptr);
	printf("\n");
	printf("preorder: ");
	preorder(ptr);
	printf("\n");
	printf("postorder: ");
	postorder(ptr);
	printf("\n");
	return 0;
}
/*创建*/
tree_pointer create()
{
	tree_pointer first,second,third,four,five,six,seven;
	first = (tree_pointer)malloc(sizeof(node));
	second = (tree_pointer)malloc(sizeof(node));
	third = (tree_pointer)malloc(sizeof(node));
	four = (tree_pointer)malloc(sizeof(node));
	five = (tree_pointer)malloc(sizeof(node));
	six = (tree_pointer)malloc(sizeof(node));
	seven = (tree_pointer)malloc(sizeof(node));
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
/*中序遍历: LVR*/
void inorder(tree_pointer ptr)
{
	if(ptr)
	{
		/*递归左子树*/
		inorder(ptr->left_child);
		/*输出存储数据*/
		printf("%d->", ptr->data);
		/*结果：40->20->50->10->60->30->70->*/
		/*递归右子树*/
		inorder(ptr->right_child);
	}
}
/*前序遍历*/
void preorder(tree_pointer ptr)
{
	if(ptr)
	{
		printf("%d->", ptr->data);
		/*结果：10->20->40->50->30->60->70->*/
		preorder(ptr->left_child);
		preorder(ptr->right_child);
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
		/*结果：40->50->20->60->70->30->10->*/
	}
}