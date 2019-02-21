#include<stdio.h>
#define M 10
struct process{
	int at;
	int bt;
	int pid;
};

void find(struct process proc[],int n)
{
	int tat[n];
	int wt[n];
	int rt[n];
	for(int i=0;i<n;i++)
		rt[i]=proc[i].bt;
	int complete=0;
	int minm=1000;
	int t=0,j;
	int s;
	while(complete!=n)
	{
		printf("|");
		minm=1000;
		for(int s=0;s<n;s++)
		{
			if(proc[s].at<=t && rt[s]>0 && proc[s].bt<minm )
			{
				j=s;
				minm=proc[s].bt;
			}
		}
		t+=proc[j].bt;
		rt[j]=0;
		//forgetting this will end in an infinite loop
		complete++;
		//minm=proc[j].bt;
		wt[j]=t-proc[j].bt-proc[j].at;
		tat[j]=wt[j]+proc[j].bt;
		printf("process %d completed in %d\n",proc[j].pid,t);
	}
	printf("The processes are pid at bt wt tat\n");
	int tatt=0,wtt=0;
	for(int i=0;i<n;i++)
	{
		printf("%d  %d  %d  %d  %d\n",proc[i].pid,proc[i].at,proc[i].bt,wt[i],tat[i]);
		tatt+=tat[i];
		wtt+=wt[i];
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
	find(proc,n);
}
