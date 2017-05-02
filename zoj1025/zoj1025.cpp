#include<iostream>
using namespace std;

struct wood
{
    int length;
    int weight;
};

int main()
{
    wood w[10001];
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>w[j].length>>w[j].weight;
        }

    }
    return 0;
}
