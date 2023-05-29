#include<stdio.h>
#include<stdlib.h>

struct time
{
    int pid,bt,at,tat,wt,pt,rtime;
};

int main()
{
    struct time p[10];
    int i,j,n,ttat=0,twt=0;
    int endtime;
    float awt,atat;
    int completed=0,t;
    int min,process;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter the process id: ");
        scanf("%d",&p[i].pid);
        printf("Enter the burst time of process: ");
        scanf("%d",&p[i].bt);
        printf("Enter the arrival time of process: ");
        scanf("%d",&p[i].at);
        printf("Enter the priorty of process: ");
        scanf("%d",&p[i].pt);

        p[i].rtime=p[i].bt;
    }
    for(t=0;completed!=n;t++)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(p[i].at<=t && p[i].pt<min && p[i].rtime>0)
            {
                min=p[i].pt;
                process=i;
            }
        }
        p[process].rtime--;
        if(p[process].rtime==0)
        {
            completed++;
            endtime=t+1;
            p[process].wt=endtime-p[process].bt-p[process].at;
            p[process].tat=endtime-p[process].at;
            ttat+=endtime-p[process].at;
            twt+=endtime-p[process].bt-p[process].at;
        }
    }

    printf("\nPID  Priority  Burst time  Arrival time  Waiting time  Turn around time\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\t  %d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].pt,p[i].bt,p[i].at,p[i].wt,p[i].tat);
    awt=(float)twt/n;
    atat=(float)ttat/n;
    printf("\nAverage waiting time is: %f\n",awt);
    printf("average turn around time is: %f\n\n",atat);
    return 0;
}
