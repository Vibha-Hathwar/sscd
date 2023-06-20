#include <stdio.h>
#include <limits.h>

const int MAX = 10;
const int INF = INT_MAX;
void Dijkstra(int c[MAX][MAX], int d[MAX], int p[MAX], int s[MAX], int so, int de, int n)
{
    int i, j, a, b, min;
    for(i=0; i<n; i++){
        s[i] = 0;
        d[i] = c[so][i];
        p[i] = so;
    }
    s[so] = 1;
    for(i=1; i<n; i++)
    {
        min = INF;
        a = -1;
        for(j=0; j<n; j++)
            if(s[j] == 0)
                if(d[j] < min)
                {
                    min = d[j];
                    a = j;
                }
        if(a == -1) return;
            s[a] = 1;
        if(a == de) return;
        for(b=0; b<n; b++)
            if(s[b] == 0)
                if(d[a] + c[a][b] < d[b]){
                    d[b] = d[a] + c[a][b];
                    p[b] = a;
               }
    }
}
int main(){
    int n;
    int cost[MAX][MAX];
    int dist[MAX];
    int visited[MAX];
    int path[MAX];
    int source, i, dest;
    printf("\nEnter the number of vertices : ");
    scanf("%d",&n);
    printf("\nEnter Cost matrix \n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&cost[i][j]);
    printf("\nEnter the number of source: ");
    scanf("%d",&source);
    printf("\nFor source vertex : %d, shortest path to other vertices\n",source);
    for(dest = 0; dest <n; dest++){
        Dijkstra(cost, dist, path, visited, source, dest, n);
        if(dist[dest] == INF)
            printf("\n%d not rechable",dest);
        else
        {
            printf("\n");
            i = dest;
            do
            {
                printf("%d<--",i);
                i = path[i];
            }while(i != source);
            printf("%d = %d\n",i,dist[dest]);
        }
    }
    printf("\n");
    return 0;
}
