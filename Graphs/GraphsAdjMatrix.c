#include<stdio.h>

void addEdge(int V,int graph[][V],int src,int dest);
void printGraph(int V,int graph[][V]);

int main()
{
    int V=5;

    int graph[5][5]={0};

    addEdge(V,graph, 0, 1); 
    addEdge(V,graph, 0, 4); 
    addEdge(V,graph, 1, 2); 
    addEdge(V,graph, 1, 3); 
    addEdge(V,graph, 1, 4); 
    addEdge(V,graph, 2, 3); 
    addEdge(V,graph, 3, 4); 

    printGraph(V,graph);

    return 0;
}

void addEdge(int V,int graph[][V],int src,int dest)
{
    graph[src][dest]=1;
    graph[dest][src]=1;
}

void printGraph(int V,int graph[][V])
{
    int i,j;

    printf("\nGraph Adjacency Matrix:-\n");

    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}