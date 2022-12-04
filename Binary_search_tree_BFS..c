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
void inorder_traversal(struct node *start)
{
	struct node *trav = start;
	if(start != NULL)
	{
		inorder_traversal(trav->left);
		printf("%d ",trav->num);
		inorder_traversal(trav->right);
	}
}

void print_each_lavel(struct node *tree,int level)
{
	if(tree == NULL)
	{
		return;
	}
	if(level == 1)
	{
		printf("%d ",tree->num);
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
			tree = insertion_node(tree);
			break;
		case 2: 
			lavel_order_traversal(tree);
			break;
		default: inorder_traversal(tree);
			break;
		}
	}
	
}