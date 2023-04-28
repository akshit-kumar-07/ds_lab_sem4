#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct queue{
	int *arr;
	int cap;
	int head;
	int tail;
	int num;
};
struct queue* new_queue(int n)
{
	struct queue* q;
	q->arr=(int *)malloc(n*sizeof(int));
	q->cap=n;
	q->head=-1;
	q->tail=-1;
	q->num=0;
	return q;
}
int isfull(struct queue *q)
{
	return q->num==q->cap;
}
int isempty(struct queue *q)
{
	return q->num==0;
}
void enq(struct queue **q,int x)
{
	if(isfull(*q)) return;
	(*q)->arr[++(*q)->head]=x;
	(*q)->num++;
	
	return;
}
int pop(struct queue **q)
{
	if(isempty(*q)) return 1;
	//printf("%d\n",(*q)->tail);
	int t=(*q)->arr[++((*q)->tail)];
	//printf("%d %d\n",(*q)->tail,(*q)->arr[(*q)->tail]);
	(*q)->num--;
	return t;
}
int main()
{
	int n;int p;
	scanf("%d",&n);
	struct queue *q=new_queue(n);
	char ch;
	while(1)
	{
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'i':
				scanf("%d",&p);
				enq(&q,p);
				if(isfull(q)) printf("1\n");
				break;
			case 'd':
				p=pop(&q);
				printf("%d\n",p);
				break;
			case 'e':
				isempty(q)?printf("1\n"):printf("-1\n");
				break;
			case 'f':
				isfull(q)?printf("1\n"):printf("-1\n");
				break;
			case 't':
				exit(0);
				break;
			default: exit(0);
		}
	}
	return 0;
}
