#include <stdio.h>
#include <stdlib.h>
#define TIMES 5
typedef struct node
{
	int num;
	struct node * next;	//指向下一个节点
}Node;

void ClearList(Node * head);   //清空链表
void DestroyList(Node * head); //摧毁链表
void PrintList(Node * head);   //打印链表
int LengthList(Node * head);   //返回链表的长度
Node * AddInList(Node * head,int num);   //在结尾处添加一个节点,并返回head
void InsertInList(Node * head, int i,int num);  //在位置i处加入一个节点
void DeleteList(Node * head);   //删除头结点
void DeleteFromList(Node * head,int i); // 删除位置i的节点
int GetInList(Node * head,int i); //返回i处的值

int main()
{
	int i = 0;
	int num;
	int location;
	Node * head = NULL;
	while(i++<TIMES)
	{
		printf("Enter an ineteger: ");
		scanf("%d",&num);
		head = AddInList(head,num);    //尾节点添加
	}
	//打印链表
	printf("The list is: ");
	PrintList(head);
	printf("\n");
    //输出长度
	printf("The Length of list: ");
	printf("%d\n",LengthList(head));
	//插入链表,并打印
	printf("Please enter a location you want to insert and a num you want to insert: ");
	scanf("%d %d",&location,&num);
	InsertInList(head,location,num);
	PrintList(head);
	printf("\n");
	//删除头结点
	// printf("Now we will delete the first node: ");
	// DeleteList(head);
	// PrintList(head);
	// printf("\n");
	//删除链表中的一个节点
	printf("Please enter a location you want to delete: ");
	scanf("%d",&location);
	DeleteFromList(head,location);
	PrintList(head);
	printf("\n");
	//获取节点
	printf("Please enter a location you want to get: ");
	scanf("%d",&location);
	printf("%d\n", GetInList(head,location));
	//摧毁链表
	DestroyList(head);
	printf("Bye\n");
	return 0;
}
//清空链表
void ClearList(Node * head)
{
	head->next = NULL;     //下一个节点为空，变相的删除了除头结点外的全部节点
}
//摧毁链表
void DestroyList(Node * head)
{
	Node * p = head;    //指针p指向head的地址
	while(head!=NULL)
	{
		head = head->next;
		free(p);
		p=head;
	}
}
//打印链表
void PrintList(Node * head)
{
	// if(head == NULL)
	// 	printf("No data!\n");
	// while(head!=NULL)   //可以尝试用head!=NULL,看会输出什么？
	// {
	// 	printf("%d->", head->num);
	// 	head=head->next;      
	// }
	Node * p;
	p = head;
	while(p!=NULL)
	{
		printf("%d->", p->num);
		p=p->next;
	}
}
//返回链表的长度
int LengthList(Node * head)
{
	int len=0;
	//可以尝试head!=NULL，看会输出什么?
	while(head!=NULL)  //当节点不为空的时候，len自增,
	{
		head= head->next;
		len++;
	}
	return len;
}
//在结尾处添加一个节点
Node * AddInList(Node * head, int num)
{
	Node * pnew = NULL;
	Node * pq = head;
	if(head == NULL)   //若头结点为空，则数据存入头结点
	{
		head = (Node *)malloc(sizeof(Node));
		head->num = num;    
		head->next = NULL; 
	}
	else
	{
		while(pq->next != NULL)
		{
			pq=pq->next;
		}
		pnew = (Node *)malloc(sizeof(Node));
		pnew->num = num;
		pnew->next = NULL;
		pq->next =pnew;
	}
	return head;
}
//在位置i处加入一个节点
void InsertInList(Node * head,int i,int num)
{
	int j=0;
	int len =LengthList(head);
	if(i<1||i>len)   //插入的位置小于或大于链表的长度是，提示错误
		printf("Out Of Limit!\n");
	else
	{
		Node * pnew;  //建立新的节点
		Node * temp;  //临时存放节点
		Node * pq;    //操作head
		pq = head;
		while(j!=i-1)   //进行遍历，找到i位置的节点
		{
			pq=pq->next;
			j++;
		}
		pnew = (Node *)malloc(sizeof(Node));
		pnew->num = num;
		pnew->next = NULL;
		temp = pq->next;
		pq->next = pnew;
		pnew->next = temp; 
	}
}
//删除头结点
void DeleteList(Node * head)
{
	Node * p;
	p = head->next;   //p指向headd的下一个节点
	head->next = p->next;   //要知道，head是链表第一个节点的地址
	free(p);              //释放节点
}
// 删除位置i的节点
void DeleteFromList(Node * head,int i)
{
	int j=0;
	int len = LengthList(head);
	if(i<1||i>len)
		printf("Out Of Limit!\n");
	else if(i == 1)
		DeleteList(head);
	else
	{
		Node * p;
		Node * temp;   //临时存放节点
		p = head;
		while(j!=i-2)    //进行遍历，找到i位置的节点
		{
			p=p->next;
			j++;
		}
		temp = p->next;    
		p->next = temp->next; 
	}
}
//返回i处的值
int GetInList(Node * head,int i)
{
	int j=0;
	int len = LengthList(head);
	if(i<1||i>len)
		return 0;
	else
	{
		Node * p;
		p = head;
		while(j!=i-1)   //进行遍历，找到i位置的节点
		{
			p=p->next;
			j++;
		}
		return p->num;
	}
}