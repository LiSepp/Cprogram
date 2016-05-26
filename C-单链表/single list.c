#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int data;
	struct Node * next;
}node;  // 把struct Node 声明为 node

/*
node * add(node * head,int data)
该函数的返回值类型为node,也就是数据结构中定义的一个节点类型
*add 表示定义了一个返回值要求是指针的函数，函数名为add，不包含*的
函数的参数有两个，一个是node类型的指针变量head，*也表示的是一个指针，另一个
是int类型的普通变量data
*/
node * add(node * head,int data);
node * ListDelete(node * head,int i);
node * reverse(node * head);
node * buddleSort(node * head);
node * mergeList(node * head1,node * head2,node * head3);  //合并三个链表

void listDestroy(node * head);  //摧毁链表
void print(node * head);     //输出链表
int lengthl(node * head);   //链表长度


int main()
{
	node * head1 = NULL;
	node * head2 = NULL;
	node * head3 = NULL;
	// printf("*******************************\n");
	// printf("1)add             2)ListDelete\n");
	// printf("3)reverser        4)buddleSort\n");
	// printf("5)mergeList       6)listDestroy\n");
	// printf("7)print           8)lengthl\n");
	// printf("*******************************\n");
	// int choice;
	int i = 10;
	while(--i>0)
	{
		head1 = add(head1, rand()%100);
		head2 = add(head2, rand()%100);
	}
	head1 = add(head1,-1);
	head1 = add(head1,-3);
	printf("Before sort: \n");
	print(head1);
	print(head2);
	printf("\n");
	printf("After sort: \n");
	buddleSort(head1);
	buddleSort(head2);
	print(head1);
	print(head2);
	printf("\n");
	printf("After mergeList: \n");
	head3 = mergeList(head1,head2,head3);
	print(head3);


	listDestroy(head1);
	listDestroy(head2);
	listDestroy(head3);
	return 0;
}
//合并两个基本的有序的链表，到head3
node * mergeList(node * head1,node * head2,node * head3)
{
	node * tail = NULL;
	// int data;
	// struct Node * next;
	
	if(head1 == NULL)
	{
		head3 = head2;
		return head3;
	}
	else if(head2==NULL)
	{
		head3 = head1;
		return head3;
	}
	else
	{
		if(head1->data > head2->data)
		{
			head3 = head2;
			tail = head3;
			head2 = head2->next;
		}
		else
		{
			head3 = head1;
			tail = head3;
			head1 = head1->next;
		}
	}
	while(head1&&head2)
	{
		if(head1->data > head2->data)
		{
			tail->next = head2;
			tail = head2; //???????????
			head2 = head2->next;
		}
		else
		{
			tail->next = head1;
			tail = head1;
			head1 = head1->next;
		}
	}
	tail->next = head1 ? head1 : head2;
	return head3;
}
//用头插完成链表的反转
node * reverse(node * head)
{
	node * tempHead = NULL, * p = NULL;
	while(head)
	{
		p = head;
		head = head -> next;
		p -> next = tempHead;
		tempHead = p;
	}
	return tempHead;
}
//对链表冒泡排序(升序)
// node * buddleSort(node * head)
// {
// 	int len = lengthl(head);
// 	node * p1 ,* p2 ;
// 	node * tempFinish = NULL;
// 	while(len-- > 0)
// 	{
// 		p1 = p2 = head;
// 		while(p2 != tempFinish)
// 		{
// 			p2 = p2->next;

// 			if(p2 == NULL)
// 				break;
// 			else if(p1->data > p2->data)
// 			{
// 				p1->data = (p1->data)^(p2->data); //^ 运算符是 按位异或
// 				p2->data = (p1->data)^(p2->data);
// 				p1->data = (p1->data)^(p2->data);
// 			}
// 			p1 = p2;
// 		}
// 		tempFinish = p1;
// 	}
// 	return head;
// }

//对链表冒泡排序(升序)
node * buddleSort(node * head)
{
	int temp1;  //用于缓存数据（中间转化值）
	node * p;  //前一个
	node * q;  //后一个
	int len =lengthl(head);
	while(len>0)
	{
		len--;
		p = q = head;
		while(q != NULL)
		{
			q = q->next;
			if(q == NULL)
				break;
			else if(p->data > q->data)
			{
				// p->data = (p->data)^(q->data);
				// q->data = (p->data)^(q->data);
				// p->data = (p->data)^(q->data);
				temp1 = p->data;
				p->data = q->data;
				q->data = temp1;
			}
			p=p->next;
		}
	}
	// for(i=0;i<len;i++)
	// {
	// 	for(q = head; q->next !=NULL;q=q->next)
	// 	{
	// 		for(p= head; p->next !=NULL;p=p->next)
	// 		{
	// 			if(p->data > p->next->data)
	// 			{
	// 				temp1 = p->data;
	// 				p->data = p->next->data;
	// 				p->next->data = temp1;
	// 			}
	// 			p=p->next;
	// 		}
	// 	}
	// }
	return head;
}


//添加一个元素
node * add(node * head,int data)
{
	node * p = NULL;
	if(head == NULL)
	{
		head = (node *)malloc(sizeof(node));
		head->data = data;
		head->next = NULL;
	}
	else
	{
		p = (node *)malloc(sizeof(node));
		p->data = data;
		p->next = head;
		head = p;
	}
	return head;
}
//删除一个元素
node * ListDelete(node * head,int i)
{
	node * p1, * p2;
	if(i>lengthl(head))
		printf("error operation\n");
	else
	{
		p1 = head;
		if(i==0)
		{
			head=head->next;
			free(p1);
		}
		else
		{
			while(--i>0)
			{
				p1=p1->next;
			}
			p2 = p1->next;
			p1->next = p1->next->next;
			free(p2);
		}
	}
	return head;
}
//摧毁链表
void listDestroy(node * head)
{
	node * p = head;
	// print(head);
	while(head!=NULL)
	{
		head = head ->next;
		free(p);
		p = head;
	}
}
//查看链表的长度
int lengthl(node * head)
{
	node * p = head;
	unsigned int len =0;
	while(p != NULL)
	{
		p = p ->next;
		len++;
	}
	return len;
}
//打印链表
void print(node * head)
{
	while(head != NULL)
	{
		printf("%d ", head->data);
		head= head->next;
	}
	printf("\n");
}

