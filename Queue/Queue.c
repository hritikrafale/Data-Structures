#include<stdio.h>
#include<stdlib.h>

struct QueueNode
{
	int data;
	struct QueueNode *next;
};

struct Queue
{
	struct QueueNode *front;
    struct QueueNode *rear;
};

struct Queue* createQueue();
struct QueueNode* createQueueNode(int data);
void enqueue(struct Queue* queue,int data);
void dequeue(struct Queue* queue);


int main()
{
	struct Queue *queue=NULL;

	queue=createQueue();

	enqueue(queue,5);
    enqueue(queue,55);
    enqueue(queue,45);
    enqueue(queue,35);
    enqueue(queue,25);
    enqueue(queue,15);
    dequeue(queue);
    dequeue(queue);
 
	printf("\n Queue's front key:%d ",queue->front->data);
    printf("\n Queue's rear key:%d ",queue->rear->data);

    return 0;
}

struct Queue* createQueue()
{
	struct Queue *temp=(struct Queue*)malloc(sizeof(struct Queue));
	temp->front=temp->rear=NULL;
	return temp;
}

struct QueueNode* createQueueNode(int data)
{
	struct QueueNode *newNode=(struct QueueNode*)malloc(sizeof(struct QueueNode));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

void enqueue(struct Queue* queue,int data)
{
	struct QueueNode *newNode=createQueueNode(data);

    if(queue->rear==NULL)
    {
    	queue->rear=queue->front=newNode;
    }
    else
    {
    	queue->rear->next=newNode;
    	queue->rear=newNode;
    }
}

void dequeue(struct Queue *queue)
{
	if(queue->rear==NULL)
	{
		printf("\nQueue is empty!!!!");
	}
	else
	{
		struct QueueNode *temp=queue->front;
		queue->front=queue->front->next;
	    if(queue->front==NULL)
	    {
	    	queue->rear=NULL;
	    }
	    else
	    {
	    	free(temp);
	    }
	}
}


