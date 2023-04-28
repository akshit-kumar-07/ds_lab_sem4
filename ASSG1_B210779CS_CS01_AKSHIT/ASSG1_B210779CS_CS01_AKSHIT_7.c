#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int count=0;
int arr[1000];
typedef struct node
{
	int key;
	struct node *left;
	struct node *right;
	struct node *p;
}node;
node* create_node(int data)
{
	node *tmp=(node *)malloc(sizeof(node));
	tmp->left=tmp->right=tmp->p=NULL;
	tmp->key=data;
	return tmp;
}
node* create_tree(char *str)
{
	int temp,k,i;
	char key[1000];
	str+=2;
	if(*str==')') return NULL;
	i=0;
	while(*str>='0' && *str<='9')
	{
		key[i++]=*str;
		str++;
	}
	key[i]='\0';
	k=atoi(key);
	node* root=create_node(k);
	str++;
	root->left=create_tree(str);
	str++;
	temp=1;
	while(temp!=0)
	{
		if(*str=='(') temp++;
		if(*str==')') temp--;
		str++;
	}
	str++;
	root->right=create_tree(str);
	return root;
}
node* insert(node *root,node *z)
{
	node *x=root;node *y=NULL;
	while(x!=NULL)
	{
		y=x;
		if(z->key< x->key) x=x->left;
		else x=x->right;
	}
	z->p=y;
	if(y==NULL) return z;
	else if(y->key< z->key) y->right=z;
	else y->left=z;
	return root;
}
void inorder(node *root)
{
	if(root==NULL) return;
	inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);
	return;
}
void preorder(node *root)
{
	if(root==NULL) return;
	int key=root->key;
	arr[count++]=key; //printf("count=%d\n",count);
	preorder(root->left);
	preorder(root->right);
}
void po(node *root)
{
	if(root==NULL) return;
	printf("%d ",root->key);
	po(root->left);
	po(root->right);
}
node* search(node* root,int key)
{
    if (root == NULL || root->key == key)
       return root;
    if (root->key < key)
       return search(root->right, key);
    return search(root->left, key);
}
int main()
{
	char str[1000];
	fgets(str,1000,stdin);
	node *root=create_tree(str);
	node *r=NULL;
	preorder(root);
	for(int i=0;i<count;i++)
		r=insert(r,create_node(arr[i]));
	//inorder(r);
	//r=new_tree(root,r);
	//po(r);
	int k;scanf("%d",&k);
	node *tmp=search(r,k); //if(tmp==NULL) printf("NOT found\n");
	if(search(r,k)==NULL || r->key==k)
	{
		printf("-1");
		return 0;
	}
	tmp=tmp->p;
	while(tmp!=NULL)
	{
		printf("%d ",tmp->key);
		tmp=tmp->p;
		//if(tmp==NULL) printf("NULL econountered\n");
	}
	return 0;
}
//( 16 ( 13 ( 12 ( ) ( ) ) ( 14 ( ) ( ) ) ) ( 23 ( 20 ( ) ( ) ) ( 32 ( ) ( ) ) ) ) )
