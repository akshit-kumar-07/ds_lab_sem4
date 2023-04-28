#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct node
{
	char name[1000];
	char roll[10];
	int age;
	int sum;
	char branch[3];
	struct node *next;
}node;



node* create_node(char *n,char *r,int a,int s,char *b)
{
	node *tmp=(node *)malloc(sizeof(node));
	strcpy(tmp->name,n);
	strcpy(tmp->roll,r);
	tmp->age=a;
	tmp->sum=s;
	strcpy(tmp->branch,b);
	tmp->next=NULL;
	return tmp;
}

void insert(node **l,node *x)
{
	if(*l==NULL) 
	{
		*l=x;
		return;
	}
	node *t=*l;
	while(t->next!=NULL)
		t=t->next;
	t->next=x;
	return;
}

int main()
{
	int n;
	scanf("%d",&n);
	char names[n][1000];
	char roll[n][1000];
	int age[n];
	int sum[n];
	char branch[n][3];
	int x;
	for(int i=0;i<n;i++) 
	{
		char temp[1000];char troll[1000];int a;
		scanf("%s %s %d",temp,troll,&a);
		strcpy(names[i],temp);strcpy(roll[i],troll);age[i]=a;
	}
	for(int i=0;i<n;i++)
	{
		int tmp=0;
		for(int j=0;names[i][j]!='\0';j++)
		{
			tmp+=(int)names[i][j];
		}
		sum[i]=(tmp+age[i])%4;
		int l=strlen(roll[i]);
		branch[i][0]=roll[i][l-2];
		branch[i][1]=roll[i][l-1];
		branch[i][2]='\0';
	}
	//for(int i=0;i<n;i++) printf("%s %s %d %d %s\n",names[i],roll[i],age[i],sum[i],branch[i]);
	node* arr[n];
	node *t;
	for(int i=0;i<n;i++)
	{	
		t=create_node(names[i],roll[i],age[i],sum[i],branch[i]);
		arr[i]=t;
	}
	//for(int i=0;i<n;i++) printf("%s %s %d %d %s\n",arr[i]->name,arr[i]->roll,arr[i]->age,arr[i]->sum,arr[i]->branch);
	//for(int i=0;i<n;i++) printf("%s %d\n",arr[i]->name,arr[i]->sum);
	int cnt[4]={0,0,0,0};
	for(int i=0;i<n;i++) 
	{
		if(arr[i]->sum==0) cnt[0]++;
		else if(arr[i]->sum==1) cnt[1]++;
		else if(arr[i]->sum==2) cnt[2]++;
		else if(arr[i]->sum==3) cnt[3]++;
	}
	char ch;int k;char br[3];
	while(1)
	{
		scanf(" %c",&ch);
		switch(ch)
		{
			case 'c':
				scanf("%d",&k);
				if(k==0)
				{
					printf("%d ",cnt[0]);
					if(cnt[0]==0) {printf("\n");break;}
					for(int i=0;i<n;i++) 
					{
						if(arr[i]->sum==0)
							printf("%s ",arr[i]->name);
						else continue;
					}
					printf("\n");
				}
				else if(k==1)
				{
					printf("%d ",cnt[1]);
					if(cnt[1]==0) {printf("\n");break;}
					for(int i=0;i<n;i++) 
					{
						if(arr[i]->sum==1)
							printf("%s ",arr[i]->name);
						else continue;
					}
					printf("\n");
				}
				else if(k==2)
				{
					printf("%d ",cnt[2]);
					if(cnt[2]==0) {printf("\n");break;}
					for(int i=0;i<n;i++) 
					{
						if(arr[i]->sum==2)
							printf("%s ",arr[i]->name);
						else continue;
					}
					printf("\n");
				}
				else if(k==3)
				{
					printf("%d ",cnt[3]);
					if(cnt[3]==0) {printf("\n");break;}
					for(int i=0;i<n;i++) 
					{
						if(arr[i]->sum==3)
							printf("%s ",arr[i]->name);
						else continue;
					}
					printf("\n");
				}
				break;
			case '0':
				scanf(" %s",br);
				br[0]=toupper(br[0]);
				br[1]=toupper(br[1]);
				if (cnt[0]==0)
				{
					printf("-1\n");
					break;
				}
				for(int i=0;i<n;i++)
				{
					if(arr[i]->sum==0 && strcmp(arr[i]->branch,br)==0)
						printf("%s ",arr[i]->name);
				}
				printf("\n");
				break;
			case '1':
				scanf("%s",br);
				br[0]=toupper(br[0]);
				br[1]=toupper(br[1]);
				if (cnt[1]==0)
				{
					printf("-1\n");
					break;
				}
				for(int i=0;i<n;i++)
				{
					if(arr[i]->sum==1 && strcmp(arr[i]->branch,br)==0)
						printf("%s ",arr[i]->name);
				}
				printf("\n");
				break;
			case '2':
				scanf("%s",br);
				br[0]=toupper(br[0]);
				br[1]=toupper(br[1]);
				if (cnt[2]==0)
				{
					printf("-1\n");
					break;
				}
				for(int i=0;i<n;i++)
				{
					if(arr[i]->sum==2 && strcmp(arr[i]->branch,br)==0)
						printf("%s ",arr[i]->name);
				}
				printf("\n");
				break;
			case '3':
				scanf("%s",br);
				br[0]=toupper(br[0]);
				br[1]=toupper(br[1]);
				if (cnt[0]==0)
				{
					printf("-1\n");
					break;
				}
				for(int i=0;i<n;i++)
				{
					if(arr[i]->sum==3 && strcmp(arr[i]->branch,br)==0)
						printf("%s ",arr[i]->name);
				}
				printf("\n");
				break;
			default: exit(0);
		}
	}
	return 0;
}
