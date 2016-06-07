/*1-23顺序查找的计时程序*/
#include <stdio.h>
#include <time.h>
#define MAX_SIZE 1001
#define ITERATIONS 16
int seqsearch(int [],int,int);

int main()
{
	int i,j,position;
	int list[MAX_SIZE];
	int sizelist[] = {0,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000};
	int numtimes[] = {0,10,20,30,40,50,60,70,80,90,100,200,300,400,500,600,700,800,900,1000};
	clock_t start,stop;
	double duration,total;
	for(i = 0;i<MAX_SIZE;i++)
		list[i] = i;
	for(i =0;i<ITERATIONS;i++)
	{
		start = clock();
		for(j=0;j<numtimes[i];i++)
		{
			position = seqsearch(list,-1,sizelist[i]);
		}
		stop = clock();
		total = ((double)(stop-start))/CLK_TCK;
		duration = total/numtimes[i];
		printf("%5d %d  %d  %f  %f\n", sizelist[i],numtimes[i],(int)(stop-start),total,duration);
		list[sizelist[i]] =sizelist[i];
	}
}

int seqsearch(int list[],int searchnum,int n)
{
	int i;
	list[n] = searchnum;
	for(i=0;list[i]!=searchnum;i++)
		;
	return ((i<n)?i:-1);
}