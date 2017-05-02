#include<iostream>
#include<cstring>
using namespace std;
char c[130][130];
struct node
{
    int num;
    node *child[4];
    int f;
};
node *root;
node *buildtree(int x,int y,int n)
{
    node *t=new node;
    t->num=1;
    t->f=2;
    if(n==1)
    {
        if(c[x][y]==c[x][y+n/2]&&c[x][y]==c[x+n/2][y]&&c[x][y]==c[x+n/2][y+n/2])
        {
            if(c[x][y]=='1') t->f=1;
            else t->f=0;
        }
        for(int i=0;i<4;i++)
            t->child[i]=0;
        return t;
    }
    t->child[0]=buildtree(x,y,n/2);
    t->child[1]=buildtree(x,y+n/2,n/2);
    t->child[2]=buildtree(x+n/2,y,n/2);
    t->child[3]=buildtree(x+n/2,y+n/2,n/2);
    if(t->child[0]->f!=2&&t->child[0]->f==t->child[1]->f&&t->child[0]->f==t->child[2]->f&&t->child[0]->f==t->child[3]->f)
    {
        t->f=t->child[0]->f;
        return t;
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            t->num+=t->child[i]->num;
        }
    }
    return t;
}

void mprint(node *r)
{
    cout<<r->f<<" ";
    for(int i=0;i<4;i++)
    {
        if(r->child[i]!=0)
            mprint(r->child[i]);
    }
}

int main()
{
    int n,m,t,k;
    int i,j;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        memset(c,0,sizeof(c));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>c[i][j];
            }
        }
        t=max(n,m);
        k=1;
        while(k<t)
            k=k*2;
        node *w=buildtree(0,0,k);
        root=w;
        cout<<w->num<<" ";
        //Union(w);
        //cout<<w->num<<endl;
    }
    return 0;
}
