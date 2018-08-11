// C program to print left view of Binary Tree

#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	int dis;
	struct node *left, *right;
};

// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	temp->dis=INT_MAX;
	temp->left = temp->right = NULL;
	return temp;
}

// Recursive function to print left view of a binary tree.
map<int,int> bottomViewUtil(struct node *root, int level)
{
  map<int,int> m;
    if(root==NULL)
       return m;
    queue<node*> q;
    q.push(root);
    root->dis=0;
    while(!q.empty()){
        node * n=q.front();
        q.pop();
        m[n->dis]=n->data;
        if(n->left){
            n->left->dis=n->dis-1;
            q.push(n->left);
        }
        if(n->right){
            n->right->dis=n->dis+1;
            q.push(n->right);
        }

    }

    return m;
}

// A wrapper over leftViewUtil()
void bottomView(struct node *root)
{
	
	map<int,int> p=leftViewUtil(root, 1);
	map<int ,int> :: iterator ir;
	for( ir=p.begin();ir!=p.end();ir++){
	    cout<< ir->second<< " ";
	}
	
}

// Driver Program to test above functions

int main()
{
	struct node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(5);
	root->left->right = newNode(3);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right->left = newNode(4);
	root->right->right = newNode(25);

	bottomView(root);

	return 0;
}
