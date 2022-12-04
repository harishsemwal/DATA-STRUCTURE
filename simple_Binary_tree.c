// Perform all Binary tree.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *create_node()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter The Element (-1) if no node: ");
    scanf("%d",&x);
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if(x == -1)
    {
        return 0;
    }
    printf("\nEnter The Element left of %d: \n",x);
    newnode->left = create_node();

    printf("\nEnter The Element right of %d: \n",x);
    newnode->right = create_node();

    return newnode;
    
}

void inorder_traversal(struct node *root)
{
	printf("%d\t",root->data);
	inorder_traversal(root->left);
	inorder_traversal(root->right);
}

int main()
{
    struct node *root;
    root = create_node();
    printf("The inorder traversal is: \n");
    inorder_traversal(root);
}