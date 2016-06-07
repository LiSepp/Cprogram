/*1-22选择排序函数的计时程序*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 1601  /*定义数组最大元素个数*/
#define ITERATIONS 26  /*定义需要排序的数组个数*/
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t)) /*交换*/

void sort(int [],int);

int main()
{
	int i,j,n;/*n表示数组元素的个数*/
	int list[MAX_SIZE];
	int sizelist[] = {0,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600};
	time_t start_t,end_t;
	double diff_T;  /*时间的差值*/
	/*随机赋值数组list*/
	for(j=0;j<ITERATIONS;j++)
	{
		n = sizelist[j];
		for(i=0;i<n;i++)
		{
			list[i] = rand() % 10000;
		}
		/*计时*/
		time(&start_t);
		sort(list,sizelist[j]);
		time(&end_t);
		diff_T = (double)difftime(end_t,start_t);
		printf("The %d   time:%f\n", sizelist[j], diff_T);
	}
	return 0;
}
/*选择排序*/
void sort(int list[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(list[j] < list[min])
				min = j;
		}
		SWAP(list[i],list[min],temp);
	}
}