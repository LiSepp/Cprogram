/*例子1-1，设计程序，把n个整数排序，其中n>=1*/
#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#define NUM 100

void sort(int [],int);

int main()
{
	int i,n;
	int list[NUM];
	printf("Enter the number of numbers to generate: ");
	scanf("%d",&n);
	if(n<1 || n>NUM)
	{
		fprintf(stderr, "Invalied input!\n");
		exit(1);
	}
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
	printf("\n");
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