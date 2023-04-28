#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node
{
	int key;
	struct node *left;
	struct node *right;
}node;
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
void level(node *root,int k)
{
	if(root==NULL) 
	{
		printf("-1\n");
		return;
	}
	if(k==0)
	{
		printf("%d\n",root->key);
		return;
	}
	level(root->left,k-1);
	level(root->right,k-1);
}
/*node* search(node *n,int k)
{
	int flag=0;
	if(n==NULL) return NULL;
	printf("%d\n",n->key);
	if(n->key==k)
	{
		flag=1;
		return n;
	}
	if(flag==0)
		return search(n->left,k);
	if(flag==0)
		return search(n->right,k);
}*/
node* search(node *n,int k)
{
	int flag=0;
	if(n==NULL) return NULL;
	if(n->key==k)
	{
		flag=1;return n;
	}
	if(flag==0 && n->left!=NULL)
		return search(n->left,k);
	if(flag==0 && n->right!=NULL)
		return search(n->right,k);
}
void print_descendants(node *x,int k) {
    if(x==NULL) return;
    if (k==0) 
    {
        printf("%d ",x->key);
        return;
    }
    print_descendants(x->left, k-1);
    print_descendants(x->right, k-1);
}

int main()
{
	node *root=NULL;
	char str[1000];
	fgets(str,1000,stdin);
	root=create_tree(str); 
	int k;int x;scanf("%d %d",&x,&k);
	node *t=search(root,x); //if(t==NULL) printf("NULL\n");
	//inorder(t);
	print_descendants(t,k);
	return 0;
}
