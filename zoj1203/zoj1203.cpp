/*
5
0 0
0 1
1 1
1 0
0.5 0.5
*/
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

double dis[105][105];
double p[105][2];
int n;
double ans;
void CalcDis()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            double r=sqrt((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]));
            dis[i][j]=r;
        }
    }
}

void Prime()
{
    int temp[105],tp;
    double m;
    memset(temp,0,sizeof(temp));
    temp[1]=1;
    for(int k=1;k<n;k++)
    {
        m=10000;
        for(int i=1;i<=n;i++)
        {
            if(temp[i]==1)
            {
                for(int j=1;j<=n;j++)
                {
                    if(temp[j]==0&&dis[i][j]<m)
                    {
                        m=dis[i][j];
                        tp=j;
                    }
                }
            }
        }
        ans+=m;
        temp[tp]=1;
    }
    return ;
}

int main()
{
    int s=0;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        s++;
        ans=0.0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf %lf",&p[i][0],&p[i][1]);
        }
        CalcDis();
        Prime();
        printf("Case#%d:\nThe minimal distance is:%.2f\n",s,ans);
    }
    return 0;
}
