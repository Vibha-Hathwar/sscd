/*#include<stdio.h>
int front,rear;

struct process_queue
{
	int process_num;
	int burst_time;
	int wait_time;
	int turn_around_time;
}process_queue[50];

void push(int num,int t)
{
	process_queue[++front].process_num=num;
	process_queue[front].burst_time=t;
	process_queue[front].wait_time=0;
	process_queue[front].turn_around_time=0;
}

void pop()
{
	printf("%d\t",process_queue[rear].process_num);
	printf("\t%d\t",process_queue[rear].burst_time);
	printf("\t%d\t",process_queue[rear].wait_time);
	printf("\t%d\t",process_queue[rear++].turn_around_time);
	printf("\n");	
}

float waiting_time()
{
	int total_wait=0;
	for(int i=rear+1;i<=front;i++)
	{
		process_queue[i].wait_time=process_queue[i-1].wait_time+process_queue[i-1].burst_time;
		total_wait+=process_queue[i].wait_time;
	}
	return ((float)total_wait/(float)(front+1));
}

float turn_around_time()
{
	int total_tat=0;
	for(int i=rear;i<=front;i++)
	{
		process_queue[i].turn_around_time=process_queue[i].wait_time+process_queue[i].burst_time;
		total_tat+=process_queue[i].turn_around_time;
	}
	return ((float)total_tat/(float)(front+1));
}

int main()
{
	int i,n,a,b;
	float avg_tat,avg_wt;
	front=-1;
	rear=0;
	printf("\nEnter the number of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process number:");
		scanf("%d",&a);
		printf("Enter the burst time:");
		scanf("%d",&b);
		push(a,b);
	}
	
	avg_wt=waiting_time();
	avg_tat=turn_around_time();
	printf("\nProcess no  Burst time  waiting time  turn around time\n");
	for(i=rear;i<=front;i++)
	{
		pop();
	}
	
	printf("\nAverage waiting time:%f",avg_wt);
	printf("\nAverage turn around time:%f\n",avg_tat);
	
	return 0;
}*/



#include<stdio.h>
#include<stdlib.h>
int n,a[100],b[100],v[100],start[100],stop[100];
void gantt()
{
    int min,i,j,ind,dum=0;
    for(j=0;j<n;j++)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(!v[i] && a[i]<min)
            {
                min=a[i];
                ind=i;
            }
        }
        v[ind]=1;
        if(dum<a[ind])
        {
            start[ind]=a[ind];
        }
        else
        {
            start[ind]=dum;
        }
        stop[ind]=start[ind]+b[ind];
        dum=stop[ind];
    }
}
void avgwait()
{
    int wait[100],i;
    float avg=0;
    printf("The waiting times :\n");
    for(i=0;i<n;i++)
    {
        wait[i]=start[i]-a[i];
        avg+=wait[i];
        printf("P%d : %d ms\n",i+1,wait[i]);
    }
    avg=avg/n;
    printf("Average waiting time = %f\n",avg);
}
void avgtat()
{
    int tat[100],i;
    float avg=0;
    printf("The turn around times :\n");
    for(i=0;i<n;i++)
    {
        tat[i]=stop[i]-a[i];
        avg+=tat[i];
        printf("P%d : %d ms\n",i+1,tat[i]);
    }
    avg=avg/n;
    printf("Average turn around time = %f\n",avg);
}
int main()
{
    int i;
    printf("Enter the no. of processes : ");
    scanf("%d",&n);
    printf("Enter the arrival time :\n");
    for(i=0;i<n;i++)
    {
        printf("P%d : ",i+1);
        scanf("%d",&a[i]);
        v[i]=0;
        start[i]=stop[i]=0;
    }
    printf("Enter the burst time :\n");
    for(i=0;i<n;i++)
    {
        printf("P%d : ",i+1);
        scanf("%d",&b[i]);
    }
    gantt();
    avgwait();
    avgtat();
    return 0;
}
