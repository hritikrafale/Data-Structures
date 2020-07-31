#include<stdio.h>
#include<stdlib.h>

typedef struct myNode
{
  int data;
  struct myNode *left;
  struct myNode *right;
}Node;

Node* insert(Node *tree,int num);
void printTree(Node *tree);
int height(Node *tree);
int max(int num1,int num2);
int maxDepth(Node* node) ;
void longestPath(Node *tree,int max[]);

int main()
{
  Node *tree=NULL;
  int *max=(int*)malloc(sizeof(int));
  max[0]=0;
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
  printTree(tree);

  longestPath(tree,max);
  
  printf("\nDiameter of the tree is %d",max[0]);
  return 0;
}

Node* insert(Node *tree,int num)
{
  Node *temp=(Node*)malloc(sizeof(Node));
  temp->data=num;
  temp->right=temp->left=NULL;
  
  if(tree==NULL)
  	  tree=temp;
  else
  if(num>tree->data)
	  tree->right=insert(tree->right,num);
  else
  if(num<tree->data)
	  tree->left=insert(tree->left,num);
  	  		
  return tree;
}

void printTree(Node *tree)
{
  if(tree!=NULL)
  {
     printf(" %d ",tree->data);
     printTree(tree->left);
     printTree(tree->right);
  }
}

int max(int num1,int num2)
{
  if(num1>num2)
  	  return num1;
  else
      return num2;
}

int height(Node *tree)
{
  if(tree==NULL)
	  return 0;
  else
  if((tree->left==NULL)&&(tree->right==NULL))
  	  return 1;
  else
	  return 1+max(height(tree->right),height(tree->left));
}

void longestPath(Node *tree,int max[])
{
  if(tree==NULL)
	return;
  else
  {
     int temp;
     temp=height(tree->left)+height(tree->right)+1;
     if(temp>max[0])
         max[0]=temp;
     longestPath(tree->left,max);
     longestPath(tree->right,max);
  }
}

