#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct TrieNode{
	struct TrieNode *children[26];
	
	bool isEndOfWord;
};

//function prototypes
struct TrieNode* createTrieNode();
void insert(struct TrieNode *trie,char str[]);
bool search(struct TrieNode *trie,char str[]);
bool isEmpty(struct TrieNode *trie);
struct TrieNode* delete(struct TrieNode *trie , char str[],int i);

int main(){
	struct TrieNode *root=createTrieNode();

	int i,n;
	
	printf("\nEnter the number of strings : ");
	scanf("%d",&n);
	
	char str[n][10];
	
	printf("\nEnter all the strings : ");
	for(i=0;i<n;i++){
		scanf("%s",str[i]);
	}
	
	for(i=0;i<n;i++){
		insert(root,str[i]);
	}
	
	root=delete(root,"geek",0);
	
	if(root==NULL)
		printf("No trie");
	else	
		search(root,"geek")?printf("\nYes"):printf("\nNo");
		
	search(root,"geeks")?printf("\nYes"):printf("\nNo");	
	
	
	return 0;
}

struct TrieNode* createTrieNode(){
	int i;
	
	struct TrieNode *newnode=(struct TrieNode*)malloc(sizeof(struct TrieNode));
	
	newnode->isEndOfWord=false;
	
	for(i=0;i<26;i++){
		newnode->children[i]=NULL;
	}
}

void insert(struct TrieNode *trie,char str[]){
	struct TrieNode *pcrawl=trie;
	
	int i;
	
	for(i=0;i<strlen(str);i++){
		int index=str[i]-'a';
		
		if(pcrawl->children[index]==NULL){
			pcrawl->children[index]=createTrieNode();
		}
		
		pcrawl=pcrawl->children[index];
	}
	
	pcrawl->isEndOfWord=true;
}

bool search(struct TrieNode *trie,char str[]){
	struct TrieNode *pcrawl=trie;
	
	int i;
	
	for(i=0;i<strlen(str);i++){
		int index=str[i]-'a';
		
		if(pcrawl->children[index]==NULL){
			return false;
		}
		
		pcrawl=pcrawl->children[index];
	}
	
	return (pcrawl->isEndOfWord && pcrawl!=NULL);
}

bool isEmpty(struct TrieNode *trie){
	int i;
	
	for(i=0;i<26;i++){
		if(trie->children[i]!=NULL){
			return false;
		}
	}
	return true;
}

struct TrieNode* delete(struct TrieNode *trie , char str[],int i){
	bool flag=false;
	
	if(trie==NULL){
		return NULL;
	}
	
	if(i==strlen(str)){
		trie->isEndOfWord=false;
		if(isEmpty(trie)){
			//deleting the node
			free(trie);
			flag=true;
		}
		if(flag)
			return NULL;
		else
			return trie;	
	}
	
	int index=str[i]-'a';
	
	trie->children[index]=delete(trie->children[index],str,i+1);
	flag=false;
	if(isEmpty(trie)==true && trie->isEndOfWord==false){
		free(trie);
		flag=true;
	}
	
	if(flag)
		return NULL;
	else
		return trie;
}
