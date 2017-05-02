#include<iostream>
using namespace std;

int main()
{
    long x1=0,y1=0,x2=0,y2=0;
    int tx,ty;
    while(1)
    {
        x1=0;y1=0;x2=0;y2=0;
        while(1)
        {
            cin>>tx>>ty;
            if(tx==0&&ty==0) break;
            else if(x1==0&&y1==0&&x2==0&&y2==0)
            {
                x1=tx;
                x2=tx;
                y1=ty;
                y2=ty;
            }
            if(x1>tx) x1=tx;
            if(x2<tx) x2=tx;
            if(y1>ty) y1=ty;
            if(y2<ty) y2=ty;
        }
        if(x1==0&&x2==0) break;
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    }
}
