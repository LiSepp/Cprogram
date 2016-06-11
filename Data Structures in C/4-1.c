/*4-1 指针所指空间的分配和回收*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int i, *pi;
	float f, *pf;
	pi = (int *)malloc(sizeof(int));
	pf = (float *)malloc(sizeof(float));
	*pi = 1024;
	*pf = 3.14;
	printf("an integer = %d, a float = %f\n", *pi,*pf);
	free(pi);
	free(pf);
	return 0;
}