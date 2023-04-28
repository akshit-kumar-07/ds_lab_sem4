#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int m=0;
int hashl[1000]={[0 ... 999]=-1};
int hashq[1000]={[0 ... 999]=-1};
int hashd[1000]={[0 ... 999]=-1};

int is_prime(int n)
{
	int flag=1;
	for(int i=2;i<sqrt(n);i++)
		if(n%i==0) flag=0;
	return flag;
}

int max_prime(int n)
{
	int max=0;
	for(int i=n-1;i>=0;i--)
		if(is_prime(i) && i>max) max=i;
	return max;
}



int linear_hash(int k,int i)
{
	return ((k+i)%m);
}
int quad_hash(int k,int i)
{
	return ((k+ i*i)%m);
}

int double_hash(int k,int i)
{
	int r=max_prime(m);
	return ( k%m + i*(r-(k%r)));
}


int insertl(int k)
{
	int i=0;
	while(i<m)
	{
		int j=linear_hash(k,i);
		//printf("j=%d and arr[%d]=%d\n",j,j,hash[j]);
		if(hashl[j]==-1)
		{
			printf("%d ",j);
			hashl[j]=k;
			return i;
		}
		else i++;
	}
	if(i==m) printf("E ");
	return i;
}
int insertq(int k)
{
	int i=0;
	while(i<m)
	{
		int j=quad_hash(k,i);
		if(hashq[j]==-1)
		{
			printf("%d ",j);
			hashq[j]=k;
			return i;
		}
		else i++;
	}
	if(i==m) printf("E ");
	return i;
}

int insertd(int k)
{
	int i=0;
	while(i<m)
	{
		int j=double_hash(k,i);
		if(hashd[j]==-1)
		{
			printf("%d ",j%m);
			hashd[j]=k;
			return i;
		}
		else i++;
	}
	if(i==m) printf("E ");
	return i;
}

void linear_probe(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int k=arr[i];
		int coll=insertl(k);
		sum+=coll;
	}
	printf("\n%d\n",sum);
}
void quad_probe(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int k=arr[i];
		int coll=insertq(k);
		sum+=coll;
	}
	printf("\n%d\n",sum);
}

void dbl_hash(int arr[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int k=arr[i];
		int coll=insertd(k);
		sum+=coll;
	}
	printf("\n%d\n",sum);
}

int main()
{
	scanf("%d",&m);
	getchar();
	int n=0;
	char str[3000];
	int arr[m];
	fgets(str,3000,stdin);
	for(int i=0;str[i]!='\0';i++)
	{
		
		if(str[i]>='0' || str[i]<='9')
		{
			int num=0;
			while(str[i]>='0' && str[i]<='9')
			{
				num=num*10+(str[i]-'0');
				i++;
			}
			arr[n++]=num;
		}
		
	}
	linear_probe(arr,n);
	quad_probe(arr,n);
	dbl_hash(arr,n);
	//printf("%d",max_prime(7));
	return 0;
}
