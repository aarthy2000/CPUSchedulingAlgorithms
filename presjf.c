#include<stdio.h>
#define N 50
struct process{
	int at;
	int bt;
	int pid;
};
void findWt(process proc[],int n,int wt[])
{
	int s=0;
	int check=0;
	int complete=0;
	int t=0;
	int ft=0;
	int rt[n];

	for(int j=0;j<n;j++)
	{
		rt[j]=proc[j].bt;
	}
	int minm=1000;
	while(complete!=n)
	{
		for(int j=0;j<n;j++)
		{
			if(proc[j].at<=t && rt[j]<minm && rt[j]>0)
			{
				s=j;
				minm=rt[j];
				check=1;
			}
		}
		if(check==0)
		{
			t++;
			continue;
		}
		rt[s]--;
		minm=rt[s];
		if(minm==0)
			minm=1000;
		if(rt[s]==0)
		{
			complete++;
			check=0;
			ft=t+1;
			wt[s]=ft-proc[s].bt-proc[s].at;

		}
if(wt[s]<0)
wt[s]=0;
t++;

	}
}
void findtat(process proc[],int n,int tat[],int wt[])
{
	for(int i=0;i<n;i++)
	{
		tat[i]=proc[i].bt+wt[i];
	}
}
void findAvg(process proc[],int n)
{
	int tat[n];
	int wt[n];
	findWt(proc,n,wt);
	findtat(proc,n,tat,wt);
	printf("pid AT BT WT TAT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d %d %d %d %d \n",proc[i].pid,proc[i].at,proc[i].bt,wt[i],tat[i]);
	}
}
void sort(process proc[],int n)
{
	process temp;
	for(int i=0;i<n-1;i++)

		for(int j=i+1;j<n;j++)
		{
			if(proc[i].at>proc[j].at)
			{
				temp=proc[i];
				proc[i]=proc[j];
				proc[j]=temp;
			}
			else if(proc[i].at==proc[j].at)
			{
				if(proc[i].bt>proc[j].bt)
				{
					temp=proc[i];
					proc[i]=proc[j];
					proc[j]=temp;

				}
			}
		}
}


int main()
{
	process proc[N];

	for(int i=0;i<5;i++)
	{
		proc[i].pid=i+1;
		scanf("%d%d",&proc[i].at,&proc[i].bt);
	}
	//sort(proc,5);
	printf("order\n");
	for(int i=0;i<5;i++)
		printf("%d %d %d\n",proc[i].pid,proc[i].bt,proc[i].at);
	findAvg(proc,5);
}
