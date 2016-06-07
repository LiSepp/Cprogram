/*1-4 全排列，给定n(n>=1)个元素组成的集合，输出该集合的所有可能的排列	*/
#include <stdio.h>
#include <stdlib.h>
// #include <math.h>

/*perm函数中参数，list表示一个字符数组，i表示第一个元素的下标，n表示最后一个元素的下标*/
void perm(char *list,int i,int n);
void SWAP(char *a,char *b);

int main()
{
	char list[4] ={'a','b','c','d'};
	perm(list,0,3);
	return 0;
}
/*交换*/
void SWAP(char *a,char *b)
{
	char tw;
	tw = *a;
	*a = *b;
	*b = tw;
}
/*递归全排列*/
void perm(char *list,int i,int n)
{
	int j;
	if(i == n)
	{
		for(j=0;j<=n;j++)
			printf("%c", list[j]);
		printf("   ");
	}
	else
	{
		for(j=i;j<=n;j++)
		{
			SWAP(&list[i],&list[j]);
			perm(list,i+1,n);
			SWAP(&list[i],&list[j]);
		}
	}
}