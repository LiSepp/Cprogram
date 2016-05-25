#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node * next;	
} Node;

void PrintList(Node * head);   //输出链表的值
void AddInList(Node * head,int num);   //向单链表的末尾添加节点

int main()
{
	Node * head1 = (Node*)malloc(sizeof(Node));  //初始化链表
	head1->next = NULL;
	// Node * head1;
	// InitList(head1);
	int i = 0;
	int num;
	while(i++<3)
	{
		printf("Enter an ineteger: ");
		scanf("%d",&num);
		AddInList(head1,num);
		PrintList(head1);
		printf("\n");
	}
	// PrintList(head1);
	return 0;
}
//输出链表的值
void PrintList(Node * head)
{
	Node * p = head; //使用指针p，指向head的地址，进行操作，也可以直接操作head
	if(head == NULL)
		printf("No data!\n");
	while(p->next!=NULL)  //当p的下一个节点不为空,输出
	{
		head=head->next;
		printf("%d->", head->num);  //你可以试着改为p->next，看会发发生什么事情
		p=head;
	}
	//若直接操作head
	/*
	if(head == NULL)
		printf("No data!\n");
	while(head->next!=NULL)
	{
		head=head->next;
		printf("%d",head->num)
	}
	*/
}
//向单链表的末尾添加节点
void AddInList(Node * head, int num)
{
	Node * pnew = NULL;
	Node * pq = NULL;
	pq = head;
	while(pq->next != NULL)
	{
		pq=pq->next;
	}
	pnew = (Node *)malloc(sizeof(Node));
	pnew->num = num;
	pnew->next = NULL;
	pq->next = pnew;
}