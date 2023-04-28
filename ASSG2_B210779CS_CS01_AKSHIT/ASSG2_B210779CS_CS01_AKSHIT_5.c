#include <stdio.h>
#include <stdlib.h>
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
void inorder(node *root)
{
	if(root==NULL) return;
	inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);
}
void par(node *root)
{
	if (root == NULL) 
	{
        printf("( )");
        return;
    }
    
    printf("( %d ", root->key);
    par(root->left);
    printf(" ");
    par(root->right);
    printf(" )");
}
void preorder(node *root)
{
	if(root==NULL) return;
	printf("%d ",root->key);
	preorder(root->left);
	preorder(root->right);
}
node* search(node *root,int key)
{
	if(root==NULL || root->key==key) return root;
	else if(key<root->key) return search(root->left,key);
	else return search(root->right,key);
}
node* min(node *root)
{
    while(root->left!=NULL) root=root->left;
    return root;
}
node* delete(node *root,int k)
{
    if(root==NULL) return root;
    if(k<root->key) root->left= delete(root->left,k);
    else if(k>root->key) root->right= delete(root->right,k);
    else
    {
        if(root->left==NULL)
        {
            node *tmp=root->right;
            free(root);
            return tmp;
        }
        else if(root->right==NULL)
        {
            node *tmp=root->left;
            free(root);
            return tmp;
        }
        node *tmp=min(root->right);
        root->key=tmp->key;
        root->right=delete(root->right,tmp->key);
    }
    root->h=1+max(h(root->left),h(root->right));
	int b=balance(root);
	if(b>1 && balance(root->left)>=0)
		return right_rotate(root);
	if(b<-1 && balance(root->right)<=0)
		return left_rotate(root);
	if(b>1 && balance(root->left)<0)
	{
		root->left=left_rotate(root->left);
		return right_rotate(root);
	}
	if(b<-1 && balance(root->right)>0)
	{
		root->right=right_rotate(root->right);
		return left_rotate(root);
	}
    return root;
}
int main()
{
	char ch;
	int k;
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
			case 'p':
				par(root);
				printf("\n");
				break;
			case 's':
				scanf("%d",&k);
				search(root,k)?printf("TRUE\n"):printf("FALSE\n");
				break;
			case 'b':
				scanf("%d",&k);
				t=search(root,k);
				if(t==NULL)
				{
					printf("FALSE\n");
					break;
				}
				printf("%d\n",balance(t));
				break;
			case 'd':
				scanf("%d",&k);
				t=search(root,k);
				if(t==NULL) 
				{
					printf("FALSE\n");
					break;
				}
				printf("%d\n",k);
				root=delete(root,k);
				break;
			default:
				exit(0);
		}
	}
	return 0;
}
