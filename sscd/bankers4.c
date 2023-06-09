//Write a C program to implement Bankers algorithm for the purpose of deadlock avoidance.
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 100

int N,R;
int allocation[SIZE][SIZE],max[SIZE][SIZE],need[SIZE][SIZE],available[SIZE],safeSequence[SIZE];;
bool finished[SIZE];

void getInputData()
{
    int i=0,j=0 ;
    printf("Enter number of processes : ");
    scanf("%d", &N);
    printf("Enter number of Resource types : ");
    scanf("%d", &R);
    printf("Enter Allocation matrix : \n");
    for (i = 0; i < N; i++)
        for (j = 0; j < R; j++)
            scanf("%d", &allocation[i][j]);
    printf("Enter Max matrix : \n");
    for (i = 0; i < N; i++)
        for (j = 0; j < R; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    printf("\n Need matrix: \n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<R;j++)
            printf("%d\n",need[i][j]);
        printf("\n");
    }
    printf("Enter Available array : \n");
    for (i = 0; i < R; i++)
        scanf("%d", &available[i]);
}
int getNextProcess(int work[], int current)
{
    int i =0,j = 0 ;
    for (i = 0 ; i < N ; i++ )
    {
        current = (current+1)%N ;
        if(finished[current]) continue ;
            bool flag = true;
        for (j = 0; j < N; j++)
            if (need[current][j] > work[j])
            {
                flag = false;
                break;
            }
        if (flag == false)
            continue;
        return current;
    }
    return -1;
}
bool findSafeSequence()
{
    int *work = available;
    int safeSequencePointer = 0;
    int current = -1 , i =0 ;
    while (true)
    {
        int next = getNextProcess(work, current);
        if (next < 0)
        {
            for (i = 0; i < N; i++)
                if (finished[i] == false)
                    return false;
            return true;
        }
        current = next;
        finished[next] = true;
        safeSequence[safeSequencePointer++] = next;
        for (i = 0; i < R; i++)
            work[i] += allocation[next][i];
    }
}
void displaySafeSequence()
{
    int i =0 ;
    printf("\nSafe Sequence is : \n");
    for (i = 0; i < N; i++)
        printf("P%d ", safeSequence[i]);
    printf("\n");
}
int main()
{
    getInputData();
    if (findSafeSequence() == true)
        displaySafeSequence();
    else
        printf("\nSo safe sequence exists !");
}
