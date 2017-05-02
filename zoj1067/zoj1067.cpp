
#include<iostream>
using namespace std;

struct color
{
    int r;
    int g;
    int b;
};

int main()
{
    color c[16],t;
    int d,m,p;
    int i;
    for(i=0;i<16;i++)
        cin>>c[i].r>>c[i].g>>c[i].b;
    cin>>t.r>>t.g>>t.b;
    while(1)
    {
        m=99999;
        for(i=0;i<16;i++)
        {
            d=(t.r-c[i].r)*(t.r-c[i].r)+(t.g-c[i].g)*(t.g-c[i].g)+(t.b-c[i].b)*(t.b-c[i].b);
            if(d<m)
            {
                m=d;
                p=i;
            }
        }
        cout<<"("<<t.r<<","<<t.g<<","<<t.b<<") maps to ("<<c[p].r<<","<<c[p].g<<","<<c[p].b<<")"<<endl;
        cin>>t.r>>t.g>>t.b;
        if(t.r==-1) break;
    }
    return 0;
}
