#include<stdio.h>
#include<stdlib.h>

struct DoublyLinkedList
{
	int data;
	struct DoublyLinkedList *next;
	struct DoublyLinkedList *prev;	
};

void insertBeg(struct DoublyLinkedList **head,struct DoublyLinkedList **tail);
void insertEnd(struct DoublyLinkedList **tail);
void insertBetween(struct DoublyLinkedList **head,int key);
void deleteBeg(struct DoublyLinkedList **head,struct DoublyLinkedList **tail);
void deleteEnd(struct DoublyLinkedList **head,struct DoublyLinkedList **tail);
void deleteBetween();
void display(struct DoublyLinkedList *head);
void displayReverse(struct DoublyLinkedList *tail);

int main()
{
	struct DoublyLinkedList *head=NULL,*tail=NULL;

	int choice,key;

	while(1)
	{
		printf("\t\t----------MENU----------\n");
		printf("1. Insert Beginning\n");
		printf("2. Insert End\n");
		printf("3. Insert Between\n");
		printf("4. Delete Beginning\n");
		printf("5. Delete End\n");
		printf("6. Display\n");
		printf("7. Display Reverse\n");
		printf("8. Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: insertBeg(&head,&tail);
					break;

			case 2: insertEnd(&tail);
					break;

			case 3: printf("\nEnter the key:");
					scanf("%d",&key);
					insertBetween(&head,key);
					break;

			case 4: deleteBeg(&head,&tail);
					break;

			case 5: deleteEnd(&head,&tail);
					break;		

			case 6: display(head);
					break;		

		    case 7: displayReverse(tail);
		    		break;

			case 8: exit(0);
			
			default: printf("\nYou have entered wrong choice. Please enter again!!!");		
		}
	}

	return 0;
}

void insertBeg(struct DoublyLinkedList **head,struct DoublyLinkedList **tail)
{
	struct DoublyLinkedList *newnode=(struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));

	printf("\nEnter the data:");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;

	if((*head)==NULL)
	{
		*head=newnode;
		*tail=newnode;
	}
	else
	{
		newnode->next=*head;
		(*head)->prev=newnode;
		*head=newnode;
	}
}

void insertEnd(struct DoublyLinkedList **tail)
{
	struct DoublyLinkedList *newnode=(struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));

	printf("\nEnter the data:");
	scanf("%d",&newnode->data);
	
	newnode->next=NULL;
	newnode->prev=NULL;

	if((*tail)==NULL)
	{
		printf("\nPlease insert a node using Insert Beginning option!!");
	}
	else
	{
		newnode->prev=*tail;
		(*tail)->next=newnode;
		*tail=newnode;
	}

}

void insertBetween(struct DoublyLinkedList **head,int key)
{
	struct DoublyLinkedList *t,*newnode=(struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));

	printf("\nEnter the data:");
	scanf("%d",&newnode->data);
	
	newnode->next=NULL;
	newnode->prev=NULL;

	if(*head==NULL)
	{
		printf("\nPlease insert a node using Insert Beginning option!!");
	}
	else
	{
		t=*head;

		while(t->data!=key)
			t=t->next;

		newnode->prev=t;
		newnode->next=t->next;
		t->next->prev=newnode;
		t->next=newnode;
	}

}

void deleteBeg(struct DoublyLinkedList **head,struct DoublyLinkedList **tail)
{
	struct DoublyLinkedList *t;

	if(*head!=NULL && *head==*tail)
	{
		t=*head;
		*head=NULL;
		*tail=NULL;
		free(t);
	}
	else
	{
		t=*head;
		*head=(*head)->next;
		free(t);
	}
}

void deleteEnd(struct DoublyLinkedList **head,struct DoublyLinkedList **tail)
{
	struct DoublyLinkedList *t;

	if(*head!=NULL && *head==*tail)
	{
		t=*head;
		*head=NULL;
		*tail=NULL;
		free(t);
	}
	else
	{
		t=*tail;
		*tail=(*tail)->prev;
		(*tail)->next=NULL;
		free(t);
	}
}

void display(struct DoublyLinkedList *head)
{
	struct DoublyLinkedList *t=head;

	if(head==NULL)
	{
		printf("\nList is empty!!!");
	}
	else
	{
		printf("\n List is :");

		while(t)
		{
			printf("%d ",t->data);
			t=t->next;
		}
	}	
	printf("\n\n");
}

void displayReverse(struct DoublyLinkedList *tail)
{
	struct DoublyLinkedList *t=tail;

	if(tail==NULL)
	{
		printf("\nList is empty!!!");
	}
	else
	{
		printf("\n Reverse List is:");

		while(t)
		{	
			printf("%d ",t->data);
			t=t->prev;
		}
	}	
	printf("\n\n");
}