#include<stdio.h>
#include<string.h>

void addEdge(int V,int graph[][V],int src,int dest,int weight);
void printGraph(int V,int graph[][V]);
int minDistance(int V,int dist[],int set[]);
void dijikstra(int V,int graph[][V],int src);

int main()
{
    int V=5;

    //int graph[5][5]={0};

    int graph[V][V];

    memset(graph,0,sizeof(graph));

/*
    int graph[9][9]= {{ 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                     { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                     { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                     { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                     { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                     { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                     { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                     { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                     { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
                    }; */

    addEdge(V,graph, 0, 1,6); 
    addEdge(V,graph, 0, 4,3); 
    addEdge(V,graph, 1, 2,8); 
    addEdge(V,graph, 1, 3,2); 
    addEdge(V,graph, 1, 4,5); 
    addEdge(V,graph, 2, 3,6); 
    addEdge(V,graph, 3, 4,3); 

    printGraph(V,graph);

    dijikstra(V,graph,0);

    return 0;
}

void addEdge(int V,int graph[][V],int src,int dest,int weight)
{
    graph[src][dest]=weight;
    graph[dest][src]=weight;
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

int minDistance(int V,int dist[],int set[])
{
    int min=10000,pos=-1,i;

    for(i=0;i<V;i++)
    {
        if(set[i]==0 && dist[i]<=min)
        {
            min=dist[i];
            pos=i;
        }
    }
    return pos;
}

void dijikstra(int V,int graph[][V],int src)
{
    int dist[V],set[V],min,i,j;

    for(i=0;i<V;i++)
    {
        dist[i]=10000;
        set[i]=0;
    }

    dist[src]=0;

    for(i=0;i<V-1;i++)
    {   
        min=minDistance(V,dist,set);
      
        set[min]=1;

        for(j=0;j<V;j++)
        {
            if(set[j]==0 && graph[min][j]!=0 && dist[min]!=10000 && dist[min]+graph[min][j]<dist[j])
            {
                dist[j]=dist[min]+graph[min][j];
            }
        } 
    }

    for(i=0;i<V;i++)
    {
        printf("\nDistance from 0 to vertex %d : %d",i,dist[i]);
    }
}