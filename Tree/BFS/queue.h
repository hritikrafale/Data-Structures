typedef struct myNode
{
	int ele;
	struct myNode *left;
	struct myNode *right;
}Node;

struct QueueNode
{
	Node *data;
	struct QueueNode *next;
};

struct Queue
{
	struct QueueNode *front;
    struct QueueNode *rear;
};

struct Queue* createQueue();
struct QueueNode* createQueueNode(Node *data);
void enqueue(struct Queue* queue,Node *data);
void dequeue(struct Queue* queue);

struct Queue* createQueue()
{
	struct Queue *temp=(struct Queue*)malloc(sizeof(struct Queue));
	temp->front=temp->rear=NULL;
	return temp;
}

struct QueueNode* createQueueNode(Node *data)
{
	struct QueueNode *newNode=(struct QueueNode*)malloc(sizeof(struct QueueNode));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

void enqueue(struct Queue* queue,Node *data)
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


