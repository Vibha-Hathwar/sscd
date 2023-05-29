/*
    //  run agutte , amele | baratte 
    //*** stack smashing detected ***: terminated Aborted (core dumped)

#include<stdio.h>
int main()
{
    int n,a[10],b[10],t[10],w[10],g[10],i,m;
    float att=0,awt=0;
    for(i=0;i<10;i++)
        a[i]=0; b[i]=0; w[i]=0; g[i]=0;
    printf("enter the number of process : ");
    scanf("%d",&n);
    printf("enter the burst times : ");
    for(i=0;i<n;i++)
      scanf("%d",&b[i]);
    printf("enter the arrival times ");
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    g[0]=0;
    for(i=0;i<10;i++)
        g[i+1]=g[i]+b[i];
    for(i=0;i<n;i++)
    {     
    	w[i]=g[i]-a[i];
    	t[i]=g[i+1]-a[i];
        awt=awt+w[i];
        att=att+t[i]; 
   }
     awt =awt/n;
     att=att/n;
     printf("\n\tprocess\t    waiting time\tturn arround time\n");
     for(i=0;i<n;i++)
         printf("\tp%d\t\t%d\t\t%d\n",i,w[i],t[i]);
    printf("the average waiting time is %f\n",awt);
    printf("the average turn around time is %f\n",att);
    return 0;
}*/


#include <stdio.h>

int front,rear;
int comp[50];
struct queue{
    int q_value;
    int time;
    int arr_time;
    int wait_time;
    int turn_around_time;
}temp,queue[50];

void bubble_sort(){
    for(int i=rear;i<=front;i++){
        for(int j=i+1;j<=front;j++){
            if(queue[i].arr_time>queue[j].arr_time){
                temp=queue[i];
                queue[i]=queue[j];
                queue[j]=temp;
            }
        }
    }
}

void push(int num, int t, int a){
    queue[++front].q_value=num;
    queue[front].time=t;
    queue[front].arr_time=a;
    queue[front].wait_time=0;
    queue[front].turn_around_time=0;
}

void pop(){
    printf(" %d\t",queue[rear].q_value);
    printf(" \t%d\t",queue[rear].time);
    printf(" \t%d\t",queue[rear].wait_time);
    printf(" \t%d\n",queue[rear++].turn_around_time);
}

float waiting_time(){
    int wait=0;
    for(int i=rear+1;i<=front;i++){
        queue[i].wait_time=queue[i].turn_around_time-queue[i].time;
        wait+=queue[i].wait_time;
    }
    return(wait/(front+1));
}

void find_comp_time(){
    comp[0]=queue[0].time;
    for(int i=rear+1;i<=front;i++){
        comp[i]=queue[i].time+comp[i-1];
    }
}

float turn_around_time(){
    int tat=0;
    find_comp_time();
    for(int i=rear;i<=front;i++){
        queue[i].turn_around_time=comp[i]-queue[i].arr_time;
        tat+=queue[i].turn_around_time;
    }
    return(tat/(front+1));
}

int main(){
    int i,n,k,t,a;
    front=-1;
    rear=0;
    printf("\nEnter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter process number: ");
        scanf("%d",&k);
        printf("Enter burst time: ");
        scanf("%d",&t);
        printf("Enter arrival time: ");
        scanf("%d",&a);
        push(k,t,a);
    }
    bubble_sort();
    printf("\nAverage Turn Around Time: %.2f seconds\n",turn_around_time());
    printf("\nAverage Waiting Time: %.2f seconds\n",waiting_time());
    printf("\nProcess No\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=rear;i<=front;i++){
        pop();
    }
}


// https://drive.google.com/drive/folders/1A693WZ78gtzTPWpqLq5C6QlkYydhFiKl


