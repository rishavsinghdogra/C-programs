#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data; 
    struct node *left;
    struct node *right;
};

struct node * givetree()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    int choice; 
    
    scanf("%d",&newnode->data);
    
    if(newnode->data == -1)
    return NULL;
    
    printf("\nEnter left of %d  (-1 for nothing) : ",newnode->data);
    newnode->left = givetree(); 

    printf("\nEnter right of %d  (-1 for nothing) : ",newnode->data);
    newnode->right = givetree();     
    
    return newnode;
}

void inorder(struct node * root)
{
	if(root == NULL)
	return;
	
	inorder(root->left);
	
	printf("%d ",root->data);

	inorder(root->right);
	
}

void preorder(struct node* root)
{
	if(root == NULL)
	return;
    
    printf("%d ",root->data);
    
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node* root)
{
	if(root == NULL)
	return;
	
	postorder(root->left);
	postorder(root->right);

	printf("%d ",root->data);
}



int main() {
	
	struct node * root;
	
	//7 4 8 -1 -1 4 -1 -1 10 1 -1 -1 12 -1 -1
	
	/*
		 7 
		/ \
	  4    10
    /  \  /  \
   8    4 1   12
   
   
	*/
	printf("\nEnter data : ");
	
	root = givetree();

    printf("\nThe preorder traversal of this tree is : ");        //7 4 8 4 10 1 12      
    preorder(root);

	printf("\nThe ineorder traversal of this tree is : ");       //8 4 4 7 1 10 12
    inorder(root);	

	printf("\nThe postorder traversal of this tree is : ");     //8 4 4 1 12 10 7 
    postorder(root);

	
	return 0;
}