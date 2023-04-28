#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int key;
	int red;
	struct node *link[2];
}node;

node* create_node(int data)
{
	node *tmp=(node *)malloc(sizeof(node));
	tmp->key=data;
	tmp->red=1;
	tmp->link[0]=tmp->link[1]=NULL;
	return tmp;
}

int is_red(node *x)
{
	return ( x!=NULL && x->red==1);
}

node* single(node *y,int d)
{
	node *x=y->link[!d];
	node *t=x->link[d];
	x->link[d]=y;
	y->link[!d]=t;
	x->red=0;
	y->red=1;
	return x;
}

node *dbl(node *y,int d)
{
	y->link[!d]=single(y->link[!d],!d);
	return single(y,d);
}	

int is_leaf(node *x)
{
	return(x->link[0]==NULL && x->link[1]==NULL);
}

node* insert(node *root,node *x)
{
	if(root==NULL) root=x;
	else if(root->key !=x->key)
	{
		int d=root->key < x->key;
		root->link[d]=insert(root->link[d],x);
		if(is_red(root->link[d]))
		{
			if(is_red(root->link[!d]) && !is_leaf(root->link[d]))
			{
				root->link[0]->red=0;
				root->link[1]->red=0;
				root->red=1;
			}
			else 
			{
				if(is_red(root->link[d]->link[d]))
					root=single(root,!d);
				else if(is_red(root->link[d]->link[!d]))
					root=dbl(root,!d);
			}
		}
	}
	//root->red=0;
	return root;
}
node* ins(node *root,node *x)
{
	root=insert(root,x);
	root->red=0;
	return root;
}
void par(node *root)
{
	if (root == NULL) {
        printf("( )");
        return;
    }
    
    printf("( %d %c ", root->key,(root->red?'R':'B'));
    par(root->link[0]);
    printf(" ");
    par(root->link[1]);
    printf(" )");
}


int main()
{
	int k;char ch;char str[4];
	node *root=NULL;
	while(1)
	{
		scanf("%s",str);
		k=atoi(str);
		if(*str=='t') exit(0);
		root=ins(root,create_node(k));
		par(root);
		printf("\n");
		/*scanf(" %c",&ch);
		switch(ch)
		{
			case 'a':
				scanf("%d",&k);
				if((char)k=='t') exit(0);
				root=ins(root,create_node(k));
				par(root);
				printf("\n");
				break;
			default: exit(0);
		}*/
	}
	return 0;
}

