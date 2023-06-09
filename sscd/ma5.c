//memory allocation
//Write a C program to implement the following contiguous memory allocation techniques : a) Worst-fit b) Best-fit c) First-fit
#include <stdio.h>
#include <stdlib.h>
int processMemory[100], tempMemory[100], memory[100];
int noMemoryBlock, noProcesses;
void fnFirstFit(int memory[])
{
    int i,j;
    printf("\nFirstFit\nProcess\t\tMemoryBlock");
    for(i=0;i<noProcesses;i++)
    {
        int flag=0;
        for(j=0;j<noMemoryBlock;j++)
            if(processMemory[i] <= memory[j])
            {
                flag=1;
                memory[j]-=processMemory[i];
                printf("\n%d\t\t%d",i+1,j+1);
                break;
            }
        if(flag==0)
            return;
    }
}
void fnWorstFit(int memory[100])
{
    int i,j;
    printf("\nWorstFit\nProcess\t\tMemoryBlock");
    for(i=0;i<noProcesses;i++)
    {
        int high=-1;
        for(j=0;j<noMemoryBlock;j++)
            if(processMemory[i]<=memory[j])
                if(memory[high]<memory[j] || high == -1)
                    high = j;
        if(high != -1)
        {
            memory[high]-=processMemory[i];
            printf("\n%d\t\t%d",i+1,high+1);
        }
        else
        {
            printf("Cant allocate further");
            return;
        }
    }
}
void fnBestFit(int memory[100])
{
    int i,j;
    printf("\nBestFit\nProcess\t\tMemoryBlock");
    for(i=0;i<noProcesses;i++)
    {
        int low=-1;
        for(j=0;j<noMemoryBlock;j++)
            if(processMemory[i]<=memory[j])
                if(memory[low]>memory[j] || low == -1)
                    low = j;
        if(low != -1)
        {
            memory[low]-=processMemory[i];
            printf("\n%d\t\t%d",i+1,low+1);
        }
        else
        {
            printf("Cant allocate further");
            return;
        }
    }
}
void restore()
{
    int i;
    for(i=0;i<noMemoryBlock;i++)
        memory[i]=tempMemory[i];
}
int main()
{
    int i, choice;
    printf("\nEnter the total number of memory blocks and number requested processes:");
    scanf("%d%d",&noMemoryBlock, &noProcesses);
    printf("\nEnter the size of memory block:\n");
    for(i=0;i<noMemoryBlock;i++)
        scanf("%d",&tempMemory[i]);
    printf("\nEnter the size of memory requested by process:\n");
    for(i=0;i<noProcesses;i++)
        scanf("%d",&processMemory[i]);
    while(1)
    {
        printf("\nEnter 1:FirstFit, 2.BestFit, 3. WorstFit\nEnter your choice:");
        scanf("%d",&choice);
        restore();
        if(choice == 1) fnFirstFit(memory);
        else if(choice == 2) fnBestFit(memory);
        else if(choice == 3) fnWorstFit(memory);
        else exit(0);
    }
}
