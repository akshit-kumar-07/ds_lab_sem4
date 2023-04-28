#include <stdio.h>
#include <stdlib.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
struct stack
{
	int *arr;
	int cap;
	int top;
    int count;
};
struct stack* new_stack(int n)
{
	struct stack* tmp;
	tmp->arr=(int *)malloc(sizeof(int)*n);
	tmp->cap=n;
	tmp->top=-1;
    tmp->count=0;
	return tmp;
}

void push(struct stack **s,int x)
{
   /// printf("The stack capp is %d and top is %d\n",(*s)->cap,(*s)->top);
	(*s)->arr[++((*s)->top)]=x;
    (*s)->count++;
	return;
}
int pop(struct stack **s)
{
	if((*s)->top==-1)
		return -1;
	int tmp=(*s)->arr[(*s)->top];
	(*s)->top--;
	return tmp;
}
void print(struct stack* s)
{
    for(int i=0;i<((s)->count);i++)
        printf("%d ",(s)->arr[i]);
    printf("\n");
}
int main()
{
	int n;int p;
	scanf("%d",&n);
	struct stack *s=new_stack(n);
	char ch;
	while(1)
	{
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'i':
				scanf("%d",&p);
				push(&s,p);
                if(s->count==s->cap)
                {
                    int tmp[s->cap];
                    rep(i,0,s->cap) tmp[i]=s->arr[i];
                    s->arr=(int *)malloc(sizeof(int)*((s->cap)*2));
                    s->cap=2*(s->cap);
                    rep(i,0,s->cap) s->arr[i]=tmp[i];
                    //rep(i,0,s->cap) printf("%d ",s->arr[i]);
                    //printf("new cap=%d\n",s->cap);
                }
				break;
			case 'd':
				p=pop(&s);
				printf("%d\n",p);
				break;
            case 'p':
                print(s);
                break;
			case 't':
				return 0;
			default: exit(0);
		}
	}
	return 0;
}
