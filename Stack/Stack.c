#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct Stack
{
	int data;
	struct Stack *next;
};

void push(struct Stack **top,int data);
void pop(struct Stack **top);
int isEmpty(struct Stack *top);
int stackSize(struct Stack *top);
int printStack(struct Stack *top);

int main()
{
	struct Stack *top=NULL;

	int choice,data;

	while(1)
	{
		printf("\t\t\n----------MENU----------\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Print Stack\n");
		printf("4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: printf("\nEnter the data:");
					scanf("%d",&data);
					push(&top,data);
					printf("\n");
					break;

			case 2: pop(&top);
					printf("\n");
					break;

			case 3: printStack(top);
					printf("\n");
					break;

			case 4: exit(0);
					
			default: printf("\nYou have entered a wrong choice.Pls enter again!!");						
		}

	}

	return 0;
}

int isEmpty(struct Stack *top)
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

int isFull(struct Stack *top)
{
	if(stackSize(top)==MAX)
		return 1;
	else
		return 0;
}

void push(struct Stack **top,int data)
{
	struct Stack *newnode=(struct Stack*)malloc(sizeof(struct Stack));

	newnode->data=data;
	newnode->next=NULL;

	if(isFull(*top))
	{
		printf("\nStack Overflow!!!");
		return;
	}

	if(isEmpty(*top))
	{
		*top=newnode;
	}
	else
	{
		newnode->next=(*top);
		*top=newnode;
	}
}

void pop(struct Stack **top)
{
	struct Stack *t;

	if(isEmpty(*top)==1)
	{
		printf("\nStack Underflow!!!");
		return ;
	}
	else
	{
		t=*top;
		*top=(*top)->next;
		printf("\nDeleted data is : %d\n",t->data);
		free(t);
	}
}

int stackSize(struct Stack *top)
{
	int count=0;

	struct Stack *t=top;

	if(top==NULL)
	{
		return 0;
	}
	else
	{
		while(t)
		{
			count++;
			t=t->next;
		}
		return count;
	}
}

int printStack(struct Stack *top)
{
	struct Stack *current=top;

	if(isEmpty(top))
	{
		printf("\nStack Underflow!!!");
	}
	else
	{
		printf("\nStack is  :");
		while(current)
		{
			printf("%d ",current->data);
			current=current->next;
		}
	}
	printf("\n\n");
}