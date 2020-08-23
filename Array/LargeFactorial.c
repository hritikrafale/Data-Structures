#include<stdio.h>

int multiply(int arr[],int i,int size);
void factorial(int num);

int main()
{
    int num_of_testcases;

    scanf("%d",&num_of_testcases);

    while(num_of_testcases--)
    {
        int num;

        scanf("%d",&num);

        factorial(num);
        printf("\n");
    }

    return 0;
}

void factorial(int num)
{
    int res[200],size=1,i,carry;

    res[0]=1;
    carry=0;

    for(i=2;i<=num;i++)
    {
        size=multiply(res,i,size);
    }    

    for(i=size-1;i>-1;i--)
    {
        printf("%d",res[i]);
    }
}

int  multiply(int arr[],int num,int size)
{
    int prod=arr[0],carry=0,i;

    for(i=0;i<size;i++)
    {
        prod=num*arr[i]+carry;
        arr[i]=prod%10;
        carry=prod/10;
    }

    while(carry>0)
    {
        size++;
        arr[size-1]=carry%10;
        carry/=10;
    }

    return size;
}