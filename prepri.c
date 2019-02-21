#include<stdio.h>
#define M 10
struct process{
	int pid;
	int at;
	int bt;
	int pr;
};

void find(struct process proc[],int n)
{
	int i;
	int tat[M];
	int wt[M];
	int complete=0;
	int s,ft,rt[M];
	for(i=0;i<n;i++)
		rt[i]=proc[i].bt;
	int t=0;
	int minm=1000;
	int check=0;
	//waiting time
	while(complete!=n)
	{
		for(i=0;i<n;i++)
		{
			if(proc[i].at<=t && proc[i].pr<minm && rt[i]>0)
			{
				s=i;
				minm=proc[i].pr;
				check=1;
			}
		}
		if(check==0)
		{
			t++;
			continue;
		}
		rt[s]--;
		if(rt[s]==0)
		{
			minm=1000;
			complete++;
			wt[s]=(t+1)-proc[s].bt-proc[s].at;
		}
		t++;
	}
	for(i=0;i<n;i++)
	{
		tat[i]=proc[i].bt+wt[i];
	}
	printf("order\n");
	printf("pid bt at tat wt\n");
	int ttat=0,twt=0;
	for(i=0;i<n;i++)
	{
		printf("%d  %d  %d  %d  %d\n",proc[i].pid,proc[i].bt,proc[i].at,tat[i],wt[i]);
		ttat+=tat[i];
		twt+=wt[i];
	}
	float avgtat=(float)ttat/n;
	float avgwt=(float)twt/n;

	printf("%d\n",ttat);
	printf("%d\n",twt);

}

int main()
{
	struct process proc[M];
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		printf("Enter %d's at,bt and prio\n",i+1);
		scanf("%d%d%d",&proc[i].at,&proc[i].bt,&proc[i].pr);
		proc[i].pid=i+1;
	}
	find(proc,n);
}
