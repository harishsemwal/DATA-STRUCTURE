// insertion in Binary Search tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *left;
	struct node *right;
};

struct node *insertion_node(struct node *tree)
{
	struct node *newnode = NULL;
	struct node *parent_n = NULL;
	struct node *traverse = NULL;

	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter The Elements: ");
	scanf("%d",&newnode->num);

	newnode->left = NULL;
	newnode->right = NULL;

	if(tree == NULL)
	{
		tree = newnode;
		newnode->left = NULL;
	    newnode->right = NULL;
	}
	else
	{
		parent_n = NULL;
		traverse = tree;
		while(traverse != NULL)
		{
		    parent_n = traverse;
			if(newnode->num < traverse->num)
			{
				traverse = traverse->left;
			}
			else
			{
				traverse = traverse->right;
			}
		}
		if(newnode->num < parent_n->num)
		{
			parent_n->left = newnode;
		}
		else
		{
			parent_n->right = newnode;
		}
	}
	return tree;
}
void inorder_traversal(struct node *tree)
{
    if(tree != NULL)
    {
        inorder_traversal(tree->left);
        printf("%d ",tree->num);
        inorder_traversal(tree->right);
    }
}

void preorder_traversal(struct node *tree)
{
    if(tree != NULL)
    {
        printf("%d ",tree->num);
        inorder_traversal(tree->left);
        inorder_traversal(tree->right);
    }
}

void preorder_traversal(struct node *tree)
{
    if(tree != NULL)
    {
        inorder_traversal(tree->left);
        inorder_traversal(tree->right);
        printf("%d ",tree->num);
    }
}


int main()
{
    int choice;
    struct node *tree = NULL;
    while(1)
    {
        printf("1->: Insertion_node: \n");
        printf("2->: inorder_traversal: \n");
        printf("3->: preorder_traversal: \n");
        printf("4->: postorder_traversal: \n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1 : tree = insertion_node(tree);
                    break;
            case 2 : inorder_traversal(tree);
                    break;
            case 3 : preorder_traversal(tree);
                    break;
            case 4 : postorder_traversal(tree);
                    break;
        }
    }
}