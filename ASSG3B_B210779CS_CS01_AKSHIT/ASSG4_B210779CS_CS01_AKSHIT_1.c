#include <stdio.h>
int main()
{
	int n;scanf("%d",&n);
	int arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
	}		
	for(int i=0;i<n;i++)
	{
		printf("%d ",i);
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==1)
				printf("%d ",j);
		}
		printf("\n");
	}
	return 0;
}
