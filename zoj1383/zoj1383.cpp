
#include<iostream>
using namespace std;

int main()
{
    int n,i,m,p;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>m;
        p=0;
        while(m/2!=0)
        {
            if((m%2)==1)
                cout<<p<<" ";
            p++;
            m=m/2;
        }
        if(m%2==1)
            if(i==n-1)
               cout<<p;
            else
                cout<<p<<endl;
    }
    return 0;
}
