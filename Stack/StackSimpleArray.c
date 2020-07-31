#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define INT_MIN -1

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack();
int isEmpty(struct Stack *stack);
void push(struct Stack *stack,int data);
int pop(struct Stack *stack);

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

struct Stack *createStack()
{
    struct Stack *stack=(struct Stack*)malloc(sizeof(struct Stack));

    stack->capacity=MAX;
    stack->array=(int*)malloc(sizeof(int)*stack->capacity);
    stack->top=-1;

    return stack;
}

int isEmpty(struct Stack *stack)
{
    return (stack->top==-1);
}

int isFull(struct Stack *stack)
{
    return (stack->top==stack->capacity-1);
}

void push(struct Stack *stack,int data)
{
    if(isFull(stack))
    {
        printf("\nStack Overflow!!!");
    }
    else
    {
        stack->top++;
        stack->array[stack->top]=data;
    }   
}

int pop(struct Stack *stack)
{
    int element;

    if(isEmpty(stack))
    {
        printf("\nStack Underflow!!!");
        return INT_MIN;
    }
    else
    {
        element=stack->array[stack->top];
        stack->top--;
        return element;
    }
}