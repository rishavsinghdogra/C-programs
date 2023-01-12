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

int max(int a, int b) {return (a > b) ? a : b;}

// Function to find the maximum depth of the binary tree
int maxDepth(struct node* root){
   
   if(root == NULL)
   return -1;

   return max(maxDepth(root->left),maxDepth(root->right))+1;
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

        printf("\nThe height of this binary tree is : %d",maxDepth(root));

	
	return 0;
}
