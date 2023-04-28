#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}node;
node* create_node(int data)
{
    node *tmp=(node *)malloc(sizeof(node));
    tmp->key=data;
    tmp->left=tmp->right=NULL;
    return tmp;
}
node* insert(node *root,node *z)
{
    if(root==NULL) return z;
    if(root->key>z->key) root->left=insert(root->left,z);
    else if(root->key<=z->key) root->right=insert(root->right,z);
    return root;
}
void inorder(node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}
void postorder(node *root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key);
}
void preorder(node *root)
{
    if(root==NULL) return;
    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}
node* search(node *root,node *z)
{
    if(root==NULL || root->key==z->key) return root;
    if(root->key<=z->key) return search(root->right,z);
    else return search(root->left,z);
}
node* max(node *root)
{
    while(root->right!=NULL) root=root->right;
    return root;
}
node* min(node *root)
{
    while(root->left!=NULL) root=root->left;
    return root;
}
node* successor(node *root,node *n)
{
    if(root==NULL) return NULL;
    if(n->right!=NULL) return min(n->right);
    
        node* succ=NULL;
        while(root!=NULL)
        {
            if(n->key<root->key)
            {
                succ=root;
                root=root->left;
            }
            else if(n->key>root->key)
                root=root->right;
            else    break;
        }

    return succ;
}
node* predecessor(node *root,node *n)
{
    if(root==NULL) return NULL;
    if(n->left!=NULL) return(max(n->left));
    node *pre=NULL;
    while(root!=NULL)
    {
        if(n->key> root->key)
        {
            pre=root;
            root=root->right;
        }
        else if(n->key< root->key)
            root=root->left;
        else
            break;
    }
    return pre;
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
    return root;
}
int level(node *root,int k,int l)
{
    if(root==NULL) return -1;
    if(root->key==k) return l;
    int dl=level(root->left,k,l+1);
    if(dl!=-1) return dl;
    dl=level(root->right,k,l+1);
    return dl;
}
int main()
{
    node *root=NULL;
    char ch;int k;
    node *x;
    while(1)
    {
        scanf(" %c",&ch);
        switch(ch)
        {
            case 'a':
                scanf("%d",&k);
                root=insert(root,create_node(k));
                //count++;
                break;
            case 'i':
                inorder(root);
                printf("\n");
                break;
            case 'p':
                preorder(root);
                printf("\n");
                break;
            case 't':
                postorder(root);
                printf("\n");
                break;
            case 's':
                scanf("%d",&k);
                (search(root,create_node(k))==NULL)?printf("-1\n"):printf("1\n");
                break;
            case 'u':
                scanf("%d",&k);
                x=search(root,create_node(k));
                if(x==NULL || x==max(root)) 
                {
                    printf("-1\n");
                    break;
                }
                else
                    printf("%d\n",successor(root,x)->key);
                break;
            case 'r':
                scanf("%d",&k);
                x=search(root,create_node(k));
                if(x==NULL || x==min(root)) 
                {
                    printf("-1\n");
                    break;
                }
                else
                    printf("%d\n",predecessor(root,x)->key);
                break;
            case 'd':
                scanf("%d",&k);
                x=search(root,create_node(k));
                if(x==NULL)
                {
                    printf("-1\n");
                    break;
                }
                else{
                    root=delete(root,k);
                   // printf("%d\n",k);
                }
                break;
            case 'l':
                scanf("%d",&k);
                x=search(root,create_node(k));
                if(x==NULL)
                {
                    printf("-1\n");
                    break;
                }
                printf("%d\n",level(root,k,1));
                break;
            case 'm':
                printf("%d\n",min(root)->key);
                break;
            case 'x':
                printf("%d\n",max(root)->key);
                break;
            case 'e': exit(0);
            default: exit(0);
        }
    }
    return 0;
}
