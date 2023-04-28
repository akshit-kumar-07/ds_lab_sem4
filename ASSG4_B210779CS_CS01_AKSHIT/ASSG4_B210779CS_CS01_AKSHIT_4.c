#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
int n=0;
void makeset(int parent[],int rank[])
{
	for(int i=0;i<n;i++){
		rank[i]=0;
		parent[i]=i;
	}
}

int find(int parent[],int x)
{
	if(parent[x]==x) return x;
	return parent[x]=find(parent,parent[x]);
}

void union_set(int u,int v,int parent[],int rank[])
{
	u=find(parent,u);
	v=find(parent,v);
	if(rank[u]<rank[v]) parent[u]=v;
	else if( rank[u]> rank[v]) parent[v]=u;
	else{
		parent[v]=u;
		rank[u]++;
	}
}

void kruskal()
{
	int i=0;int j=0;int k=0;int l=0;
	scanf("%d",&n);getchar();
	int parent[n];int rank[n];makeset(parent,rank);
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
	/*for(i=0;i<n;i++){
		for(j=0;j<n;j++) printf("%d ",arr[i][j]);
		printf("\n");
	}
	
	for(i=0;i<n;i++) printf("%d ",k2[i]);
	printf("\n");
	
	for(i=0;i<n;i++){
		for(j=1;j<k2[i];j++) printf("%d ",ind[i][j]);
		printf("\n");
	}*/
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
	int edge_count=0;int cost=0;
	while(edge_count<n-1)
	{
		int min=INT_MAX;int a=-1;int b=-1;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(find(parent,i)!=find(parent,j) && mat[i][j]<min){
					min=mat[i][j];
					a=i;
					b=j;
				}
			}
		}
		union_set(a,b,parent,rank);
		edge_count++;
		cost+=min;
	}
	printf("%d\n",cost);
}

int found(int arr[],int n,int x)
{
	for(int y=0;y<n;y++)
	{
		if(arr[y]==x)
			return 1;
	}
	return 0;
}
void prim()
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
	/*for(i=0;i<n;i++){
		for(j=0;j<n;j++) printf("%d ",arr[i][j]);
		printf("\n");
	}
	
	for(i=0;i<n;i++) printf("%d ",k2[i]);
	printf("\n");
	
	for(i=0;i<n;i++){
		for(j=1;j<k2[i];j++) printf("%d ",ind[i][j]);
		printf("\n");
	}*/
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
	/*for(i=0;i<n;i++){
		for(j=0;j<n;j++) printf("%d ",mat[i][j]);
		printf("\n");
	}*/
	
	int inc[n];
	for(i=0;i<n;i++) inc[i]=0;
	int sum=0;
	int count=1;i=0;int g=0;
	while(count < n)
	{
		count++;
		int min=INT_MAX;
		int id=0;
		for(j=0;j<n;j++)
		{
			if(!found(inc,n,j))
			{
				if(mat[i][j]<min)
				{
					min=mat[i][j];id=j;
				}
			}
		}
		/*printf("\n");
		for(l=0;l<n;l++) printf("%d ",inc[l]);
		printf("\nid =%d min=%d",id,min);*/
		sum+=min;
		inc[g++]=id;
		//printf("\n");
		//for(l=0;l<n;l++) printf("%d ",inc[l]);
		i=id;
		//printf("\n%d",sum);
	}
	printf("%d\n",sum);
}
int main()
{
	char ch;scanf(" %c",&ch);
	if(ch=='a') kruskal();
	if(ch=='b') prim();
	return 0;
}
