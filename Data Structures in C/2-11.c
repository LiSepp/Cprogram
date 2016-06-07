/*2-11字符串插入函数*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
/*字符插入*/
void strnins(char *s,char *t,int i);

int main()
{
	char string1[MAX_SIZE] = {"dog"};
	char string2[MAX_SIZE] = {"house"};
	char *s = string1;
	char *t = string2;
	strnins(s,t,1);
	printf("%s",string1);
	return 0;
}
/*字符串插入，插入位置为i*/
void strnins(char *s,char *t,int i)
{
	char string[MAX_SIZE],*temp = string;

	if(i<0||i>strlen(s))
	{
		fprintf(stderr, "Position is out of bounds\n");
		exit(1);
	}
	/*如果s为空，直接把t指向的字符串，接在s的后面*/
	if(!strlen(s))
		strcpy(s,t);
	else if(strlen(t))
	{
		strncpy(temp,s,i);
		strcat(temp,t);
		strcat(temp,(s+i));  /*指针，使其复制i以后的字符串*/
		strcpy(s,temp);
	}
}
