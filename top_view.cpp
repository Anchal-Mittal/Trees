// C program to print left view of Binary Tree
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Recursive function to print left view of a binary tree.
void topViewUtil(struct node *root, int level, auto &m)
{
	// Base Case
	if (root==NULL) 
	return;
    
    if(m.find(level)==m.end())
    {
        m[level]=root->data;
        cout<<root->data<<" ";
    }
	topViewUtil(root->left, level-1, m);
	topViewUtil(root->right, level+1, m);
}

// A wrapper over leftViewUtil()
void topView(struct node *root)
{
	int level = 0;
	map<int,int> m;
	leftViewUtil(root, 1, m);
}

// Driver Program to test above functions
int main()
{
	struct node *root = newNode(12);
	root->left = newNode(10);
	root->right = newNode(30);
	root->right->left = newNode(25);
	root->right->right = newNode(40);

	topView(root);

	return 0;
}
