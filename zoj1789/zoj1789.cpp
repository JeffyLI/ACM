
#include<iostream>
#include<cstdio>
using namespace std;
int parent[30005];
int sum[30005];
int findparent(int n)
{
    int temp=n;
    while(parent[temp]!=-1)
    {
        temp=parent[temp];
    }
    return temp;
}

int main()
{
    int n,m,k,qt,t;
    int i,j;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) break;
        for(i=0;i<n;i++)
        {
            parent[i]=-1;
            sum[i]=1;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&k,&qt);
            qt=findparent(qt);
            for(j=0;j<k-1;j++)
            {
                scanf("%d",&t);
                t=findparent(t);
                if(qt!=t)
                {
                    parent[t]=qt;
                    sum[qt]+=sum[t];
                }
            }
        }
        printf("%d\n",sum[findparent(0)]);
    }
    return 0;
}
