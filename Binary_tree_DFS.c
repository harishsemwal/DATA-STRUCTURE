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
    scanf("%d", &x);
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    if (x == -1)
    {
        return 0;
    }
    printf("\nEnter The Element left of %d: \n", x);
    newnode->left = create_node();

    printf("\nEnter The Element right of %d: \n", x);
    newnode->right = create_node();

    return newnode;
}

void inorder_traversal(struct node *tree)
{
    if (tree != NULL)
    {
        inorder_traversal(tree->left);
        printf("%d ", tree->data);
        inorder_traversal(tree->right);
    }
}

void preorder_traversal(struct node *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        inorder_traversal(tree->left);
        inorder_traversal(tree->right);
    }
}

void postorder_traversal(struct node *tree)
{
    if (tree != NULL)
    {
        inorder_traversal(tree->left);
        inorder_traversal(tree->right);
        printf("%d ", tree->data);
    }
}

int main()
{
    int choice;
    struct node *tree = NULL;
    while (1)
    {
        printf("\n1->: Insertion_node: \n");
        printf("2->: inorder_traversal: \n");
        printf("3->: preorder_traversal: \n");
        printf("4->: postorder_traversal: \n");
        printf("Enter Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            tree = create_node();
            break;
        case 2:
            inorder_traversal(tree);
            break;
        case 3:
            preorder_traversal(tree);
            break;
        case 4:
            postorder_traversal(tree);
            break;
        }
    }
}