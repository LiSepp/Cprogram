/*1-2折半查找,假定一个不同的整数n>=1，且它们已经排序并存放在list中，即list[0]<=list[1]<= ......<=list[n-1]*/
/*要求判断searchnum是否在数组list中*/

#include <stdio.h>
#include <stdlib.h>
// #include <math.h>

#define NUM 100
void sort(int [],int);/*排序*/
int compare(int x,int y);/*比较整形x,y的大小*/
int binsearch(int list[],int searchnum,int left,int right); /*查询这个数searchnum是否在数组list中*/

int main()
{
	int i,n,searchnum,left=0,right;
	int list[NUM];
	printf("Enter the number of numbers to generate: ");
	scanf("%d",&n);
	if(n<1 || n>NUM)
	{
		fprintf(stderr, "Invalied input!\n");
		exit(1);
	}
	/*赋值right*/
	right = n-1;
	/*随机给数组赋值(1-1000), rand()函数*/
	for(i=0;i<n;i++)
	{
		list[i] = rand() % 1000;
		printf("%d ",list[i]);
	}
	/*排序*/
	sort(list,n);
	printf("\n Sorted: \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",list[i]);
	}
	/*查询*/
	printf("\n Enter the number you want to search: ");
	scanf("%d",&searchnum);
	printf("Search......\n");
	if(binsearch(list,searchnum,left,right) == -1 )
		printf("The %d is not in the array\n", searchnum);
	else
		printf("The %d is in the array\n", searchnum);
	return 0;
}
/*冒泡排序*/
void sort(int list[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(list[j] > list[j+1])
			{
				int temp;
				temp = list[j];
				list[j] =list[j+1];
				list[j+1] = temp;
			}
		}
	}
}
/*比较函数，x小于y返回-1，x等于y返回0，x大于y返回1*/
int compare(int x,int y)
{
	if(x < y)
		return -1;
	else if(x == y)
		return 0;
	else
		return 1;
}
/*折半查询,如果在数组中，返回数组的下标，不在数组中返回-1*/
int binsearch(int list[],int searchnum,int left,int right)
{
	int middle;
	while(left <= right)
	{
		middle = (left + right)/2;
		switch(compare(list[middle],searchnum))
		{
			case -1: left = middle +1;break;
			case 0: return middle;
			case 1: right = middle -1;
		}
	}
	return -1;
}