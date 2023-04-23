#include<stdio.h>
#include<stdlib.h>

struct node{  
    int data;  
    struct node *left;  
    struct node *right;  
};  

struct node* insertNode(int data) 
{
  struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    newNode->left = NULL;  
    newNode->right = NULL;  
    return newNode;  
}  


void Inorder_traversal(struct node* root)
{
	if (root == NULL)
		return;
		
	Inorder_traversal(root->left);
	printf("%d ", root->data);
	Inorder_traversal(root->right);
}

void Preorder_traversal(struct node* root)
{
    if (root == NULL)
        return;
 
    printf("%d ", root->data);
    Preorder_traversal(root->left);
    Preorder_traversal(root->right);
}

void Postorder_traversal(struct node* root)
{
    if (root == NULL)
        return;
 
    Postorder_traversal(root->left);
    Postorder_traversal(root->right);
    printf("%d ", root->data);
    
}


int main()
{
    struct node *root = NULL; 
    root = insertNode(9);
	root->left = insertNode(2);
	root->right = insertNode(4);
	root->left->left = insertNode(3);
	root->left->right = insertNode(7);
	root->right->left = insertNode(6);
	root->right->right = insertNode(5);
	root->right->left->left = insertNode(1);
	root->right->left->right = insertNode(8);

	printf("Inorder traversal: \n");
	Inorder_traversal(root);
	
	printf("\nPreorder traversal: \n");
    Preorder_traversal(root);
    
    printf("\nPostorder traversal:  \n");
    Postorder_traversal(root);
    
	return 0;
}
