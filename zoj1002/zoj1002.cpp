#include<iostream>
#include<cstring>
using namespace std;

int G[32][32];
int visit[32];
int prev[32];
int n;

bool DFS(int start)
{
    int i,temp;
    for(i=0;i<n;i++)
    {
        if(G[start][i]&&visit[i]==0)
        {
            visit[i]=1;
            temp=prev[i];
            prev[i]=start;
            if(temp==-1||DFS(temp))
            {
                return true;
            }
            prev[i]=temp;
        }
    }
    return false;
}

int BIMATCH()
{
    for(int i=0;i<n;i++)
    {
        memset(visit,0,sizeof(visit));
        DFS(i);
    }
    int num=0;
    for(int i=0;i<n;i++)
    {
        if(prev[i]!=-1) num++;
    }
    return num/2;
}

int main()
{
    int a,b,m,i,j,t;
    char c;
    int map[6][6];
    int mh[6][6],mv[6][6];
    while(cin>>m&&m!=0)
    {
        memset(map,0,sizeof(map));
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>c;
                if(c=='X') map[i][j]=-1;
            }
        }
        n=0;
        memset(mh,int(-1),sizeof(mh));
        memset(mv,int(-1),sizeof(mv));
        for(i=0;i<m;i++)
        {
            t=-1;
            for(j=0;j<m;j++)
            {
                if(t==map[i][j])
                {
                    if(t!=-1) mh[i][j]=n;
                }
                else
                {
                    if(t==-1) mh[i][j]=n;
                    else n++;
                }
                t=map[i][j];
            }
            if(t!=-1) n++;
        }
        if(t==-1) n++;
        for(j=0;j<m;j++)
        {
            t=-1;
            for(i=0;i<m;i++)
            {
                if(t==map[i][j])
                {
                    if(t!=-1) mv[i][j]=n;
                }
                else
                {
                    if(t==-1) mv[i][j]=n;
                    else n++;
                }
                t=map[i][j];
            }
            if(t!=-1) n++;
        }
        memset(G,0,sizeof(G));
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mh[i][j]!=-1)
                {
                    a=mh[i][j];
                    b=mv[i][j];
                    G[a][b]=1;
                    G[b][a]=1;
                }
            }
        }
        memset(prev,int(-1),sizeof(prev));
        cout<<BIMATCH()<<endl;
    }
    return 0;
}
