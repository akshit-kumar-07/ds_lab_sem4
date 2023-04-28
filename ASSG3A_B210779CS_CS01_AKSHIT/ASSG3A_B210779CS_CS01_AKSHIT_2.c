#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
int size=0;
void swap(int *a,int *b)
{
    int temp=*a;*a=*b;
    *b=temp;
}
int parent(int i)
{
    return (i - 1) / 2;
}

int left(int i)
{
    return (2 * i + 1);
}

int right(int i)
{
    return (2 * i + 2);
}
void print(int arr[])
{
    rep(i,0,size)
        printf("%d ",arr[i]);
    printf("\n");
}
void insert(int arr[], int key)
{
    size++;
    arr[size - 1] = key;
    int x = size - 1;
    while (x > 0 && arr[parent(x)] > arr[x])
    {
        /*int temp = arr[parent(x)];
        arr[parent(x)] =arr[x];
        arr[x] = temp;*/
        swap(&arr[x], &arr[parent(x)]);
        x = parent(x);
    }
}
void min_heapify(int arr[], int i)
{
    int smallest = i;
    // int left = 2 * i + 1;
    // int right = 2 * i + 2;
    if (left(i) < size && arr[smallest] > arr[left(i)])
        smallest = left(i);
    if (right(i) < size && arr[smallest] > arr[right(i)])
        smallest = right(i);
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        min_heapify(arr, smallest);
    }
}
void build_min_heap(int arr[])
{
    for(int i=size/2-1;i>=0;i--)
        min_heapify(arr,i);
}
int extract_min(int arr[])
{
    if (size == 0)
        return -1;
    int last = arr[size-1];
    int res = arr[0];
    swap(&arr[0], &last);
    size--;
    min_heapify(arr,0);
    return res;
}
void delete_key(int arr[],int key)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]==key)
            break;
    }
    int x=arr[i];
    swap(&arr[i],&arr[size-1]);
    size--;
    build_min_heap(arr);
}
void change_priority(int arr[],int y,int z)
{
    if (z > y)
        return;
    int ind = -1;
    rep(i, 0, size)
    {
        if (arr[i] == y)
        {
            ind = i;
            break;
        }
    }
   if(ind==-1)
    {
    	printf("-1\n");
    	return;
    }
    arr[ind] = z;
    if(ind!=-1) printf("%d\n",z);
    while (ind > 0 && arr[parent(ind)] > arr[ind])
    {
        swap(&arr[ind], &arr[parent(ind)]);
        ind = parent(ind);
    }
}
int main()
{
    int arr[10000];
    char ch;int k;int f=0;
    int y;int z;
    while(1)
    {
        scanf(" %c",&ch);
        switch(ch)
        {
            case 'i':
            	scanf("%d", &k);
            	insert(arr, k);
            	break;
        	case 'p':
            	print(arr);
            	break;
        	case 'x':
            	extract_min(arr);
            	print(arr);
            	break;
            case 'd':
            	scanf("%d",&k);f=0;
            	rep(i,0,size)
            	{
            		if(arr[i]==k)
            			f=1;
            	}
            	if(f==0)
            	{
            		printf("-1\n");
            		break;
            	}
            	printf("%d\n",k);
            	delete_key(arr,k);
            	break;
        	case 'g':
        		if(size==0)
        		{
        			printf("-1\n");break;
        		}
            	printf("%d\n",arr[0]);
            	break;
       		case 'r':
            	scanf("%d %d", &y, &z);
            	if(z>=y) 
            	{
            		printf("-1\n");
            		break;
            	}
            	change_priority(arr, y, z);
            //	printf("%d\n",z);
            	break;
        	case 'e':
            	exit(0);
            default: exit(0);
        }
    }
    return 0;
}
