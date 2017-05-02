
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    int a,b;
    double v;
    cin>>n;
    cout <<fixed<<setprecision(2);
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(a%2==1&&b%2==1)
            v=a*b-1+sqrt(2);
        else
            v=a*b;
        cout<<"Scenario #"<<i+1<<":"<<endl;
        cout<<v;
        cout<<endl<<endl;
    }
    return 0;
}
