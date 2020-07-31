#include<stdio.h>
#include<stdlib.h>
#define INT_MAX -1

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack* createStack();
int isEmpty(struct Stack *stack);
int isFull(struct Stack *stack);
void doubleStack(struct Stack *stack);
void push(struct Stack *stack,int data);
int  pop(struct Stack *stack);

int main()
{
    struct Stack *stack=createStack();

    int choice,data;

    while(1)
    {
        printf("\n\t\t----------MENU----------");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Exit");

        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter the data you wish to push:");
                    scanf("%d",&data);
                    push(stack,data);
                    break;

            case 2: printf("\n%d is deleted!!!",pop(stack));
                    break;

            case 3: exit(0);

            default: printf("\nYou have entered wrong choice.Please enter again!!!");                
        }
    }

    return 0;
}

struct Stack* createStack()
{
    struct Stack *stack=(struct Stack*)malloc(sizeof(struct Stack));

    stack->top=-1;
    stack->capacity=1;
    stack->array=(int*)malloc(stack->capacity*sizeof(int));

    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top==-1;
}

int isFull(struct Stack *stack)
{
    return stack->top==stack->capacity-1;
}

void doubleStack(struct Stack *stack)
{
    stack->capacity=stack->capacity*2;
    stack->array=realloc(stack->array,stack->capacity*sizeof(int));
}

void push(struct Stack *stack,int data)
{
    if(isFull(stack))
        doubleStack(stack);

    stack->array[++stack->top]=data;    
}

int pop(struct Stack *stack)
{
    if(isEmpty(stack))
    {
        printf("\nStack Underflow!!!\n");
        return INT_MAX;
    }

    return stack->array[stack->top--];
}