/*
	Linked List ADT implementation

	It will contain every required functions.
*/

#include<stdio.h>          				//header files
#include<stdlib.h>

struct LinkedList						//structure declaretion for LinkedList
{
	int data;							//structure contains a integer element
	struct LinkedList *next;			//structure contains a pointer to the struct LinkeList type
};


/*
	We are using here double pointers, reasons are:-

	1) If we don't do instead we send a single pointer the meaning of that will be 
	   we are just sending the head variable which contains the address of the first
	   node.

	   So than it will not work like call by reference so anything we change in the function 
	   won't be reflected.

	2) So if we send double pointer that will mean that we are sending a pointer two the head.
	   Therefore it will work like call by reference.

	   Main thing this double pointer should be done only when we are adjusting the head pointer.
	   Otherwise not needed.

	3) But it does not mean we need to always send double pointer. There is an alternative way
	   whenever we change the head pointer we can just return the head again like we normally do.   
*/

void insertBeg(struct LinkedList **head);  //function prototypes
void insertEnd(struct LinkedList **head);
void insertBetween(struct LinkedList **head,int key);
void deleteBeg(struct LinkedList **head);
void deleteEnd(struct LinkedList **head);
void deleteBetween(struct LinkedList **head,int key);
void displayLinkedList(struct LinkedList *head);

int main()                 				//main function
{
	struct LinkedList *head=NULL;       //creating a LinkedList head pointing to NULL 

	int choice,key;                         //variable decleration of type int

	while(1)
	{	
		printf("\n\t\t----------MENU----------\n");          //menu for ADT
		printf("\n1) Insert(beginning)\n");
		printf("2) Insert(End)\n");
		printf("3) Insert(Between)\n");
		printf("4) Delete(Beg)\n");
		printf("5) Delete(End)\n");
		printf("6) Delete(Between)\n");
		printf("7) Display list\n");
		printf("8) Exit\n");
		printf("\n\nEnter your choice:");
		
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: insertBeg(&head);
					break;

			case 2: insertEnd(&head);
					break;

			case 3: printf("\nEnter the key:");
					scanf("%d",&key);
					insertBetween(&head,key);
					break;

			case 4: deleteBeg(&head);
					break;

			case 5: deleteEnd(&head);
					break;

			case 6: printf("\nEnter the key that you want to delete:");
					scanf("%d",&key);
					deleteBetween(&head,key);
					break;

			case 7: displayLinkedList(head);
					break;	

			case 8: exit(0);			

			default: printf("\nYou have entered a wrong choice!!! Please enter again.");
					 break;
		}
	}

	return 0;
}

void insertBeg(struct LinkedList **head)              //function for insert in beginning
{
	struct LinkedList *newnode=(struct LinkedList*)malloc(sizeof(struct LinkedList));

	printf("\nEnter the data:");
	scanf("%d",&newnode->data);

	newnode->next=NULL;

	if(!newnode)
	{
		printf("\nMemory Error!!!");
		return;
	}
	else
	{
		if(*head==NULL)
		{
			*head=newnode;
		}
		else
		{
			newnode->next=*head;
			*head=newnode;
		}
	}	
}

void insertEnd(struct LinkedList **head)           //function to insert the node at end
{
	struct LinkedList *t,*newnode=(struct LinkedList*)malloc(sizeof(struct LinkedList));

	printf("\nEnter the data :");
	scanf("%d",&newnode->data);

	newnode->next=NULL;

	if(!newnode)
	{
		printf("\nMemory error!!!");
		return ;
	}
	else
	{
		if(*head==NULL)
		{
			*head=newnode;
		}
		else
		{
			t=*head;
			
			while(t->next!=NULL)
			{
				t=t->next;
			}

			t->next=newnode;
		}
	}
}

void insertBetween(struct LinkedList **head,int key)       //function to insert the node in between two existing node
{
	struct LinkedList *t,*newnode=(struct LinkedList*)malloc(sizeof(struct LinkedList));

	newnode->next=NULL;

	printf("\nEnter the data:");
	scanf("%d",&newnode->data);

	if(!newnode)
	{
		printf("\nMemory error!!!");
		return ;
	}
	else
	{
		if(*head==NULL)
		{
			*head=newnode;
		}
		else
		{
			t=*head;

			while(t->data!=key)
				t=t->next;

			newnode->next=t->next;
			t->next=newnode;
		}
	}
}

void deleteBeg(struct LinkedList **head)
{
	struct LinkedList *t;

	if(!*head)
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		t=*head;
		*head=(*head)->next;
		free(t);
	}	
}

void deleteEnd(struct LinkedList **head)
{
	struct LinkedList *t,*temp;

	if(!*head)
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		t=*head;

		while(t->next->next)
			t=t->next;

		temp=t->next;
		t->next=NULL;
		free(temp);
	}	
}

void deleteBetween(struct LinkedList **head,int key)
{

	struct LinkedList *t,*temp;

	if(!*head)
	{
		printf("\nList is empty");
		return;
	}
	else
	{
		t=*head;

		while(t->next->data!=key)
			t=t->next;

		temp=t->next;
		t->next=temp->next;
		temp->next=NULL;
		free(temp);
	}	
}

void displayLinkedList(struct LinkedList *head)   //function to display the list 
{
	struct LinkedList *t=head;

	printf("List is : ");

	while(t!=NULL)
	{
		printf(" %d",t->data);
		t=t->next;
	}
}

