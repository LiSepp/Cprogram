/*1-4 全排列，给定n(n>=1)个元素组成的集合，输出该集合的所有可能的排列	*/
#include <stdio.h>
#include <stdlib.h>
// #include <math.h>

void perm(int [],int i,int n);/*迭代全排列函数*/
void SWAP(int *a,int *b); /*交换*/

int main()
{
	// int i,n;
	int list[4] = {1,2,3,4};
	perm(list,0,3);
	return 0;
}
/*递归全排列*/
void perm(int list[],int i,int n)
{
	int j;
	if(i==n)
	{
		for(j=0;j<=n;j++)
			printf("%d", list[j]);
		printf("   ");
	}
	else
	{
		for(j=i;j<=n;j++)
		{
			/*这个程序的精华就在这3句*/
			SWAP(&list[i],&list[j]);/*1)可以理解成是现场保护为 这只是从结构上说 实际上这里 就相当于中断服务程序啦 即你实际要做的事情啦*/
			perm(list,i+1,n);    /*2)这里可以理解为中断嵌套 即进入下一个中断 也就是说下一级的中断的优先级比上一级的高 所以先得以运行*/
			SWAP(&list[i],&list[j]);  /*3)这里就是现场恢复啦  实际上做的事情的确是把交换后的两个数据的再次交换 恢复到交换之前的状态 即1）状态之前*/
		}
	}
}
/*交换*/
void SWAP(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}