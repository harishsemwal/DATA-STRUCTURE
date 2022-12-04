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
void print_each_lavel(struct node *tree,int level)
{
	if(tree == NULL)
	{
		return;
	}
	if(level == 1)
	{
		printf("%d ",tree->data);
	}
	else if(level > 1)
	{
		print_each_lavel(tree->left,level -1);
		print_each_lavel(tree->right, level - 1);
	}
}

int cheack_hight(struct node *root)
{
	int hight1, hight2;
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		hight1 = cheack_hight(root->left);
		hight2 = cheack_hight(root->right);
	}

	if(hight1 > hight2)
	{
		return (hight1 + 1);
	}
	else
	{
		return (hight2 + 1);
	}
}

void lavel_order_traversal(struct node *tree)
{
	int height = cheack_hight(tree);
	for (int i = 1; i <= height; i++)
	{
		print_each_lavel(tree,i);
	}
}

int main()
{
	struct node *root = NULL;
	struct node *tree = NULL;
	int choice;
	while (1)
	{
		printf("\n1->Insertion: \n");
		printf("2->Breath for Search: \n");

		printf("Enter Your choice: ");
		scanf("%d",&choice);

		switch (choice)
		{
		case 1: 
			tree = create_node();
			break;
		case 2: 
			lavel_order_traversal(tree);
			break;
		default: printf("Invalid Choice !!!");
			break;
		}
	}
	
}