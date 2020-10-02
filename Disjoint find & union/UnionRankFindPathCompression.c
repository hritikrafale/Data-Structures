#include<stdio.h>                                                                 //header files
#include<unistd.h>

 //function prototypes
void initialize(int parent[],int rank[],int size);  //This function is to initialize the parent and rank array                               
void unions(int parent[],int rank[],int x,int y);    // This function unions the two trees or we can say set better
int find(int parent[],int x);                       // This function finds the representative of the given element  

int main(){
	int size,i,choice,x,y;
	
	printf("\nEnter the number of elements :");         //Getting the number of elements in the set
	scanf("%d",&size);
	
	int parent[size],rank[size];
	
	initialize(parent,rank,size);                        //calling the initialize function to initialize both parent and rank arrays
	 
	while(1){                                              //menu of good user interface
		printf("\n----------MENU----------");
		printf("\n1.Union");
		printf("\n2.Find");
		printf("\n3.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: printf("\nEnter the first element : ");               
					scanf("%d",&x);
					printf("\nEnter the second element : ");
					scanf("%d",&y);
					unions(parent,rank,x,y);
					printf("\nParent array is : ");
					for(i=0;i<size;i++){
						printf("%d ",parent[i]);
					}
					break;
					
			case 2: printf("\nEnter the element : ");
					scanf("%d",&x);
					printf("\nParent of %d is : %d",x,find(parent,x));
					printf("\nParent array is : ");
					for(i=0;i<size;i++){
						printf("%d ",parent[i]);
					}
					break;		
					
			case 3: exit(0);
			
			default : printf("\nYou have entered a wrong choice please enter again !!!");
						
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

void unions(int parent[],int rank[],int x,int y){            //Working of union
	int x_rep,y_rep;                                        //This union uses rank array to reduce time complexity
	
	x_rep=find(parent,x);                                          //finding representatives of both elements
	y_rep=find(parent,y);
	
	if(x_rep==y_rep){                                       //If representatives of both elements are same then we just return since they are of same set already
		return;
	}
	
	if(rank[x_rep]>rank[y_rep]){                           // Whoosever rank is more we attach other set to this set therefore reducing height of tree
		parent[y_rep]=x_rep;
	} else if(rank[x_rep]<rank[y_rep]){
		parent[x_rep]=y_rep;
	} else {
		parent[y_rep]=x_rep;                               // If height are same then we can make anybody as child and parent and we increase the height of other
		rank[x_rep]++;
	}
}

int find(int parent[],int x){                              // In find we use path compression to reduce the height of the tree
	if(parent[x] == x){                                      // Basic idea of path compression is to attach any element to representative of the set
		return x;
	}
	
	parent[x]=find(parent,parent[x]);
	
	return parent[x];
}

