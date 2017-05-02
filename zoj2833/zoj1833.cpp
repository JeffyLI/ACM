#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
//int a[100005];

struct node
{
    int num;
    int pos;
    node *parent;
};
node *r[100005];
/*
class myclass
{
private:
    node *r[100005];
public:
    myclass(){}
    void getmember(int x,int y)
    {
        if(a[x]==0)
        {
            myinit(x);
        }
        if(a[y]==0)
        {
            myinit(y);
        }
        Union(x,y);
    }
    ~myclass()
    {
        delete[] r;
    }

    void mclear()
    {
        delete[] r;
        memset(a,0,sizeof(a));
    }

    void myinit(int x)
    {
        a[x]=1;
        r[x]=new node;
        r[x]->pos=x;
        r[x]->next=0;
        r[x]->parent=0;
    }

    void Union(int x,int y)
    {
        node *xp,*yp,*temp;
        xp=findparent(x);
        yp=findparent(y);
        if(xp->pos==yp->pos)
            return;
        if(a[xp->pos]<a[yp->pos])
        {
            int w=a[xp->pos];
            addnumber(xp,a[yp->pos]);
            addnumber(yp,w);
            xp->parent=yp;
            temp=r[y];
            while(temp->next)
            {
                temp=temp->next;
            }
            temp->next=xp;
        }
        else
        {
            int w=a[xp->pos];
            addnumber(xp,a[yp->pos]);
            addnumber(yp,w);
            yp->parent=xp;
            temp=r[x];
            while(temp->next)
            {
                temp=temp->next;
            }
            temp->next=yp;
        }
    }

    void addnumber(node *root,int n)
    {
        while(root)
        {
            a[root->pos]+=n;
            root=root->next;
        }
    }

    node *findparent(int x)
    {
        node *root=r[x];
        while(root->parent)
        {
            root=root->parent;
        }
        return root;
    }
};
*/
node *myfind(int x)
{
    node *n=r[x];
    while(n->parent)
    {
        n=n->parent;
    }
    return n;
}

void myunion(int x,int y)
{
    node *dx,*dy;
    dx=myfind(x);
    dy=myfind(y);
    if(dx->pos!=dy->pos)
    {
        if(dx->num<dy->num)
        {
            dx->parent=dy;
            dy->num+=dx->num;
        }
        else
        {
            dy->parent=dx;
            dx->num+=dy->num;
        }
    }
}
int main()
{
    int n,m,i,j;
    int x,y;
    int q;
    char c;
    int ct=1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(ct!=1)
            printf("\n");
        printf("Case %d:\n",ct);
        ct++;
        for(i=1;i<=n;i++)
        {
            r[i]=new node;
            r[i]->num=1;
            r[i]->pos=i;
            r[i]->parent=0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%s",&c);
            if(c=='M')
            {
                scanf("%d%d",&x,&y);
                myunion(x,y);
            }
            else if(c=='Q')
            {
                scanf("%d",&q);
                printf("%d\n",myfind(q)->num);
            }
        }
    }
    return 0;
}
