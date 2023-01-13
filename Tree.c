#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int data;
	struct node *left, *right;
};

struct node *givetree()
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	char choice;
	
	newnode->left = NULL;
	newnode->right = NULL;

	printf("Enter data : ");
	scanf("%d",&newnode->data);
	
	printf("\nWanna fill left of %d ? (y/n) : ",newnode->data);
	scanf(" %c",&choice);
	
	if(choice == 'y')
	newnode->left = givetree();
	
	printf("\nWanna fill right of %d ? (y/n) : ",newnode->data);
	scanf(" %c",&choice);	

	if(choice == 'y')
	newnode->right = givetree();
	
	return newnode;
	
}

void inorder(struct node * root)
{
	if(root->left != NULL)
	inorder(root->left);
	
	printf("%d ",root->data);
		
	if(root->right != NULL)
	inorder(root->right);
	
}

void preorder(struct node* root)
{
	printf("%d ",root->data);

	if(root->left != NULL)
	preorder(root->left);
		
	if(root->right != NULL)
	preorder(root->right);
}

void postorder(struct node* root)
{
	if(root->left != NULL)
	postorder(root->left);
		
	if(root->right != NULL)
	postorder(root->right);

	printf("%d ",root->data);
}


int main() {
	
	//4 y 5 y 7 n n y 8 n n y 10 n y 1 n n      jenny's test  case  
	//7 y 4 y 8 n n y 4 n n y 10 y 1 n n y 12 n n
    /* 
	     7 
		/ \
	  4    10
    /  \  /  \
   8    4 1   12
	
	*/
	struct node *root = givetree();

	printf("\nThe preorder traversal of this tree is : ");            
    preorder(root);

	printf("\nThe ineorder traversal of this tree is : ");
    inorder(root);	

	printf("\nThe postorder traversal of this tree is : ");
    postorder(root);
//YE mera first change hai
//YE mera 2nd change hai

	return 0;
} 