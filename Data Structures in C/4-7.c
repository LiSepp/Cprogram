/*4-7 稀疏矩阵*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
typedef enum {head,entry} tagfield;/*枚举类型*/
typedef struct matrix_node *matrix_pointer;
typedef struct entry_node
{
	int row;
	int col;
	int value;
}entry_node;
typedef struct matrix_node
{
	/*链接列表*/
	matrix_pointer down;
	/*链接行表*/
	matrix_pointer right;
	tagfield tag;
	union {
		matrix_pointer next;
		entry_node entry;
	} u;
}matrix_node;
/*保存全部头结点*/
matrix_pointer hdnode[MAX_SIZE];

/*读取稀疏举证*/
matrix_pointer mread(void);
/*获得矩阵的新结点*/
matrix_pointer new_node(void);
/*输出稀疏矩阵*/
void mwrite(matrix_pointer node);


int main(int argc, char const *argv[])
{
	
	return 0;
}

matrix_pointer mread(void)
{
	int num_rows,num_cols,num_terms,num_heads,i;
	int row,col,value,current_row;
	matrix_pointer temp,last,node;
	printf("Enter the number of rows,colums and number of nonzero terms: ");
	/*num_terms记录非零项*/
	scanf("%d%d%d",&num_rows,&num_cols,&num_terms);
	num_heads = (num_cols > num_rows) ? num_cols:num_rows;
	/*node = (matrix_pointer)malloc(sizeof(matrix_node))*/
	/*相当于分配内存*/
	node = new_node();
	/*node->tag=1 ??*/
	node->tag = entry;
	node->u.entry.row = num_rows;
	node->u.entry.col = num_cols;

	if(!num_heads)
		node ->right = node;
	else
	{
		/*初始化head node*/
		for(i=0;i<num_heads;i++)
		{
			temp = new_node();
			hdnode[i] = temp;
			/*hdnode[i]->tag = 0*/
			hdnode[i]->tag = head;
			hdnode[i]->right = temp;
			hdnode[i]->u.next = temp;
		}
		current_row = 0;
		last = hdnode[0];
		/*输入非零项 num_terms*/
		for(i=0;i<num_terms;i++)
		{
			/*输入坐标，和值*/
			printf("Enter row, column and value: ");
			scanf("%d%d%d",&row,&col,&value);
			if(row>current_row)
			{
				last->right = hdnode[current_row];
				current_row = row;
				last = hdnode[row];
			}
			temp = new_node();
			temp->tag = entry;
			temp->u.entry.row = row;
			temp->u.entry.col = col;
			temp->u.entry.value = value;
			last->right = temp;
			last = temp;
			hdnode[col]->u.next->down = temp;
			hdnode[col]->u.next = temp;
		}
		last->right = hdnode[current_row];
		for(i=0;i<num_cols;i++)
			hdnode[i]->u.next->down = hdnode[i];
		for(i=0;i<num_heads-1;i++)
			hdnode[i]->u.next = hdnode[i+1];
		hdnode[num_heads-1]->u.next = node;
		node->right = hdnode[0];
	}
	return node;
}

matrix_pointer new_node(void)
{
	matrix_pointer temp;
	temp = (matrix_pointer)malloc(sizeof(matrix_node));
	if(IS_FULL(temp))
	{
		fprintf(stderr, "The memory is full\n");
		exit(1);
	}
	return temp;
}
/*输出*/
void mwrite(matrix_pointer node)
{
	int i;
	matrix_pointer temp,head = node->right;
	printf("\n num_rows = %d, num_cols = %d \n",node->u.entry.row,node->u.entry.col);
	printf(" The matrix by row, column, and value: \n\n");
	for(i=0;i<node->u.entry.row;i++)
	{
		for(temp=head->right;temp!=head;temp=temp->right)
			printf("%5d%5d%5d \n", temp->u.entry.row,temp->u.entry.col,temp->u.entry.value);
		head = head->u.next;
	}
}
/*删除*/
void merase(matrix_pointer *node)
{
	matrix_pointer x,y,head=(*node)->right;
	int i,num_heads;
	for(i=0;i<(*node)->u.entry.row;i++)
	{
		y=head->right;
		while(y!=head)
		{
			x=y;
			y=y->right;
			free(x);
		}
		x=head;head=head->u.next;
		free(x);
	}
	y=head;
	while(y!=*node)
	{
		x=y;
		y=y->u.next;
		free(x);
	}
	free(*node);
	*node = NULL;
}