#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
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
int subtrees(node *root, int k) 
{
    if (root == NULL) 
    {
        return 0;
    }
    int lc=subtrees(root->left,k);
    int rc=subtrees(root->right,k);
    int cs=root->key+(root->left?root->left->key:0)+(root->right?root->right->key:0);
    int cur_count=(cs==k);
    return (lc+rc+cur_count);
}
int main() 
{
    node *root = NULL;
    int k;
    char str[1000];
    fgets(str,1000,stdin);
    root=create_tree(str);scanf("%d",&k);
    printf("%d\n",subtrees(root,k));
    return 0;
}

//( 1 ( 3 ( 5 ( ) ( ) ) ( 9 ( ) ( ) ) ) ( 6 ( 11 ( ) ( ) ) ( ) ) )
//( 5 ( 2 ( 1 ( ) ( ) ) ( 3 ( ) ( ) ) ) ( 12 ( 9 ( ) ( ) ) ( 21 ( ) ( ) ) ) 
