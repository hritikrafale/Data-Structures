/*In this problem we will be given a matrix mxn where all the elements are only 0 or 1. We need to find the number of distinct rows present in the matrix and output it

Sample Test Case:-
-----------------

[ [ 1 , 0 , 0 ] ,
  [ 0 , 1 , 0 ] ,
  [ 1 , 0 , 0 ] ,
  [ 0 , 1 , 0 ] ]
  
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TrieNode{
	struct TrieNode *children[2];
};

struct TrieNode* createTrieNode();
int calDistinctRows(struct TrieNode *root,int row,int column,int mat[][column]);
bool insert(struct TrieNode *root,int column,int matrix[][column],int index);

int main(){
	struct TrieNode *root=createTrieNode();
	
	int i,j,row,column;
	
	printf("\nEnter the size of the matrix :");
	scanf("%d %d",&row,&column);
	
	int matrix[row][column];
	
	printf("\nEnter the elements in the matrix : ");
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
	
	printf("\nNumber of distinct rows in a matrix : %d",calDistinctRows(root,row,column,matrix));
	
	return 0;
}  
  
struct TrieNode* createTrieNode(){
	struct TrieNode *root=(struct TrieNode *)malloc(sizeof(struct TrieNode));
	
	int i;
	
	for(i=0;i<2;i++){
		root->children[i]=NULL;
	}
	
	return root;
}

int calDistinctRows(struct TrieNode *root,int row,int column,int mat[][column]){
	int i,result=0;
	
	for(i=0;i<row;i++){
		if(insert(root,column,mat,i))
			result++;
	}
	
	return result;
}

bool insert(struct TrieNode *root,int column,int matrix[][column],int index){
	struct TrieNode *temp=root;
	
	int i;
	
	bool flag=false;
	
	for(i=0;i<column;i++){
		int ind=matrix[index][i];
		
		if(temp->children[ind]==NULL){
			temp->children[ind]=createTrieNode();
			flag=true;
		}
		
		temp=temp->children[ind];
	}
	
	return flag;
}
