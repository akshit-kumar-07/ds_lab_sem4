#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mat[1000][1000];
int bfs_visit[1000];
int ver[2000];
int n=0;
int q[1000]={0};
int front=0;int end=0;

void BFS(int start)
{
    q[end++]=start;
    bfs_visit[start]=1;
    int vis;
    while(front<end)
    {
        vis=q[front];
        printf("%d ",vis);
        front++;
        for(int i=0;i<n;i++)
        {
            if(mat[vis][i]==1 && !bfs_visit[i])
            {
                q[end++]=i;
                bfs_visit[i]=1;
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    getchar();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) 
            mat[i][j]=0;
    }
    
    int start=0;
    for(int i=0;i<n;i++)
    {
        int arr[n];
        char str[10000];
        fgets(str,10000,stdin);
        int count=0;
        int k = 0; 
        for(int j=0;str[j];j++)
        {
            if(str[j]>='0' || str[j]<='9')
            {
                int num=0;
                while(str[j]>='0' && str[j]<='9' && str[j])
                {
                    num=10*num; num+=str[j]-48;
                    j++;
                }
                count++;
                arr[k++]=num;
            }
        }
        for(int f=1;f<k;f++)  mat[i][arr[f]]=1;
    }

    for(int i=0;i<n;i++) 
    {
        bfs_visit[i]=0;
        ver[i]=0;
    }

    BFS(0);
    return 0;
}

