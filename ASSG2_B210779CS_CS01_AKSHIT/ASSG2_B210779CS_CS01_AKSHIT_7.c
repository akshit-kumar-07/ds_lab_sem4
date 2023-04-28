#include <stdio.h>
#include <stdlib.h>
int count=-1;
int arr[1000];
typedef struct node
{
	int key;
	int h;
	struct node *left;
	struct node *right;
}node;
node* create_node(int data)
{
	node *tmp=(node *)malloc(sizeof(node));
	tmp->h=1;
	tmp->key=data;
	tmp->left=tmp->right=NULL;
	return tmp;
}
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int h(node *z)
{
	if(z==NULL) return 0;
	return z->h;
}
int balance(node *z)
{
	if(z==NULL) return 0;
	return (h(z->left)-h(z->right));
}
node* left_rotate(node *y)
{
	node *x=y->right;
	node *t=x->left;
	x->left=y;
	y->right=t;
	y->h=1+max(h(y->left),h(y->right));
	x->h=1+max(h(x->left),h(x->right));
	return x;
}
node* right_rotate(node *y)
{
	node *x=y->left;
	node *t=x->right;
	x->right=y;
	y->left=t;
	y->h=1+max(h(y->left),h(y->right));
	x->h=1+max(h(x->left),h(x->right));
	return x;
}

node* insert(node *n,node *z)
{
	if(n==NULL) return z;
	if(z->key< n->key) n->left=insert(n->left,z);
	else if(z->key> n->key) n->right=insert(n->right,z);
	else return n;
	n->h=1+max(h(n->left),h(n->right));
	int b=balance(n);
	if(b>1 && z->key<n->left->key)
		return right_rotate(n);
	if(b<-1 && z->key> n->right->key)
		return left_rotate(n);
	if(b>1 && z->key > n->left->key)
	{
		n->left=left_rotate(n->left);
		return right_rotate(n);
	}
	if(b<-1 && z->key < n->right->key)
	{
		n->right=right_rotate(n->right);
		return left_rotate(n);
	}
	return n;
}
node* search(node *root,int key)
{
	if(root==NULL || root->key==key) return root;
	else if(key<root->key) return search(root->left,key);
	else return search(root->right,key);
}
void inorder(node *root)
{
	//int j=0; int arr[1000];
	if(root==NULL) return;
	inorder(root->left);
	int k=root->key; int flag=0;
	for(int i=0;i<=count;i++) 
		if(arr[i]==k) flag=1;
	if(flag!=1) arr[++count]=root->key;	
	inorder(root->right);
}
int main()
{
	char ch;int k;int j;
	node *root=NULL;
	node *t=NULL;
	while(1)
	{
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'i':
				scanf("%d",&k);
				root=insert(root,create_node(k));
				break;
			case 'c':
				j=0;
				inorder(root);
				scanf("%d",&k);
				for(int i=0;i<=count;i++)
					if(arr[i]>k) j++;
				printf("%d\n",j);
				for(int i=0;i<=count;i++)
					if(arr[i]>k) printf("%d ",arr[i]);
				printf("\n");
				break;
			default:
				exit(0);
		}
	}
	return 0;
}
