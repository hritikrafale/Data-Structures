#include<stdio.h>   //header file
 
int left(int ind);  //function prototype
int right(int ind);
void buildMaxHeap(int arr[],int len);
void maxHeapify(int arr[],int i,int heapsize);
void heapSort(int arr[],int len);

int main(){		//main function
	int len,i;
	
	printf("\nEnter the length of the array:");
	scanf("%d",&len);
	
	int arr[len];
	
	printf("\nEnter the array elements:");
	for(i=0;i<len;i++){
		scanf("%d",arr+i);
	}
	
	heapSort(arr,len);    
	
	printf("\nSorted array is:");
	for(i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	
	return 0;
}

int left(int ind){    //function to return left child index of an index
	return 2*ind+1;
}

int right(int ind){		//function to return right child index of an index
	return 2*ind+2;
}

void buildMaxHeap(int arr[],int len){      
	int heapsize=len,i;
	
	for(i=(len/2)-1;i>-1;i--){
		maxHeapify(arr,i,heapsize);
	}
}

void maxHeapify(int arr[],int i,int heapsize){
	int l,r,largest;
	
	l=left(i);
	r=right(i);
	
	if(l<heapsize && arr[l]>arr[i]){
		largest=l;
	}
	else{
		largest=i;
	}
	
	if(r<heapsize && arr[r]>arr[largest]){
		largest=r;
	}
	
	if(largest!=i){
		int temp;
		//swapping elements
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		
		maxHeapify(arr,largest,heapsize);
	}
	
}

void heapSort(int arr[],int len){
	int i,heapsize=len;
	
	buildMaxHeap(arr,len);
	
	for(i=len-1;i>-1;i--){
		int temp=arr[i];
		arr[i]=arr[0];
		arr[0]=temp;
		heapsize=heapsize-1;
		maxHeapify(arr,0,heapsize);
	}
}
