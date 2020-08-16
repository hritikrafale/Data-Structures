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
int getFront(struct Queue* queue);
int isEmpty();

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
	    	free(temp);
	}
}

int getFront(struct Queue* queue)
{
    return queue->front->data;
}

int isEmpty(struct Queue *queue)
{
    if(queue->front==NULL)
        return 1;
    return 0;    
}