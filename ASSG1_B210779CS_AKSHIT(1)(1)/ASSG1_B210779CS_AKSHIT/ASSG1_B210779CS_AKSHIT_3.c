#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define rep(i,a,b) for(int i=a;i<b;i++) 
struct node
{
    int data;
    struct node *next;
};
struct node* create_node(int x)
{
    struct node *tmp=(struct node *)malloc(sizeof(struct node));
    tmp->data=x;
    tmp->next=NULL;
    return tmp;
}
void push(struct node **head,struct node *x)
{
    if(*head==NULL)
    {
        *head=x;
        return;
    }
    struct node *tmp=*head;
    while(tmp->next!=NULL) tmp=tmp->next;
    tmp->next=x;
    return;
}
int main()
{
    struct node *head=NULL;
    char str[1000];int k;
    fgets(str,1000,stdin);
    int count;
    for(int i=0;str[i];i++)
    {
        if(str[i]>='0' || str[i]<='9')
        {
            int num=0;
            while(str[i]>='0' && str[i]<='9' && str[i])
            {
                num=10*num; num+=str[i]-48;
                i++;
            }
            count++;
            push(&head,create_node(num));
        }
    }
    scanf("%d",&k);
    if(k>count) {
        printf("-1");
        return 0;
    }
    struct node *tmp=head;
    for(int i=0;i<count-k;i++) tmp=tmp->next;
    printf("%d",tmp->data);
    return 0;
}