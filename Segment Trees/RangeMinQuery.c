#include<stdio.h>

int calcSize(int n);
long long int min(long long int a,long long int b){return (a>b)?b:a;} 
long long int constructSegTree(long long int segtree[],long long int arr[],int start,int end,int index);
long long int getMin(long long int segtree[],int s_start,int s_end,int q_start,int q_end,int index);
void update(long long int segtree[],int size,int i,long long int diff);

int main()
{
    int n,m,i,size;

    scanf("%d %d",&n,&m);

    size=calcSize(n);

    long long int segtree[2*size-1],arr[size],v;

    for(i=0;i<n;i++)
        scanf("%lld",arr+i);

    for(;i<size;i++)
        arr[i]=1000000001;

    constructSegTree(segtree,arr,0,size-1,0);

    while(m--)
    {
        int task;
        scanf("%d",&task);
        if(task==1)
        {
            scanf("%d %lld",&i,&v);
            update(segtree,size,i,v-arr[i]);
            arr[i]=v;
        }   
        else
        {
            int l,r;
            scanf("%d %d",&l,&r);
            printf("%lld\n",getMin(segtree,0,size-1,l,r-1,0));
        }
    }

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
    if(start == end)
    {
        segtree[index]=arr[start];
        return segtree[index];
    }
    int mid=(start+end)/2;

    segtree[index]=min(constructSegTree(segtree,arr,start,mid,2*index+1),constructSegTree(segtree,arr,mid+1,end,2*index+2));
    return segtree[index];
}

long long int getMin(long long int segtree[],int s_start,int s_end,int q_start,int q_end,int index)
{
    if(s_start>q_end || q_start>s_end)
    {
        return 1000000001;
    }
    else
    if(s_start>=q_start && q_end>=s_end)
    {
        return segtree[index];
    }
    int mid=(s_start+s_end)/2;

    return min(getMin(segtree,s_start,mid,q_start,q_end,2*index+1),getMin(segtree,mid+1,s_end,q_start,q_end,2*index+2));
}

void update(long long int segtree[],int size,int i,long long int diff)
{
    int index=(2*size-1)-(size-i);

    segtree[index]+=diff;

    while(index!=0)
    {
        index=(index%2==0)?(index-2)/2:index/2;
        segtree[index]=min(segtree[2*index+1],segtree[2*index+2]);
    }
}
