#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *tree;

struct node *insertion(struct node *tree,int total)
{
	int i;
	printf("Enter The %d nodes: \n",total);
	for(i = 1 ; i <= total ; i++)
	{
	struct node *newnode = tree;
	struct node *traverse = NULL;
	struct node *parent_node = NULL;

	newnode = (struct node *)malloc(sizeof(struct node));
	scanf("%d",&newnode->data);
	newnode->left = NULL;
	newnode->right = NULL;
	
	if(tree == NULL)
	{
		tree = newnode;
	}
	else
	{
		traverse = tree;
		while(traverse != NULL)
		{
			parent_node = traverse;
			if(newnode->data < traverse->data)
			{
				traverse = traverse -> left;
			}
			else
			{
				traverse = traverse -> right; 
			}
		}
		
		if(newnode->data < parent_node->data)
		{
			parent_node->left = newnode;
		}
		else
		{
			parent_node -> right = newnode;
		}
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

struct node *find_smallest(struct node *tree)
{
	if(tree == NULL || tree->left == NULL)
	{
		return tree;
	}
	else
	{
		return find_smallest(tree->left);
	}
}

struct node *find_gratest(struct node *tree)
{
	if(tree == NULL || tree->right == NULL)
	{
		return tree;
	}
	else
	{
		return find_gratest(tree->right);
	}
}

struct node *delete_node(struct node *tree, int val)
{
	struct node *cur , *parent, *suc, *psuc, *ptr;
	if(tree->left == NULL)
	{
		printf("List is Empty !!!\n");
	}
	
	parent = tree;
	cur = tree->left;
	
	while(cur != NULL && val != cur->data)
	{
		parent = cur;
		cur = (val < cur->data) ? cur->left : cur->right;
	}
	if(cur == NULL)
	{
		printf("Element is not present in The tree !!!");
		return tree;
	}
	
	
	if(cur->left == NULL)
	{
		ptr = cur -> right;
	}
	else if(cur->right == NULL)
	{
		ptr = cur -> left;
	}	
	else
	{
		// find the inorder succesor of its parent
		psuc = cur;
		cur = cur -> left;
		while(suc->left != NULL)
		{
			psuc = suc;
			suc = suc -> left;
		}
		if(cur == psuc)
		{
			//Situation 1
			suc->left = cur->left;
			psuc->left = suc->right;
			suc->right = cur->right;
		}
		ptr = suc;
	}
	// atech ptr with parent node
	if(parent->left == cur)
	{
		parent->right = ptr;
	}
	else
	{
		parent->left = ptr;
	}
	free(cur);
	return tree;
}

int count_total_node(struct node *tree)
{
	if(tree == NULL)
	{
		return 0;
	}
	else
	{
		return (count_total_node(tree->left) + count_total_node(tree->right));
	}
}

int total_external_node(struct node *tree)
{
	if(tree == NULL)
	{
		return 0;
	}
	else if((tree->left == NULL) && (tree->right == NULL))
	{
		return 1;
	}
	else
	{
		return(total_external_node(tree->left) + total_external_node(tree->right) + 1);
	}
}


int total_internal_node(struct node *tree)
{
	if((tree == NULL)|| ((tree->left == NULL) && (tree->right == NULL)))
	{
		return 0;
	}
	else 
	{
		return(total_internal_node(tree->left) + total_internal_node(tree->right) + 1);
	}
}

int hight(struct node *tree)
{
	int left_hight, right_hight;
	
	if(tree == NULL)
	{
		return 0;
	}
	else
	{
		left_hight = hight(tree->left);
		right_hight = hight(tree->right);
		
		if(left_hight > right_hight)
		{
			return (left_hight + 1);
		}
		else
		{
			return (right_hight + 1);
		}
	}
}
// Do not know clearly.
struct node *mirror_image(struct node *tree)
{
	struct node *ptr;
	if(ptr != NULL)
	{
		mirror_image(tree->left);
		mirror_image(tree->right);
		ptr = tree->left;
		ptr->left = ptr->right;
		tree->right = ptr;
	}
}

struct node *deleteTree(struct node *tree)
{
	if(tree!= NULL)
	{
		deleteTree(tree->left);
		deleteTree(tree->right);
		free(tree);
	}
}
int main()
{
    int choice, val, del, num;
    struct node *tree = NULL;
    struct node *ptr;
while(1)
{
    printf("\nPlease Enter one choice :\n");
    printf("1->: Insertion: \n");
    printf("2->: Preorder: \n");
    printf("3->: Postorder: \n");
    printf("4->: Inorder: \n");
    printf("5->: Find smallest: \n");
    printf("6->: Find Largest: \n");
    printf("7->: Delete an element: \n");
    printf("8->: Count the total number of nodes: \n");
    printf("9->: Count the total number of external nodes: \n");
    printf("10->: Count the total number of internal nodes: \n");
    printf("11->: Determine the hight of the tree: \n");
    printf("12->: Find the mirror image of tree: \n");
    printf("13->: Delete the tree: \n");
    printf("14->: Exit \n");
    
    printf("\nEnter The choice: ");
    scanf("%d",&choice);
    
    switch(choice)
    {
        case 1 : printf("Enter The total number of node: ");
                 scanf("%d",&val);
                 tree = insertion(tree,val);
                 break;
        case 2 : printf("The Element of tree is: \n");
                 preorder_traversal(tree);
                 break;
        case 3 : printf("The Element of tree is: \n");
                 postorder_traversal(tree);
                 break;
        case 4 : printf("The Element of tree is: \n");
                 inorder_traversal(tree);
                 break;
        case 5 : ptr =  find_smallest(tree);
        	     printf("The smallest element is: %d\n",ptr->data);
        	     break;
        case 6 : ptr =  find_gratest(tree);
        	     printf("The gratest element is: %d\n",ptr->data);
        	     break;
        case 7 : printf("\nEnter The Element which you want to delete: ");
        		 scanf("%d",&del);
        		 tree = delete_node(tree,del);
        		 break;
        case 8 : num = count_total_node(tree);
        		 printf("The total number of node in tree is: %d\n",num);
        		 break;
        case 9 : num = total_external_node(tree);
        		 printf("The total number of external node in tree is: %d\n",num);
        		 break;
        case 10: num = total_internal_node(tree);
        		 printf("The total number of internal node in tree is: %d\n",num);
        		 break;
        case 11: num = hight(tree);
        		 printf("The total hight of the tree is: %d\n",num);
        		 break;
        case 12: tree = mirror_image(tree);
        		 break;
        case 13: tree = deleteTree(tree);
        		 break;
        default: exit(0);
        		 break;
    }
}
}
