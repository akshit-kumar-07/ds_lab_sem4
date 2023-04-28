#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int n;
	scanf("%d",&n);
	int arr1[100000]; int arr2[100000];
	for(int i=0;i<n;i++)
		scanf("%d",&arr1[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&arr2[i]);
	int count1[100000]={0}; int count2[100000]={0};
	for(int i=0;i<n;i++)
		count1[arr1[i]]++;
	for(int i=0;i<n;i++)
		count2[arr2[i]]++;
	int flag=1;
	for(int i=0;i<100000;i++)
		{if(count1[i]==count2[i]) continue;
		else flag =0;}
	printf("%d\n",flag);
	return 0;
}
