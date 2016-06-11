/*3-4-2 后缀表达式求值*/
/*待完成*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 
#define MAX_EXPR_SIZE 100
typedef enum {lparen, rparen, plud, minus, times, divide, mod, eos, operand,} precedence;
int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];

int eval(void);

int main()
{

}

int eval(void)
{
	precedence token;
	char symbol;
	int op1,op2;
	int n=0;
	int top=-1;
	token = get_token(&symbol,&n);
	while(token != eos)
	{
		if(token == operand)
			add(&top,symbol - '0');
		else
		{
			op2 = delete(&top);
			op1 = delete(&top);
			switch(token)
			{
				case plus:add(&top,op1+op2);
					break;
				case minus:add(&top,op1-op2);
					break;
				case times:add(&top,op1*op2);
					break;
				case divide:add(&top,op1/op2);
					break;
				case mod:add(&top,op1%op2);
			}
		}
		token = get_token(&symbol,&n);
	}
	return delete(&top);
}	

void add(int *top,)
{
	if(*top == MAX_STACK_SIZE)
	{
		stack_full();
		return;
	}
	return stack[++*top];
}

