#include<iostream>
#include<queue>
#include <cstdlib>
using namespace std;

struct people
{
    char name[25];
    int n;
};
int comp(const void*p1,const void*p2)
{
    return (*(people*)p2).n > (*(people*)p1).n?1:-1;
}

int main()
{
    char c[25];
    people l[11];
    int x,y;
    int pe=0;
    int m;
    while(cin>>c)
    {
        m=0;
        if(pe!=0) cout<<endl;
        pe=1;
        while(cin>>l[m].name)
        {
            if(l[m].name[1]=='N') break;
            cin>>x>>y;
            l[m].n=y-x;
            m++;
        }
        qsort(l,m,sizeof(people),comp);
        for(int i=0;i<m;i++)
            cout<<l[i].name<<endl;
    }
    return 0;
}
