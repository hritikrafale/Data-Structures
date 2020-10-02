#include<stdio.h>

void initialize(int parent[],int rank[],int size);       //function prototypes
void unions(int parent[],int rank[],int x,int y);
int find(int parent[],int x);

int main(){
	int size,x,y,choice,i;
	
	printf("\nEnter the total number of elements : ");
	scanf("%d",&size);
	
	int parent[size],rank[size];
	
	initialize(parent,rank,size);
	
	while(1){
		printf("\n----------MENU----------");
		printf("\n1.Union");
		printf("\n2.Find");
		printf("\n3.Print parent array");
		printf("\n4.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1 : printf("\nEnter the first element:");
					 scanf("%d",&x);
					 printf("\nEnter the second element:");
					 scanf("%d",&y);
					 unions(parent,rank,x,y);
					 break;	
					 
			case 2:  printf("\nEnter the element:");
					 scanf("%d",&x);
					 printf("\nParent is : %d",find(parent,x));
					 break;	
					 
			case 3:  printf("\nParent array is:");
					 for(i=0;i<size;i++){
					 	printf("%d ",parent[i]);
					 }	
					 break;
					 
			case 4: exit(0);		 
					 
			default : printf("\nYou have entered wrong choice pls enter again!!!!");
					  break;		 	 	 
		}
		
	}
	
	return 0;
}

void initialize(int parent[],int rank[],int size){
	int i;
	
	for(i=0;i<size;i++){
		parent[i]=i;
		rank[i]=0;
	}
}

void unions(int parent[],int rank[],int x,int y){
	int x_rep,y_rep;
	
	x_rep=find(parent,x);
	y_rep=find(parent,y);
	
	if(x_rep == y_rep)
		return;
		
		
	if(rank[x_rep]<rank[y_rep]){
		parent[y_rep]=y_rep;
	}
	else if(rank[x_rep]>rank[y_rep]){
		parent[x_rep]=y_rep;
	}
	else{
		parent[y_rep] = x_rep;
        rank[x_rep]++;
	}
}

int find(int parent[],int x){
	if(parent[x]==x){
		return x;
	}
	else{
		return find(parent,parent[x]);
	}
}

