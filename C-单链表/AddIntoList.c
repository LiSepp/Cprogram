#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int num;
	struct node * next;	
} Node;

void PrintList(Node * head);   //输出链表的值
Node * AddInList(Node * head,int num);   //向单链表的末尾添加节点,并返回head

int main()
{
	Node * head = NULL;  //链表初始化
	int i = 0;
	int num;
	while(i++<3)
	{
		printf("Enter an ineteger: ");
		scanf("%d",&num);
		head = AddInList(head,num);
		PrintList(head);   //每次执行打印一次
		printf("\n");
	}
	PrintList(head);    //打印全部
	printf("\n");
	return 0;
}
//输出链表的值
void PrintList(Node * head)
{
	Node * p = head; //使用指针p，指向head的地址，进行操作，也可以直接操作head
	if(p == NULL)
		printf("No data!\n");
	while(p!=NULL)  //当p的下一个节点不为空,输出
	{
		head = head->next;
		printf("%d->", p->num);  //你可以试着改为p->next，看会发发生什么事情
		p=head;
	}
	//若直接操作head
	// if(head == NULL)
	// 	printf("No data!\n");
	// while(head!=NULL)
	// {
	// 	printf("%d",head->num)
	// 	head=head->next;
	// }
}
//向单链表的末尾添加节点
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