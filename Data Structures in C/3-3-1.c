#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1
#define m 9
#define p 6
// 用X标记当前位置maze[row][col]，下一个位置则是maze[next_row][next_col]
// 定义一个迷宫m*p则需要一个(m+2)*(p+2)的数组

// 定义移动方式
typedef struct offsets
{
	short int vert;		/*x轴*/
	short int horiz;    /*y轴*/
} offsets;
offsets move[8] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};    /*8种移动方式*/
/*北，东北，东，东南，南，西南，西，西北*/

typedef struct {
	short int row;
	short int col;
	short int dir;  /*下标*/
}element;
element stack[MAX_STACK_SIZE];

/*定义全局数组和常量*/

int maze[m+2][p+2] = 
{
	{1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,0,1},
	{1,1,0,0,0,0,1,1},
	{1,0,1,1,1,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,0,1},
	{1,1,0,0,0,0,1,1},
	{1,0,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1}
	/*入口在mp[1][1],出口在mp[m][p]*/
};
int mark[m][p]; 	/*记录已经检查过的迷宫位置*/
int EXIT_ROW = 9;
int EXIT_COL = 6;
int top;


void path(void); /*搜素函数*/
void add(int *top,element item); /*栈的添加*/
element delete(int *top);  /*栈的删除*/
void stack_empty(void);
void stack_full(void);

int main(int argc, char const *argv[])
{
	int i;
	int j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
			mark[i][j] = 0;
		}
	}
	path();
	return 0;
}

void path(void)
{
	int i, row, col, next_row, next_col, dir, found=FALSE;
	element position;
	mark[1][1] = 1;
	top = 0;
	/*定义开始坐标*/
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 0;
	while(top > -1 && !found)
	{
		position = delete(&top);/*position = stack[(*top)--] = stack[0] , 此时top=-1，只是为了跳出函数*/
		row = position.row;/*row = 1*/
		col = position.col;/*col = 1*/
		dir = position.dir;/*dir = 1*/
		/*遍历每一个方向,并且继续移动*/
		while(dir < 8 && !found)
		{
			next_row = row + move[dir].vert;
			next_col = col + move[dir].horiz;
			if(next_row == EXIT_ROW && next_col == EXIT_COL)
				found = TRUE;
			/*如果是通路，则进入下面这条*/
			else if(!maze[next_row][next_col] && !mark[next_row][next_col])
			{
				/*记录这个坐标，用1表示*/
				mark[next_row][next_col] = 1;
				position.row = row;
				position.col = col;
				/*记录是第几种移动方式*/
				position.dir = ++dir;
				add(&top,position);
				row = next_row;
				col = next_col;
				dir = 0;
			}
			/*不是通路，则继续遍历各个方向*/
			else
				++dir;
		}
	}
	/*发现通道*/
	if(found)
	{
		printf("The path is:\n");
		printf("row  col\n");
		for(i=0;i<=top;i++)
			printf("%2d%5d\n", stack[i].row,stack[i].col);
		printf("%2d%5d\n", row,col);
		printf("%2d%5d\n", EXIT_ROW,EXIT_COL);
	}
	else
	{
		printf("The maze does not have a path!\n");
	}
}

void add(int *top,element item)
{
	if(*top >= MAX_STACK_SIZE-1)
	{
		stack_full();
		return;
	}
	stack[++*top] = item;
}

element delete(int *top)
{
	if(*top == -1)
	{
		stack_empty();
		return;
	}
	return stack[(*top)--];
}
/*堆栈已满*/
void stack_full()
{
	fprintf(stderr, "The array is full!\n");
}
/*堆栈为空*/
void stack_empty()
{
	fprintf(stderr, "The array is empty!\n");
}