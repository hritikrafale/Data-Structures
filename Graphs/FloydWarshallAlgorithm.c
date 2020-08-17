#include<stdio.h>
#define INF 99999 

void floydWarshall(int V,int graph[][V]);
void printSolution(int V,int graph[][V],int dist[][V]);

int main()
{
    int V=4;

    int graph[4][4] = { {0,   5,  INF, 10}, 
                        {INF, 0,   3, INF}, 
                        {INF, INF, 0,   1}, 
                        {INF, INF, INF, 0} 
                      }; 

    floydWarshall(V,graph);

    return 0;
}

void printSolution(int V,int graph[][V],int dist[][V])
{
    int i,j;

    printf("\nNumber of vertices : %d",V);

    printf("\nGraph :-\n\n");

    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if(graph[i][j]==INF)
                printf("INF ");
            else
                printf("%d   ",graph[i][j]);
        }
        printf("\n");
    }

    printf("\nShortest distance from each node to other node is:-\n\n");

    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            if(dist[i][j]==INF)
                printf("INF ");
            else
                printf("%d   ",dist[i][j]);
        }
        printf("\n");
    }

}

void floydWarshall(int V,int graph[][V])
{
    int i,j,k,dist[V][V];

    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            dist[i][j]=graph[i][j];
        }
    }

    for(k=0;k<V;k++)
    {
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }    
            }
        }
    }

    printSolution(V,graph,dist);
}