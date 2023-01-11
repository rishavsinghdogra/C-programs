#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct node 
{
    int data; 
    struct node *left;
    struct node *right;
};

// Function to create a binary tree
struct node * givetree()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    
    // Read the data for the node
    scanf("%d",&newnode->data);
    
    // If the data is -1, return null
    if(newnode->data == -1)
    return NULL;
    
    // Recursively create the left and right subtrees
    printf("\nEnter left of %d  (-1 for nothing) : ",newnode->data);
    newnode->left = givetree(); 

    printf("\nEnter right of %d  (-1 for nothing) : ",newnode->data);
    newnode->right = givetree();     
    
    return newnode;
}

// Function to perform in-order traversal of the tree
void inorder(struct node * root)
{
	if(root == NULL)
	return;
	
	inorder(root->left);
	
	printf("%d ",root->data);

	inorder(root->right);
	
}

// Function to perform pre-order traversal of the tree
void preorder(struct node* root)
{
	if(root == NULL)
	return;
    
    printf("%d ",root->data);
    
	preorder(root->left);
	preorder(root->right);
}

// Function to perform post-order traversal of the tree
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
	
	// Example Input
	// 7 4 8 -1 -1 4 -1 -1 10 1 -1 -1 12 -1 -1
	
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