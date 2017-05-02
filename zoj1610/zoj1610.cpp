
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

struct node
{
    int a,b;
    int c;
}Tree[16003];
int color[8001];
int tc;
int n;

void buildtree(int i,int a,int b)
{
    Tree[i].a=a;
    Tree[i].b=b;
    Tree[i].c=0;
    if((b-a)==1) return;
    buildtree(i*2,a,(a+b)/2);
    buildtree(i*2+1,(a+b)/2,b);
}

void Insert(int i,int a,int b,int c)
{
    if(Tree[i].a>=a&&Tree[i].b<=b)
    {
        Tree[i].c=c+1;
        return;
    }
    int mid=Tree[i].a+Tree[i].b;
    mid=mid/2;
    if(Tree[i].c)
    {
        Insert(i*2,a,mid,Tree[i].c);
        Insert(i*2+1,mid,b,Tree[i].c);
        Tree[i].c=0;
    }
    if(a<mid)
    {
        Insert(i*2,a,b,c);
    }
    if(b>mid)
    {
        Insert(i*2+1,a,b,c);
    }
    return;
}

void Count(int i)
{
    if(i>16003) return;
    if(Tree[i].c==0)
    {
        Count(i*2);
        Count(i*2+1);
        return;
    }
    if(tc!=Tree[i].c)
    {
        color[Tree[i].c-1]++;
        tc=Tree[i].c;
    }
    return;
}

int main()
{
    int i,j,a,b,c;
    while(scanf("%d",&n)!=EOF)
    {
        buildtree(1,0,10);
        memset(color,0,sizeof(color));
        tc=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            Insert(1,a,b,c);
        }
        Count(1);
        for(j=0;j<8001;j++)
        {
            if(color[j]) printf("%d %d\n",j,color[j]);
        }
        printf("\n");
    }
    return 0;
}
