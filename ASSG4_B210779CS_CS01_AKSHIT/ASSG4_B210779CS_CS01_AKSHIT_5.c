#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int n=0;
int ans=0;
int status[1001];int path_len[1001];int pre[1001];
int min_temp(int status[],int path_len[])
{
	int i=0;int min=INT_MAX;
	int k=-1;
	for(i=0;i<n;i++){
		if(status[i]==0 && path_len[i]<min)
		{
			min=path_len[i];
			k=i;
		}
	}
	return k;
}

void dijkstra(int adj[][n],int s)
{
	//int status[n];int path_len[n];int pre[n];
	int i=0;int curr=0;
	for(i=0;i<n;i++){
		status[i]=0;
		path_len[i]=INT_MAX;
		pre[i]=-1;
	}
	//printf("s=%d\n",s);
	path_len[s]=0;
	for(int count=0;count<n;count++)
	{
		int u=min_temp(status,path_len);
		if(u==-1) return;
		//printf("u=%d\n",u);
		status[u]=1;
		for(int v=0;v<n;v++) 
		{
			if(status[v]==0 && adj[u][v]!=INT_MAX)
			{
				if(path_len[u]+adj[u][v]<path_len[v])
				{
					pre[v]=u;
					path_len[v]=path_len[u]+adj[u][v];
				}
			}
		}
	}
}

void dist(int adj[][n],int s,int v)
{
	int i=0;int u=0;
	ans=0;
	while(v!=s)
	{
		u=pre[v];
		ans+=adj[u][v];
		//printf("u=%d v=%d adj[u][v]=%d\n",u,v,adj[u][v]);
		v=u;
	}
}

void create_graph()
{
	int i=0;int j=0;int k=0;int l=0;
	scanf("%d",&n);getchar();
	int arr[n][n];int ind[n][n];
	
	
	for(i=0;i<n;i++){ for(j=0;j<n;j++) {arr[i][j]=0;ind[i][j]=0;}}
	int temp[n];int k2[n]; for(int i=0;i<n;i++) {temp[i]=0;k2[i]=0;}
	for(i=0;i<n;i++)
	{
		//printf("i=%d\n",i);
		char str[10000];
		fgets(str,10000,stdin);//printf("string=%s\n",str);
		k=0;
		for(int j=0;str[j];j++)
		{
			if(str[j]>='0' || str[j]<='9' || str[j]=='-')
			{
				int num=0;char key[100000];int b=0;
				while((str[j]>='0' && str[j]<='9')|| str[j]=='-')
				{
					key[b++]=str[j];
					j++;
				}
				key[b]='\0'; num=atoi(key);
				//printf("%d\n",num);
				temp[k]=num;ind[i][k++]=num;
			}
		}
		k2[i]=k;
		for(l=1;l<k;l++)
			{
				//printf("%d ",temp[l]);
				if(temp[l]!=0)
					arr[i][temp[l]]=1;
			}
			//printf("\n");
	}
	int mat[n][n];for(i=0;i<n;i++){ for(j=0;j<n;j++) mat[i][j]=INT_MAX;}
	for(i=0;i<n;i++)
	{
		//printf("i=%d\n",i);
		char str[10000];
		fgets(str,10000,stdin);//printf("string=%s\n",str);
		k=0;
		for(int j=0;str[j];j++)
		{
			if(str[j]>='0' || str[j]<='9' || str[j]=='-')
			{
				int num=0;char key[100000];int b=0;
				while((str[j]>='0' && str[j]<='9')|| str[j]=='-')
				{
					key[b++]=str[j];
					j++;
				}
				key[b]='\0'; num=atoi(key);
				//printf("%d\n",num);
				temp[k++]=num;
			}
		}
		int c=0;
		for(c=1;c<k;c++)
			mat[i][ind[i][c]]=temp[c];
		//printf("\n");
	}
	
	//for(i=0;i<n;i++) {for(j=0;j<n;j++) printf("%d ",mat[i][j]); printf("\n");}
	
	while(1){
	char test[5];fgets(test,5,stdin);
	if(strcmp(test,"stop")==0) return;
	if(strcmp(test,"apsp")==0)
	{
		int sc;scanf("%d",&sc);
		//printf("src index=%d\n",sc);
		dijkstra(mat,sc);
		for(i=0;i<n;i++) printf("%d ",path_len[i]);
		printf("\n");
	}
	if(strcmp(test,"sssp")==0)
	{
		int sc;int dn;scanf("%d %d",&sc,&dn);
		//printf("src ind=%d destn ind=%d\n",sc,dn);
		dijkstra(mat,sc);
		//for(i=0;i<n;i++) printf("%d ",path_len[i]);
		if(path_len[dn]==INT_MAX) 
			printf("UNREACHABLE\n");
		else{
		dist(mat,sc,dn);
		//for(i=0;i<n;i++) printf("%d ",pre[i]);
		//printf("\n");
		printf("%d\n",ans);}
	}
	}
}

int main()
{
	create_graph();
	return 0;
}
