#include<stdio.h>
#define M 10
struct process
{
	int pid;
	int at;
	int bt;
	int pr;
};

int main()
{
	int wt[M];
	int tat[M];
	struct process proc[M];
	int n,done=0;
	int t=0;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		printf("Enter %d's at,bt,pri \n",i+1);
		scanf("%d%d%d",&proc[i].at,&proc[i].bt,&proc[i].pr);
		proc[i].pid=i+1;
	}
	int complete=0;
	int rt[M];
	for(int i=0;i<n;i++)
		rt[i]=proc[i].bt;
	int minm=1000;
int idle=0;
	for(;complete!=n;)
	{
		minm=1000;
		done=1;
		idle=0;
		for(i=0;i<n;i++)
		{
			done=0;
			if(rt[i]>0 && proc[i].at<=t && proc[i].pr<minm)
			{
				done=1;
				
				printf("process %d\n",proc[i].pid);
				minm=proc[i].pr;
				k=i;
			}
			//if(done==0)
			//{
			//		idle++;
					
			//}
		}
		printf("idle %d\n",idle);
		printf("At time %d , %d process completed ..taking up %d th job\n",t,complete,proc[k].pid);
		t+=rt[k];
		rt[k]=0;
		wt[k]=t-proc[k].bt-proc[k].at;
		tat[k]=wt[k]+proc[k].bt;
		complete++;
	}
	printf("processes done \n proc at bt wt pr tat \n");
	for(int i=0;i<n;i++)
		printf("%d  %d  %d  %d  %d  %d \n",proc[i].pid,proc[i].at,proc[i].bt,wt[i],proc[i].pr,tat[i]);
}

