#include<stdio.h>
int n,nf,in[100],p[50],hit=0,i,j,k,pgfaultcnt=0;
void getData()
{
    printf("Enter length of page reference sequence\n");
    scanf("%d",&n);
    printf("Enter the page reference sequence\n");
    for(i=0; i<n; i++)
        scanf("%d",&in[i]);
        printf("Enter no of frames\n");
    scanf("%d",&nf);
}
void initialize()
{
    pgfaultcnt=0;
    for(i=0; i<nf; i++)
        p[i]=9999;
}
int isHit(int data)
{
    hit=0;
    for(j=0; j<nf; j++)
        if(p[j]==data)
        {
            hit=1;
            break;
        }
    return hit;
}
int getHitIndex(int data)
{
    int hitind;
    for(k=0; k<nf; k++)
        if(p[k]==data)
        {
            hitind=k;
            break;
        }
    return hitind;
}
void dispPages()
{
    for (k=0; k<nf; k++)
    {
        if(p[k]!=9999)
        printf(" %d",p[k]);
    }
}
void dispPgFaultCnt() 
{ 
    printf("\nTotal no of page faults:%d\n",pgfaultcnt);
}
void fifo()
{
    initialize();
    for(i=0; i<n; i++)
    {
        printf("\nFor %d :",in[i]);
        if(isHit(in[i])==0)
        {
            for(k=0; k<nf-1; k++)
                p[k]=p[k+1];
            p[k]=in[i];
            pgfaultcnt++;
            dispPages();
        }
        else
            printf("No page fault");
    }
    dispPgFaultCnt();
}
void lru()
{
    initialize();
    int least[50];
    for(i=0; i<n; i++)
    {
        printf("\nFor %d :",in[i]);
        if(isHit(in[i])==0)
        {
            for(j=0; j<nf; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i-1; k>=0; k--)
                {
                    if(pg==in[k])
                    {
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-9999;
            }
            int min=9999;
            int repindex;
            for(j=0; j<nf; j++)
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            p[repindex]=in[i];
            pgfaultcnt++;
            dispPages();
        }
        else
            printf("No page fault");
    }
    dispPgFaultCnt();
}
void lfu()
{
    int usedcnt[100],least,repin,sofarcnt=0,bn;
    initialize();
    for(i=0; i<nf; i++)
        usedcnt[i]=0;
    for(i=0; i<n; i++)
    {
        printf("\n For %d :",in[i]);
        if(isHit(in[i]))
        {
            int hitind=getHitIndex(in[i]);
            usedcnt[hitind]++;
            printf("No page fault");
        }
        else
        {
            pgfaultcnt++;
            if(bn<nf)
            {
                p[bn]=in[i];
                usedcnt[bn]=usedcnt[bn]+1;
                bn++;
            }
            else
            {
                least=9999;
                for(k=0; k<nf; k++)
                    if(usedcnt[k]<least)
                    {
                        least=usedcnt[k];
                        repin=k;
                    }
                p[repin]=in[i];
                sofarcnt=0;
                for(k=0; k<=i; k++)
                    if(in[i]==in[k])
                        sofarcnt=sofarcnt+1;
                usedcnt[repin]=sofarcnt;
            }
            dispPages();
        }
    }
    dispPgFaultCnt();
}
int main()
{
    int choice;
    while(1)
    {
        printf("1.Enter data\t2.FIFO\t3.LRU\t4.LFU\nEnter your choice:");
            scanf("%d",&choice);
        switch(choice)
        {
            case 1:getData();
                    break;
            case 2:fifo();
                    break;
            case 3:lru();
                    break;
            case 4:lfu();
                    break;
            default:printf("invalid choice\n");
                    break;
        }
    }
}
