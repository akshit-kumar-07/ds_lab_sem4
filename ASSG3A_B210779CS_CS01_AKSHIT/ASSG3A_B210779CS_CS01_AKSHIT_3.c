#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int n;int k;
void swap(int *a,int *b)
{
	int t=*a;*a=*b;
	*b=t;
}



int parent(int i) {return (i-1)/2;}
int left(int i) {return 2*i+1;}
int right(int i) {return 2*i+2;}

void max_heapify(int arr[], int i)
{
    int smallest = i;
    // int left = 2 * i + 1;
    // int right = 2 * i + 2;
    if (left(i) < n && arr[smallest] < arr[left(i)])
        smallest = left(i);
    if (right(i) < n && arr[smallest] < arr[right(i)])
        smallest = right(i);
    if (smallest != i)
    {
        swap(&arr[i], &arr[smallest]);
        max_heapify(arr, smallest);
    }
}
void build_max_heap(int arr[])
{
    for(int i=n/2-1;i>=0;i--)
        max_heapify(arr,i);
}
void extract_max(int arr[])
{
    if (n == 0)
        return;
    int last = arr[n-1];
    int res = arr[0];
    swap(&arr[0], &last);
    n--;
    max_heapify(arr,0);
    printf("%d ",res);
}

void klargest(int arr[],int n,int k)
{
	build_max_heap(arr);
	for(int i=0;i<k;i++) extract_max(arr);
	printf("\n");
}

int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++) scanf("%d",&arr[i]);
		scanf("%d",&k);
		klargest(arr,n,k);
	}
	return 0;
}
