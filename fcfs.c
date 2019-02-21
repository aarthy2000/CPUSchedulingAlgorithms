#include<stdio.h>
#define M 10

struct process
{
	int pid;
	int at;
	int bt;
};

int main()
{
	int wt[M];
	int tat[M];
	struct process proc[M];
	int n;
	int t=0;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		printf("Enter %d's at,bt \n",i+1);
		scanf("%d%d",&proc[i].at,&proc[i].bt);
		proc[i].pid=i+1;
	}
	int complete=0;
	int rt[M];
	for(int i=0;i<n;i++)
		rt[i]=proc[i].bt;
	for(;complete!=n;)

	{
		printf("completed %d process \n",complete);
		for(int i=0;i<n;i++)
		{
			if(proc[i].at<=t && rt[i]>0)
			{
				complete++;
				t+=rt[i];
				wt[i]=t-proc[i].bt-proc[i].at;
				tat[i]=proc[i].bt+wt[i];

				rt[i]=0;
			}
		}
	}
	printf("proc at bt wt tat\n");
	for(int i=0;i<n;i++)
	{
		printf("%d  %d  %d  %d  %d\n",proc[i].pid,proc[i].at,proc[i].bt,wt[i],tat[i]);
	}
}
