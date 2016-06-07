/*2-7稀疏矩阵的转置,将数组中的第i个元素与第i+1个元素转换*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101  /*最大存储*/
typedef struct {
	int col;
	int row;
	int value;
}term;

term a[MAX_SIZE];
term b[MAX_SIZE];

void transpose(term a[],term b[]);  /*矩阵转置*/

int main()
{
	int i,n;
	printf("Please enter an integer: ");
	scanf("%d",&n);

	if(n<1||n>MAX_SIZE)
	{
		fprintf(stderr, "Error input\n");
		exit(1);
	}
	/*输入值*/
	for(i=0;i<n;i++)
	{
		printf("Please enter the a's col: ");
		scanf("%d",&a[i].col);
		printf("Please enter the a's row: ");
		scanf("%d",&a[i].row);
		printf("Please enter the a's value: ");
		scanf("%d",&a[i].value);
	}
	/*矩阵的转置*/
	/*将第任意两个元素行和列转置*/
	transpose(a,b);
	for(i=0;i<n;i++)
	{
		printf("a:%d: %d %d %d\n", i+1,a[i].col,a[i].row,a[i].value);
	}
	for(i=0;i<n;i++)
	{
		printf("b:%d: %d %d %d\n", i+1,b[i].col,b[i].row,b[i].value);
	}
	return 0;
}
/*转置*/
void transpose(term a[],term b[])
{
	int n,i,j,currentb;
	n = a[0].value;   /*元素总数*/
	b[0].row = a[0].col;  /*b的行数 = a的行数*/
	b[0].col = a[0].row;  /*b的列数 = a的行数*/
	b[0].value = n;
	if(n > 0)      /*非零矩阵*/
	{
		currentb = 1;
		for(i = 0;i< a[0].col;i++)
		{
			/*按a的列转置*/
			for(j=1;j<=n;j++)
				/*找出当前的所有元素*/
				if(a[j].col == i)
				{
					/*元素是当前列的，加入b*/
					b[currentb].col	= a[j].col;
					b[currentb].row = a[j].row;
					b[currentb].value = a[j].value;
				}
		}
	}
}