#include<stdio.h>

void constructBITree(int bit[],int arr[],int n);
void update(int bit[],int index,int n,int value);
int getSum(int bit[],int index);

int main(){
	int n,i; //variable decleration
	
	printf("\nEnter the size of the array:");
	scanf("%d",&n);
	
	int arr[n],bit[n+1];  //arr decleration
	
	printf("\nEnter the data:");
	for(i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	
	constructBITree(bit,arr,n);  //function for constructing the binary indexed tree
	
	printf("\nPrinting the binary indexed tree:");
	for(i=0;i<n+1;i++){
		printf("%d ",*(bit+i));
	}
	
	
	printf("\nPrefix sum of first 5 is : %d",getSum(bit,5));
	
	update(bit,2,n,5);
	
	printf("\nUpdated bit array is:");
	for(i=0;i<n+1;i++){
		printf("%d ",*(bit+i));
	}
	
	printf("\nPrefix sum of first 5 is : %d",getSum(bit,5));
	
	return 0;
}

void constructBITree(int bit[],int arr[],int n){
	int i;
	
	for(i=0;i<n+1;i++){
		bit[i]=0;
	}
	
	for(i=0;i<n;i++){
		update(bit,i,n,arr[i]);
	}
}

void update(int bit[],int index,int n,int value){
	index+=1;
	
	while(index<=n){
		bit[index]+=value;
		
		index+=index & (-index);
	}
}

int getSum(int bit[],int index){
	int result=0;
	
	index+=1;
	
	while(index>0){
		result+=bit[index];
	
		index-=index & (-index);
	}
	
	return result;
}
