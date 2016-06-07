/*1-3用递归调用折半查找的迭代函数*/
#include <stdio.h>
#include <stdlib.h>
// #include <math.h>

#define NUM 100

int compare(int,int);
int binsearch(int list[],int searchnum,int left,int right);
void sort(int list[],int );

int main()
{
	int i,n,searchnum,left=0,right;
	int list[NUM];
	printf("Enter the number of numbers to generate: ");
	scanf("%d",&n);
	if(n<1||n>NUM)
	{
		fprintf(stderr, "Invalied input\n");
		exit(1);
	}
	/*赋值right*/
	right = n-1;
	/*赋值数组*/
	for(i=0;i<n;i++)
	{
		list[i] = rand() % 1000;
		printf("%d ",list[i]);
	}
	printf("\n Please enter the searchnum: ");
	scanf("%d",&searchnum);
	/*排序*/
	sort(list,n);
	/*折半查找*/
	if(binsearch(list,searchnum,left,right) == -1)
		printf("The %d is not in list.\n", searchnum);
	else
		printf("The %d is in list.\n", searchnum);

	printf("\n");
	return 0;
}
/* 比较x,y */
int compare(int x,int y)
{
	if(x<y)
		return -1;
	else if(x == y)
		return 0;
	else
		return 1;
}
/* 折半查找 */
int binsearch(int list[],int searchnum,int left,int right)
{
	int middle;
	if(left <= right)
	{
		middle = (left + right)/2;
		switch(compare(list[middle],searchnum))
		{
			case -1:return binsearch(list,searchnum,middle+1,right);
			case 0:return middle;
			case 1:return binsearch(list,searchnum,left,middle-1);
		}
	}
	return -1;
}

void sort(int list[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(list[j]>list[j+1])
			{
				int temp;
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	}
}