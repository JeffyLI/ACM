
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int G[101][101];
int f[101];
double d[101];

int main()
{
    int n,m,i;
    int a,b,c,tb;
    double t,tm,ans;
    while(cin>>n&&n!=0)
    {
        cin>>m;
        memset(G,0,sizeof(G));
        memset(f,0,sizeof(f));
        memset(d,0,sizeof(d));
        for(i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            G[a][b]=c;
            G[b][a]=c;
        }
        f[1]=1;
        int temp=1;
        int tn=n-1;
        while(tn--)
        {
            tm=0;
            for(i=1;i<=n;i++)
            {
                if(f[i]==0&&G[temp][i])
                {
                    if(d[temp]) t=d[temp]*G[temp][i]/100;
                    else t=G[1][i];
                    if(d[i]<t)
                    {
                        d[i]=t;
                    }
                }
                if(d[i]>tm&&G[temp][i])
                {
                    tm=d[i];
                    tb=i;
                }
            }
            f[tb]=1;
            temp=tb;
        }
        cout<<fixed<<setprecision(6);
        cout<<d[n]<<" percent"<<endl;
    }
    return 0;
}
