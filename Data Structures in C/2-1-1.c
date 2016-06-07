/*2-1-1一维数组寻址*/
#include <stdio.h>
#define MAX_SIZE 5

void print1(int *ptr,int rows);

int main()
{
	int one[] = {0,1,2,3,4};
	print1(one,MAX_SIZE);/*输出数组one*/
	return 0;
}
/*输出*/
void print1(int *ptr,int rows)
{
	int i;
	printf("Address Contents\n");
	for(i=0;i<rows;i++)
		printf("%8u%5d\n",ptr+i,*(ptr+i));/*分别输出地址和值*/
	printf("\n");
}