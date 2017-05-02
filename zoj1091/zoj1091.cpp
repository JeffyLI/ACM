
#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

int a[8][8];
struct point
{
    int x;
    int y;
    int c;
};

queue<point> q;

int bfs(int dx,int dy)
{
    point temp,t;
    int i;
    int dir[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    while(!q.empty())
    {
        temp=q.front();
        if(temp.x==dx&&temp.y==dy) return temp.c;
        a[temp.x][temp.y]=1;
        for(i=0;i<8;i++)
        {
            t.x=temp.x+dir[i][0];
            t.y=temp.y+dir[i][1];
            t.c=temp.c+1;
            if(t.x>=0&&t.x<8&&t.y>=0&&t.y<8&&a[t.x][t.y]!=1)
            {
                q.push(t);
            }
        }
        q.pop();
    }
    return 1;
}


int main()
{
    int x1,x2,y1,y2;
    int i,j;
    char c[5];
    while(gets(c))
    {
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                a[i][j]=0;
            }
        }
        while(!q.empty())
        {
            q.pop();
        }
        y1=c[0]-'a';
        x1=c[1]-'1';
        y2=c[3]-'a';
        x2=c[4]-'1';
        point p;
        p.x=x1;
        p.y=y1;
        p.c=0;
        q.push(p);
        cout<<"To get from "<<c[0]<<c[1]<<" to "<<c[3]<<c[4]<<" takes "<<bfs(x2,y2)<<" knight moves."<<endl;
    }
    return 0;
}
