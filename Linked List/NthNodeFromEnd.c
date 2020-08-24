#include<stdio.h>
#include<stdlib.h>

struct LinkedList
{
    int data;
    struct LinkedList *next;
};

struct LinkedList *createLinkedListNode();
void initLinkedList(struct LinkedList **list);
void nNodeFromEnd(struct LinkedList *list,int n);
void printLinkedList(struct LinkedList *list);

int main()
{
    int n;

    struct LinkedList *list=NULL;

    initLinkedList(&list);

    printf("\nList is :");
    printLinkedList(list);
    printf("\n\n");

    printf("\nEnter the n Node :");
    scanf("%d",&n);

    nNodeFromEnd(list,n);

    return 0;
}

struct LinkedList *createLinkedListNode()
{
    struct LinkedList *newnode=(struct LinkedList*)malloc(sizeof(struct LinkedList));

    printf("\nEnter the data:");
    scanf("%d",&newnode->data);

    newnode->next=NULL;

    return newnode;
}

void initLinkedList(struct LinkedList **list)
{
    int num_of_inputs,i;

    printf("\nEnter the number of inputs:");
    scanf("%d",&num_of_inputs);

    for(i=0;i<num_of_inputs;i++)
    {
        struct LinkedList *newnode=createLinkedListNode();

        if(*list==NULL)
        {
            *list=newnode;
        }
        else
        {
            struct LinkedList *temp=*list;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }
}

void nNodeFromEnd(struct LinkedList *list,int n)
{
    struct LinkedList *start=list,*end=list;

    int i=1;

    while(i<=n)
    {
        if(end->next==NULL)
        {
            printf("\nNot possible!!!!");
            return;
        }
        else
        {
            end=end->next;
        }
        i++;
    }

    while(end)
    {
        end=end->next;
        start=start->next;
    }

    printf("\n%d th Node from the end is : %d\n\n",n,start->data);
}

void printLinkedList(struct LinkedList *list)
{
    struct LinkedList *temp=list;

    if(temp==NULL)
    {
        printf("\nList is empty!!!!");
    }
    else
    {
        while(temp)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
    }
}