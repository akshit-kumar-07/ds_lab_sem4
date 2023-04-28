#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

typedef struct node
{
	int key;
	struct node *next;
}node;

typedef struct list
{
	node *head;
}list;

node* create_node(int data)
{
	node *tmp=(node *)malloc(sizeof(node));
	tmp->key=data;
	tmp->next=NULL;
	return tmp;
}

list* create_list()
{
	list *tmp=(list *)malloc(sizeof(list));
	tmp->head=NULL;
	return tmp;
}

list* insert(list *l,node *x)
{
	node *t=l->head;
	if(t==NULL) {l->head=x;return l;}
	if(t->key>x->key)
	{
		x->next=l->head;
		l->head=x;
	}
	else{
		while(t->next!=NULL && t->next->key<x->key) t=t->next;
		x->next=t->next;
		t->next=x;
		return l; 
	}
	return l;
}

node* extract_min(list *l)
{
	if(l->head==NULL) return NULL;
	node *tmp=l->head;
	l->head=l->head->next;
	return tmp;
}

void print(list *l)
{
	node *tmp=l->head;
	while(tmp!=NULL)
	{
		printf("%d ",tmp->key);
		tmp=tmp->next;
	}
	printf("\n");
}

void min_cost(list *l)
{
	int sum=0;
	node *t=l->head;
	while(l->head->next!=NULL)
	{
		node *x=extract_min(l);
		node *y=extract_min(l);
		int cost_x=0;int cost_y=0;
		if(x!=NULL) cost_x=x->key;
		if(y!=NULL) cost_y=y->key;
		int z=cost_x+cost_y;
		sum+=z;
		l=insert(l,create_node(z));
		//print(l);
		//printf("x=%d y=%d %d\n",cost_x,cost_y,sum);
		
	}
	printf("%d\n",sum);
}

int main()
{
	char ch;int k;
	int n;scanf("%d",&n);
	list *l=create_list();
	while(n--)
	{
		scanf("%d",&k);
		l=insert(l,create_node(k));
	}
	min_cost(l);
	/*while(1)
	{
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'a':
				scanf("%d",&k);
				l=insert(l,create_node(k));
				break;
			case 'e':
				if(l->head==NULL)
				{
					printf("-1\n");
					break;
				}
				printf("%d\n",extract_min(l)->key);
				print(l);
				break;
			case 'p':
				print(l);
				break;
			case 's':
				min_cost(l);
				break;
			default: exit(0);
		}
	}*/
	return 0;
}



















