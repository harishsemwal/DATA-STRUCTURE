// Binary tree basic 

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter The Data (-1 for no node): \n");
    scanf("%d",&x);

    if(x == -1)
    {
        return 0;
    }
    newnode->data = x;

    printf("Enter The Element of left child of %d\n: ",x);
    newnode->left = create_node();

    printf("Enter The Element of right child of %d\n: ",x);
    newnode->right = create_node();

    return newnode; 
}

void preOrder(struct node *tree)
{
    printf("%d\t",tree->data);
    preOrder(tree->left);
    preOrder(tree->right);
}

int main()
{
    struct node *root;
    root = create_node();
    preOrder(root);
}

/*
Preoerder Traversal
-------------------------------


void preOrder(struct node *tree)
{
    printf("%d\t",tree->data);
    preOrder(tree->left);
    preOrder(tree->right);
}
----------------------------------

void inOrder(struct node *tree)
{
   
    preOrder(tree->left);
    printf("%d\t",tree->data);
    preOrder(tree->right);
}
-----------------------------------

void postOrder(struct node *tree)
{
    preOrder(tree->left);
    preOrder(tree->right);
    printf("%d\t",tree->data);
}
------------------------------------
*/