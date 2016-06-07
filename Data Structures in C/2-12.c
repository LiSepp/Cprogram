/*2-12先检测末端标记的模式匹配方式*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
/*匹配*/
/*不使用strstr（）函数*/
int nfind(char *string,char *pat);

int main()
{
	char string[MAX_SIZE] = {"ababbaabaa"}; 
	char pat[MAX_SIZE] = {"aab"};
	if(nfind(string,pat) >= 0)
		printf("Successful!\n");
	else
		printf("Failed!\n");
	return 0;
}

int nfind(char *string,char *pat)
{
	int i,j,start=0;
	int lasts = strlen(string)-1;
	int lastp = strlen(pat)-1;
	int endmatch = lastp;

	for(i=0;endmatch<=lasts;endmatch++,start++)
	{
		if(string[endmatch] == pat[lastp])
			for(j=0,i=start;j<lastp&&string[i] == pat[j];i++,j++)
				;
		if(j==lastp)
			return start;
	}
	return -1;
}