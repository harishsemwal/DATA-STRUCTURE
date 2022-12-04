// Write a Programe to Create Binary tree Perform all The Operations.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;

struct node *insertion(struct node *tree,int val)
{
    struct node *newnode = NULL;
    struct node *parent_ptr = NULL;
    struct node *traverse_ptr = NULL;
    
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    
    if(tree == NULL)
    {
        tree = newnode;
    }
    else
    {
        traverse_ptr = tree;
        while(traverse_ptr!= NULL)
        {
            parent_ptr = traverse_ptr;
            if(val < parent_ptr->data)
            {
                traverse_ptr = traverse_ptr->left;
            }
            else
            {
                traverse_ptr = traverse_ptr->right;
            }
        }
          if(val < parent_ptr->data)
            {
                parent_ptr->left = newnode;
            }
            else
            {
                parent_ptr->right = newnode;
            }
    }
    return tree;
}

void preorder_traversal(struct node *tree)
{
    if(tree!= NULL)
    {
        printf("%d ",tree->data);
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
    }
}

void inorder_traversal(struct node *tree)
{
    if(tree!= NULL)
    {
        preorder_traversal(tree->left);
        printf("%d ",tree->data);
        preorder_traversal(tree->right);
    }
}

void postorder_traversal(struct node *tree)
{
    if(tree!= NULL)
    {
        preorder_traversal(tree->left);
        preorder_traversal(tree->right);
        printf("%d ",tree->data);
    }
}

int main()
{
    int n, val;
    printf("Enter The number of element: \n");
    scanf("%d",&n);
    
    printf("Enter The Elements: ");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&val);
        tree = insertion(tree, val);
    }
    
    printf("\nThe Elements is: \n");
    inorder_traversal(tree);
}