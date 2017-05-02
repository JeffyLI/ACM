
#include<iostream>
#include<queue>
using namespace std;

int f(int m,queue<int> q)
{
    int temp,w;
    q.pop();
    while(!q.empty())
    {
        for(int i=0;i<m-1;i++)
        {
            temp=q.front();
            q.pop();
            q.push(temp);
        }
        q.pop();
    }
    return temp;
}

int main()
{
    int n,sum;
    queue<int> tq;
    while(1)
    {
        cin>>n;
        while(!tq.empty())
            tq.pop();
        if(n==0) break;
        for(int i=1;i<=n;i++)
        {
            tq.push(i);
        }
        sum=2;
        while(1)
        {
            if(f(sum,tq)==2)
            {
                cout<<sum<<endl;
                break;
            }
            sum++;
        }
    }
    return 0;
}
