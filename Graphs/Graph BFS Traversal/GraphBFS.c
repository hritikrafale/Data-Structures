#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"

struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int num_of_vertices;
    int *visited;
    struct AdjList *array;
};

struct AdjListNode* createAdjListNode(int dest);
struct Graph* createGraph(int V);
void addEdge(struct Graph *graph,int src,int dest);
void printGraph(struct Graph *graph);
void BFS(struct Graph *graph,int ind);

int main()
{
    int V=5;

    struct Graph *graph=createGraph(5);

    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 

    printGraph(graph);

    printf("\nBreath first Traversal of the graph:\n");

    BFS(graph,0);

    return 0;
}

struct AdjListNode* createAdjListNode(int dest)
{
    struct AdjListNode *newnode=(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newnode->dest=dest;
    newnode->next=NULL;
    return newnode;
}

struct Graph *createGraph(int V)
{
    struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));

    graph->num_of_vertices=V;

    graph->array=(struct AdjList*)malloc(sizeof(struct AdjList)*V);
   
    graph->visited=(int*)malloc(sizeof(int)*V);

    for(int i=0;i<V;i++)
    {
        graph->array[i].head=NULL;

        graph->visited[i]=0;
    }
    
    return graph;
}

void addEdge(struct Graph *graph,int src,int dest)
{
    struct AdjListNode *newnode=createAdjListNode(dest);

    newnode->next=graph->array[src].head;
    graph->array[src].head=newnode;

    newnode=createAdjListNode(src);

    newnode->next=graph->array[dest].head;
    graph->array[dest].head=newnode;

}

void printGraph(struct Graph *graph)
{
    int i;

    graph->visited[0]=1;

    struct AdjListNode *temp;

    printf("\nAdjacency List for graph:-\n");

    for(i=0;i<graph->num_of_vertices;i++)
    {
        printf("\nhead");
        temp=graph->array[i].head;

        while(temp!=NULL)
        {
            printf(" ->%d",temp->dest);
            temp=temp->next;
        }
    }
}

void BFS(struct Graph *graph,int ind)
{
    graph->visited[ind]=1;

    struct Queue *queue=createQueue();

    enqueue(queue,ind);

    while(!isEmpty(queue))
    {
        ind=getFront(queue);

        printf("->%d",ind);

        dequeue(queue);

        struct AdjListNode *temp=graph->array[ind].head;

        while(temp)
        {
            if(graph->visited[temp->dest]==0)
            {
                graph->visited[temp->dest]=1;
                enqueue(queue,temp->dest);
            }
            temp=temp->next;
        }
    }
}    