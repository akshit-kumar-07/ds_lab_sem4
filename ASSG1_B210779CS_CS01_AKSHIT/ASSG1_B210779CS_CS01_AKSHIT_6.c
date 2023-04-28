#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node
{
	int key;
	struct node *p;
	struct node *left;
	struct node *right;
}node;
node* create_node(int data)
{
	node *tmp=(node *)malloc(sizeof(node));
	tmp->key=data;
	tmp->left=tmp->right=tmp->p=NULL;
	return tmp;
}
node* create_tree(char *str)
{
	int temp;int k;int i;
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
	node *root=(node *)malloc(sizeof(node));
	root->key=k;
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
void inorder(node *root)
{
	if(root==NULL) return;
	inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);
	return;
}
void search(node *root,int l,int r)
{
	if(root==NULL) return;
	search(root->left,l,r);
	if(root->key>=l &&  root->key<=r)
		printf("%d ",root->key);
	search(root->right,l,r);
	return;
}
int main()
{
	node *root=NULL;
	int l,r;char ch;node *t;
	char str[1000];
	fgets(str,1000,stdin);
	root=create_tree(str);
	scanf("%d %d",&l,&r);
	search(root,l,r);
	return 0;
}
