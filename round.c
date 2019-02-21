#include<stdio.h>
#define M 10

struct process
{
	int pid;
	int at;
	int bt;
};

void find(process proc[],int n,int q)
{
	int tat[M];
	int wt[M];
	int rt[M];
	int t=0;
	for(int i=0;i<n;i++)
	{
		rt[i]=proc[i].bt;
	}
	int complete=0;
	int done=0;
	while(1)
	{
		done=0;
		printf("completed %d process \n",complete);
		for(int i=0;i<n;i++)
		{
			if(rt[i]>0  && proc[i].at<=t )
			{
				done=1;
				if(rt[i]>q)
				{
					rt[i]-=q;
					t+=q;
				}
				else
				{
					t+=rt[i];
					rt[i]=0;
					wt[i]=t-proc[i].bt-proc[i].at;
					tat[i]=wt[i]+proc[i].bt;
					complete++;
				}
			}
		}
		if(done==0)
			break;
	}
	printf("processes\n proc at bt wt tat \n");
	for(int i=0;i<n;i++)
	{
		printf("%d  %d  %d  %d  %d\n",proc[i].pid,proc[i].at,proc[i].bt,wt[i],tat[i]);
	}
}
int main()
{
	struct process proc[M];
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		printf("Enter %d's at,bt \n",i+1);
		scanf("%d%d",&proc[i].at,&proc[i].bt);
		proc[i].pid=i+1;
	}
	printf("enter quantum \n");
	scanf("%d",&k);
	find(proc,n,k);
}
