#include<stdio.h>
#include<string.h>

int calcSize(int n);
int constructSegTree(int segtree[],int arr[],int start,int end,int index);

int main()
{
    int n,size,i;

    scanf("%d",&n);

    size=calcSize(n);

    int segtree[(2*size)-1],arr[size];

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    for(;i<size;i++)
        arr[i]=0;

    memset(segtree,0,2*size-1);

    constructSegTree(segtree,arr,0,size-1,0);

    printf("\nSegment tree is :");
    for(i=0;i<2*size-1;i++)
        printf("%d ",*(segtree+i));

    return 0;
}

int calcSize(int n)
{
    int size=1;
    while(size<n)size*=2;
    return size;
}

int constructSegTree(int segtree[],int arr[],int start,int end,int index){
    if(start==end)
    {
        segtree[index]=arr[start];
        return arr[start];
    }    
    int m=start+(end-start)/2;

    segtree[index]=constructSegTree(segtree,arr,start,m,2*index+1)+constructSegTree(segtree,arr,m+1,end,2*index+2);

    return segtree[index];
}