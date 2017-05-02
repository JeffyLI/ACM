
#include<iostream>
#include<stdlib.h>
using namespace std;
struct process
{
    int id;
    int time;
};
int maxtime=0;
process p[1001];

int cmp( const void *a ,const void *b)
{ return (*(process *)a).id > (*(process *)b).id ? 1 : -1; }

void run(int num,int tk)
{
    long time=1;
    while(tk>0)
    {
        for(int i=0;i<num;i++)
        {
            if(time%p[i].time==0)
            {
                cout<<p[i].id<<endl;
                tk--;
            }
        }
        time++;
    }
}

int main()
{
    char c[9];
    int n=0,k=0;
    cin>>c;
    while(c[0]!='#')
    {
        cin>>p[n].id>>p[n].time;
        if(p[n].time>maxtime) maxtime=p[n].time;
        n++;
        cin>>c;
    }
    cin>>k;
    qsort(p,n,sizeof(p[0]),cmp);
    run(n,k);
    return 0;
}
