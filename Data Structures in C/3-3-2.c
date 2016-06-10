/*3-3-2 迷宫问题2*/
#include <stdio.h>
#define MaxSize 100
#define M 8
#define N 8
int mg[M+2][N+2] =
{
	{1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

typedef struct 
{
	int i,j;
	int pre;
}Box;

typedef struct
{
	Box data[MaxSize];
	int front,rear;
}QuType;

void print(QuType qu,int front)
{
	int k = front,j,ns=0;
	printf("\n");
	do
	{
		j=k;
		k=qu.data[k].pre;
		qu.data[j].pre = -1;
	}while(k!=0);
	printf("迷宫路径如下：\n");
	k=0;
	while(k<=front)
	{
		if(qu.data[k].pre == -1)
		{
			ns++;
			printf("\t(%d,%d)", qu.data[k].i,qu.data[k].j);
			if(ns%5==0)
				printf("\n");
		}
		k++;
	}
	printf("\n");
}

int mgpath(int xi,int yi,int xe,int ye)
{
	int i,j,find=0,di;
	QuType qu;
	qu.front = qu.rear = -1;
	qu.rear++;
	qu.data[qu.rear].i = xi;
	qu.data[qu.rear].j = yi;
	qu.data[qu.rear].pre = -1;
	mg[xi][yi]=-1;
	while(qu.front!=qu.rear && !find)
	{
		qu.front++;
		i=qu.data[qu.front].i;
		j=qu.data[qu.front].j;
		if(i==xe&&j==ye)
		{
			find = i;
			print(qu,qu.front);
			return 1;
		}
		for(di=0;di<4;di++)
		{
			switch(di)
			{
				case 0:
					i=qu.data[qu.front].i-1;
					j=qu.data[qu.front].j;
					break;
				case 1:
					i=qu.data[qu.front].i;
					j=qu.data[qu.front].j+1;
					break;
				case 2:
					i=qu.data[qu.front].i+1;
					j=qu.data[qu.front].j;
					break;
				case 3:
					i=qu.data[qu.front].i;
					j=qu.data[qu.front].j-1;
					break;
			}
			if(mg[i][j]==0)
			{
				qu.rear++;
				qu.data[qu.rear].i = i;
				qu.data[qu.rear].j = j;
				qu.data[qu.rear].pre = qu.front;
				mg[i][j]=-1;
			}
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	mgpath(1,1,M,N);
	return 0;
}