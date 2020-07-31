#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createTreeNode(int data);
void insert(struct TreeNode **root,int data);
void inOrder(struct TreeNode *root);
void postOrder(struct TreeNode *root);
void preOrder(struct TreeNode *root);
void delete(struct TreeNode **root,int data);
struct TreeNode* findMax(struct TreeNode *root);


int main()
{
    struct TreeNode *root=NULL;

    int n,data,i,choice;

    /*while(1)
    {
        printf("\n\t\t----------MENU----------");
        printf("\n1.Insert");
        printf("\n2.Post Order Display");
        printf("\n3.Pre Order Display");
        printf("\n4.Inorder Display");
        printf("\n5.Delete an element");
        printf("\n6.Exit");
        printf("\n\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter the data you want to insert:");
                    scanf("%d",&data);
                    insert(&root,data);
                    printf("\n");
                    break;

            case 2: printf("\nPostorder traversal of tree is : ");
                    postOrder(root);
                    printf("\n");
                    break;

            case 3: printf("\nPreorder traversal of tree is : ");
                    preOrder(root);
                    printf("\n");
                    break;

            case 4: printf("\nInorder traversal of tree is : ");
                    inOrder(root);
                    printf("\n");
                    break;

            case 5: printf("\nEnter the data you want to insert:");
                    scanf("%d",&data);
                    delete(&root,data);
                    break;

            case 6: exit(0);        

            default: printf("\nYou have selected wrong choice.Please enter again!!!");                                
        }

    }*/

    insert(&root,10);
    insert(&root,15);
    insert(&root,5);
    insert(&root,3);
    insert(&root,2);
    insert(&root,1);
    insert(&root,4);
    insert(&root,7);
    insert(&root,6);
    insert(&root,8);
    insert(&root,13);
    insert(&root,12);
    insert(&root,14);
    insert(&root,17);
    insert(&root,16);
    insert(&root,20);
    
    printf("\nInorder Traversal:\n");
    inOrder(root);

    delete(&root,1);
    
inOrder(root);

    return 0;
}

struct TreeNode* createTreeNode(int data)
{
    struct TreeNode *newnode=(struct TreeNode*)malloc(sizeof(struct TreeNode));

    newnode->data=data;
    newnode->right=newnode->left=NULL;

    return newnode;
}

void insert(struct TreeNode **root,int data)
{
    struct TreeNode *newnode=createTreeNode(data);

    if(*root==NULL)
    {
        *root=newnode;
        return;
    }
    else
    {
        if(data>(*root)->data)
        {
            insert(&((*root)->right),data);
            return;
        }
        else
        if(data<(*root)->data)
        {
            insert(&((*root)->left),data);
            return;
        }
    }
}

void preOrder(struct TreeNode *root)
{
    if(root)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct TreeNode *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

void inOrder(struct TreeNode *root)
{
    if(root)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }

}

struct TreeNode* findMax(struct TreeNode *root)
{
    if(root==NULL)
        return NULL;
    else
    if(root->right==NULL)
        return root;
    else
       return findMax(root->right);
}

void delete(struct TreeNode **root,int data)
{
    struct TreeNode *temp;

    if(*root==NULL)
    {
        printf("\nThe tree is empty!!!");
    }
    else
    if(data>(*root)->data)
        delete(&((*root)->right),data);
    else
    if(data<(*root)->data)
        delete(&((*root)->left),data);
    else
    {
        if((*root)->right && (*root)->left)
        {
            temp=findMax((*root)->left);
            printf("\nTemp:%d\n",temp->data);
            (*root)->data=temp->data;
            delete(&((*root)->left),(*root)->data);
        }
        else
        {
            temp=*root;
            if((*root)->left==NULL)
                *root=(*root)->right;
            else    
            if((*root)->right==NULL)
                *root=(*root)->left;
            free(temp);    
        }
    }        
}
