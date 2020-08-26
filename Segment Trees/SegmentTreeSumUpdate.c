#include<stdio.h>
#include<string.h>

int calcSize(int n);
long long int constructSegTree(long long int segtree[],long long int arr[],int start,int end,int index);
long long getSum(long long int segtree[],int s_start,int s_end,int q_start,int q_end,int index);
void update(long long int segtree[],int s_start,int s_end,int i,int index,long long int diff);

int main()
{
    int n,size,i,m;

    scanf("%d %d",&n,&m);

    size=calcSize(n);

    long long int segtree[(2*size)-1],arr[size];

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    
    for(;i<size;i++)
        arr[i]=0;

    memset(segtree,0,2*size-1);

    constructSegTree(segtree,arr,0,size-1,0);

    while(m--)
    {
        int task;

        scanf("%d",&task);

        if(task==1)
        {
            int i;
            long long int v;

            scanf("%d %lld",&i,&v);

            update(segtree,0,size-1,i,0,v-arr[i]);

            arr[i]=v;
        }
        else
        {
            int l,r;

            scanf("%d %d",&l,&r);
            printf("%lld\n",getSum(segtree,0,size-1,l,r-1,0));
        }
    }

    printf("\n");
    
    return 0;
}

int calcSize(int n)
{
    int size=1;
    while(size<n)size*=2;
    return size;
}

long long int constructSegTree(long long int segtree[],long long int arr[],int start,int end,int index)
{
    if(start==end)
    {
        segtree[index]=arr[start];
        return arr[start];
    }    
    int m=(end+start)/2;

    segtree[index]=constructSegTree(segtree,arr,start,m,2*index+1)+constructSegTree(segtree,arr,m+1,end,2*index+2);

    return segtree[index];
}

long long int getSum(long long int segtree[],int s_start,int s_end,int q_start,int q_end,int index)
{
    if(q_start > s_end || s_start > q_end)
    {
        return 0;
    }

    if(q_start <= s_start && q_end >= s_end)
    {
        return segtree[index];
    }
    
    int mid=(s_start+s_end)/2;

    return getSum(segtree,s_start,mid,q_start,q_end,2*index+1)+getSum(segtree,mid+1,s_end,q_start,q_end,2*index+2);
}

void update(long long int segtree[],int s_start,int s_end,int i,int index,long long int diff)
{
    if(i<s_start || i >s_end)
    {
        return;
    }
     
    segtree[index]=segtree[index]+diff;

    if(s_end>s_start)
    {
        int mid=(s_start+s_end)/2;
        update(segtree,s_start,mid,i,2*index+1,diff);
        update(segtree,mid+1,s_end,i,2*index+2,diff);
    }
}