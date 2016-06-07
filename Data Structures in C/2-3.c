/*2-3 检查结结构是否相等*/
#include <stdio.h>
#include <string.h>
#define FALSE 0
#define TRUE 1

typedef struct human_being
{
	char name[10];
	int age;
	float salary;
}human_being;

int humans_equal(human_being person1,human_being person2);

int main()
{
	human_being person1 = {
		"xjf",
		19,
		1500
	};
	human_being person2 = {
		"xjf",
		19,
		1500
	};
	if(humans_equal(person1,person2))
		printf("The two human beings are the same\n");
	else
		printf("The two human beings are not the same\n");
	return 0;
}

int humans_equal(human_being person1,human_being person2)
{
	if(strcmp(person1.name,person2.name))
		return FALSE;
	if(person1.age != person2.age)
		return FALSE;
	if(person1.salary != person2.salary)
		return FALSE;
	return TRUE;
}