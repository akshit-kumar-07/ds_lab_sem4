#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node
{
    int key, degree;
    struct node* parent;
    struct node* child;
    struct node* sibling;
}node;

node* root = NULL;
node *root2=NULL;
node *h=NULL;
int Link(node* h1, node* h2)
{
    h1->parent = h2;
    h1->sibling = h2->child;
    h2->child = h1;
    h2->degree++;
}
typedef struct node_ll
{
	node *key;
   	struct node_ll *sibling;
}*node_ll;

typedef struct queue
{
	node_ll head;
 	node_ll tail;
}*queue;

int QUEUE_EMPTY(queue Q)
{
   if(Q->head==NULL)
     return 0;
   else
     return 1;
}
node_ll CREATENODE(node *k)
{
	 node_ll temp;
	 temp=(node_ll)malloc(sizeof(struct node_ll));
	 temp->key=k;
	 temp->sibling=NULL;
	 return temp;
}
void ENQUEUE(queue Q,node *y)
{
	node_ll x=CREATENODE(y);
	//printf("%d",y->key); 
 	if(QUEUE_EMPTY(Q)==0)
   		Q->head=x;
 	else
    		Q->tail->sibling=x;
  		Q->tail=x;
  	//printf("enqueued");
 
}

void DEQUEUE(queue Q)
{
   if(QUEUE_EMPTY(Q)!=0)
     {
        node_ll temp=Q->head;
        if(Q->head==Q->tail)
          Q->tail=NULL;
        Q->head=Q->head->sibling;
         
}
//return temp->data;
}
void QUEUE_DELETE(queue Q)
{
    
   while(QUEUE_EMPTY(Q)!=0)
    {
      DEQUEUE(Q);
    }
  
}
void level_order_aux(node *root_q)
{
  if(root_q==NULL)
    return;
  printf("%d ", root_q->key) ;
  if(root_q->child==NULL)
    return;

   queue Q;
   Q=(queue)malloc(sizeof(struct queue));
   Q->head=NULL;
   Q->tail=NULL;
   node *present=root_q->child;
   ENQUEUE(Q,present);
   node *loop_tree;
   while(QUEUE_EMPTY(Q)!=0)
     {
       loop_tree=Q->head->key;
       DEQUEUE(Q);
        while(loop_tree!=NULL)
          {
              //printf("in while");
              printf("%d ",loop_tree->key);
              if(loop_tree->child!=NULL)
                   ENQUEUE(Q,loop_tree->child);
              loop_tree=loop_tree->sibling;
           }
    }
}

node* createNode(int n)
{
    node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = n;
    new_node->parent = NULL;
    new_node->sibling = NULL;
    new_node->child = NULL;
    new_node->degree = 0;
    return new_node;
}
struct node* MAKE_HEAP()
{
    struct node* head;
    head = NULL;
    return head;
}
node* MERGE(node* h1, node* h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;


    node* current = NULL;


    if (h2->degree >= h1->degree)
        current = h1;

    else if (h2->degree < h1->degree)
        current = h2;


    while (h1 != NULL && h2 != NULL)
    {

        if (h2->degree > h1->degree)
            h1 = h1->sibling;


        else if (h1->degree == h2->degree)
        {
            node* sib = h1->sibling;
            h1->sibling = h2;
            h1 = sib;
        }


        else
        {
            node* sib = h2->sibling;
            h2->sibling = h1;
            h2 = sib;
        }
    }
    return current;
}


node* UNION(node* h1, node* h2)
{
    if (h1 == NULL && h2 == NULL)
        return NULL;

    node* current = MERGE(h1, h2);


    node* prev = NULL;
    node* present = current;
    node* sibling = present->sibling;
    while (sibling != NULL)
    {
        if ((present->degree != sibling->degree) || ((sibling->sibling != NULL) && (sibling->sibling)->degree == present->degree))
        {
            prev = present;
            present = sibling;
        }

        else
        {
            if (present->key <= sibling->key)
            {
                present->sibling = sibling->sibling;
                 Link(sibling, present);
            }
            else
            {
                if (prev == NULL)
                    current = sibling;
                else
                    prev->sibling = sibling;
                Link(present, sibling);
                present = sibling;
            }
        }
        sibling = present->sibling;
    }
    return current;
}
/*node* UNION(node *h1,node *h2)
{
	if (h1 == NULL && h2 == NULL)
        return NULL;

    node* current = MERGE(h1, h2);


    node* xp = NULL;
    node* x = current;
    node* xn = x->sibling;
	int x_key=-1;int xn_key=-1;int xp_key=-1;
	if(xp) xp_key=xp->key;
	if(xn) xn_key=xn->key;
	if(x) x_key=x->key; 
	//printf("cur=%d sibling=%d\n",x_key,xn_key);
	while(xn!=NULL)
	{
		if((x->degree!=xn->degree)||((xn->sibling!=NULL) &&((xn->sibling)->degree==x->degree)))
		{
			xp=x;
			x=xn;
		}
		else
		{ 
			if(x->key<=xn->key)
			{
				x->sibling=xn->sibling;
				Link(xn,x);
			}
			else {
				if(xp==NULL) h=xn;
				else xp->sibling=xn;
				Link(x,xn);
				x=xn;
			}
		}
		xn=x->sibling;
	}
	return h;
}
*/


node* INSERT_aux(int x)
{

    root=UNION(root, createNode(x));
}

node* INSERT_aux2(int x)
{

    root2=UNION(root2, createNode(x));
}


void level_order(node* h)
{
    while (h)
    {
        printf("%d ", h->key);
        level_order(h->sibling);
        h = h->child;
    }
}
void level_order_2(node* h)
{
    while(h!=NULL)
    { 
        level_order_aux(h);
        h=h->sibling;       
     }
}
int reverse_linked_list(node* h)
{
    if (h->sibling != NULL)
    {
        reverse_linked_list(h->sibling);
        (h->sibling)->sibling = h;
    }
    else
        root = h;
}
void min_elem(node* h)
{
    if (h == NULL)
        printf("-1");
    else
    {
        node* min_node_prev = NULL;
        node* min_node = h;

        int min = h->key;
        node* present = h;
        while (present->sibling != NULL)
        {
            if ((present->sibling)->key < min)
            {
                min = (present->sibling)->key;
                min_node_prev = present;
                min_node = present->sibling;
            }
            present = present->sibling;
        }
        printf("%d\n", min);
    }
}
int min_elem_ret(node* h)
{
    if (h == NULL)
        return -1;

    node* min_node_prev = NULL;
    node* min_node = h;

    int min = h->key;
    node* present = h;
    while (present->sibling != NULL)
    {
        if ((present->sibling)->key < min)
        {
            min = (present->sibling)->key;
            min_node_prev = present;
            min_node = present->sibling;
        }
        present = present->sibling;
    }
    return min;
}
struct node* EXTRACT_MIN(node* h)
{
    if (h == NULL)
        return NULL;
    node* min_node_prev = NULL;
    node* min_node_curr = h;
    node* sibling = min_node_curr->sibling;
    int min = min_elem_ret(h);
    while (sibling != NULL)
    {
        if (min_node_curr->key == min)
            break;
        min_node_prev = min_node_curr;
        min_node_curr = sibling;
        sibling = sibling->sibling;
    }
    if (min_node_prev == NULL)
        h = sibling;
    else
        min_node_prev->sibling = sibling;
    min_node_curr->sibling = NULL;
    node* temp = min_node_curr;
    min_node_curr = min_node_curr->child;
    free(temp);
    node* new = (node*)malloc(sizeof(node));
    new->parent = NULL;
    new = min_node_curr;
    min_node_prev = NULL;
    sibling = NULL;
    while (min_node_curr != NULL)
    {
        sibling = min_node_curr->sibling;
        min_node_curr->sibling = min_node_prev;
        min_node_prev = min_node_curr;
        min_node_curr = sibling;
    }
    new = min_node_prev;
    return UNION(h, new);

}
node* search_node(node* h, int key)
{
    if (h == NULL)
        return NULL;
    if (h->key == key)
        return h;
    node* present = search_node(h->child, key);
    if (present != NULL)
        return present;

    return search_node(h->sibling, key);
}
void DECREASE_KEY(node *H, int key, int k){
      if(key>=k && search_node(H, key) != NULL){
            while(1){
                  
                  node *nd = search_node(H, key);
                  if(nd==NULL) break;

                  nd->key = key-k;
                  while(nd->parent != NULL){
                        if(nd->key < nd->parent->key){
                              int temp = nd->key;
                              nd->key = nd->parent->key;
                              nd->parent->key = temp;
                        }
                        else break;
                  }
            }
            //printf("%d\n", key-k);
      }
     // else printf("-1\n");
}


node* DELETE(node* h, int key)
{


    if (h == NULL)
    {
        printf("-1\n");
        return NULL;
     }
    node* temp = search_node(h, key);

    if (temp == NULL)
    {
        printf("-1\n");
        return h;
    }
    else
        printf("%d\n", key);

    DECREASE_KEY(h, key, 1e9);


    return EXTRACT_MIN(h);
}

void print(node *h)
{
  	node *p=h;
  	if(p==NULL) return;
  	while(p!=NULL)
  	{
  		printf("%d ",p->key);
  		p=p->sibling;
  	}
  	printf("\n");
} 

int main()
{
    char op;
    int elem;int k;
    int min;
    struct node* n;
   // scanf("%c", &op);
    int dec, dec_by;
    while (1)
    {
    	scanf(" %c",&op);
        switch (op)
        {
        case 'i':
            scanf("%d", &elem);
            INSERT_aux(elem);
            break;
        case 'j':
            scanf("%d", &elem);
            INSERT_aux2(elem);
            break;
        case 'd':
            scanf("%d", &elem);
            root = DELETE(root, elem);
            break;
        case 'x':
            min_elem(root);
            root = EXTRACT_MIN(root);
            break;
        case 'm':
            min_elem(root);
            break;
        case 'r':
            scanf("%d", &dec);
            scanf("%d", &dec_by);
            n = search_node(root, dec);
            if (n == NULL || dec < dec_by)
                printf("-1\n");
            else
            {
                DECREASE_KEY(root, dec, dec_by);
                printf("%d\n", dec - dec_by);
            }
            break;
        case 'p':
            scanf("%d",&k);
            if(k==1)
            	print(root);
            else print(root2);
            break;
        case 'u':
        	h=UNION(root,root2);
        	print(h);
        	break;
        default: exit(0);
        }

    }
    return 0;
}
