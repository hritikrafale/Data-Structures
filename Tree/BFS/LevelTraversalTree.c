#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

Node* insert(Node *tree,int num);
void printLevelOrder(Node *tree);

int main()
{
	Node *tree=NULL;

	int n,i,num;
	printf("\nEnter the number of values you want to insert?");
	scanf("%d",&n);
  
	for(i=0;i<n;i++)
	{	
		printf("\nEnter the number you want to insert:");
		scanf("%d",&num);
		tree=insert(tree,num);
    }
    printf("\n");
    printLevelOrder(tree);

    return 0;
}

Node* insert(Node *tree,int num)
{
	Node *temp=(Node*)malloc(sizeof(Node));
	temp->ele=num;
	temp->right=temp->left=NULL;
  
	if(tree==NULL)
  		tree=temp;
	else
		if(num>tree->ele)
			tree->right=insert(tree->right,num);
    	else
    		if(num<tree->ele)
	    		tree->left=insert(tree->left,num);
  	  		
    return tree;
}

void printLevelOrder(Node *tree)
{
	struct Queue *temp=createQueue();
    
    enqueue(temp,tree);
    printf("\nLevel Order traversal:");
    while(temp->front!=NULL)
    {
    	Node *temp1=temp->front->data->left;
    	Node *temp2=temp->front->data->right;
    	if(temp1!=NULL)
    	{
    		enqueue(temp,temp1);
    	}	
    	if(temp2!=NULL)
    	{
    		enqueue(temp,temp2);
    	}
    	printf(" %d ",temp->front->data->ele);
    	dequeue(temp);
    }
}

int maxSumLevel(Node *tree,int max)
{
  if()
}

