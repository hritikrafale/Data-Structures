#include<stdio.h>
#include<stdlib.h>

struct CircularLinkedList
{
	int data;
	struct CircularLinkedList *next;
};

void insertBeg(struct CircularLinkedList **head);
void insertEnd(struct CircularLinkedList **head);
void display(struct CircularLinkedList *head);

int main()
{
	struct CircularLinkedList *head=NULL;

	int choice;

	while(1)
	{
		printf("\t\t----------MENU----------\n\n");
		printf("1.Insert(Beginning)\n");
		printf("2.Insert(End)\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: insertBeg(&head);
					break;

		    case 2: insertEnd(&head);
		    		break;

			case 3:display(head);
					break;

			case 4: exit(0);
			
			default:printf("\nYou have entered wrong choice.Please enter again!!");		
		}
	}

	return 0;
}

void insertBeg(struct CircularLinkedList **head)
{
	struct CircularLinkedList *t,*newnode=(struct CircularLinkedList*)malloc(sizeof(struct CircularLinkedList));

	printf("\nEnter the data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;

	if(*head==NULL)
	{
		*head=newnode;
		(*head)->next=*head;
	}
	else
	{
		newnode->next=*head;
		
		t=*head;

		while(t->next!=*head)
			t=t->next;

		t->next=newnode;

		*head=newnode;
	}
}

void insertEnd(struct CircularLinkedList **head)
{
	struct CircularLinkedList *t,*newnode=(struct CircularLinkedList*)malloc(sizeof(struct CircularLinkedList));

	printf("\nEnter the data:");
	scanf("%d",&newnode->data);
	newnode->next=*head;

	t=*head;

	while(t->next!=*head)
	{
		t=t->next;
	}

	t->next=newnode;
}

void display(struct CircularLinkedList *head)
{
	struct CircularLinkedList *t=head;

	printf("\nList is: ");

	if(head==NULL)
	{
		printf("\nList is empty!!");
	}
	else
	{
		do
		{
			printf("%d ",t->data);
			t=t->next;
		}while(t!=head);
	}
	printf("\n\n");
}