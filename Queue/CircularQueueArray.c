#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5

struct Queue
{
    int front;
    int rear;
    int capacity;
    int *array;
};

struct Queue *createQueue();
int isEmpty(struct Queue *queue);
int isFull(struct Queue *queue);
void enqueue(struct Queue *queue,int data);
int dequeue(struct Queue *queue);

int main()
{
    struct Queue *queue=createQueue();

    int choice,data;

    while(1)
    {
        printf("\n\t\t----------MENU----------");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Exit");

        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter the data you wish to push:");
                    scanf("%d",&data);
                    enqueue(queue,data);
                    break;

            case 2: printf("\n%d is deleted!!!",dequeue(queue));
                    break;

            case 3: exit(0);

            default: printf("\nYou have entered wrong choice.Please enter again!!!");                
        }
    }

    return 0;
}

struct Queue *createQueue()
{
    struct Queue *queue=(struct Queue*)malloc(sizeof(struct Queue));

    queue->capacity=MAXSIZE;
    queue->front=queue->rear=-1;
    queue->array=(int*)malloc(queue->capacity*sizeof(int));

    return queue;
}

int isEmpty(struct Queue *queue)
{
    return queue->front==-1;
}

int isFull(struct Queue *queue)
{
    return (queue->rear+1)%queue->capacity==queue->front;
}

void enqueue(struct Queue *queue,int data)
{
    if(isFull(queue))
    {
        printf("\nQueue Overflow!!");
    }
    else
    {
        queue->rear=(queue->rear+1)%queue->capacity;
        queue->array[queue->rear]=data;
        if(queue->front==-1)
            queue->front=queue->rear;
    }
}

int dequeue(struct Queue *queue)
{
    if(isEmpty(queue))
    {
        printf("\nQueue Underflow!!");
        return 0;
    }
    else
    {
        int data=queue->array[queue->front];
        if(queue->front==queue->rear)
            queue->front=queue->rear=-1;
        else
            queue->front=(queue->front+1)%queue->capacity;
        return data;    
    }
}