
#include<iostream>
using namespace std;
int n,m;
int sum;
struct card
{
    int val;
    int num;
};
card c[10];
void dfs(int t,int start)
{
    if(t==0)
    {
        sum++;
        return;
    }
    for(int i=start;i<m;i++)
    {
        if(t>=c[i].val&&c[i].num)
        {
            c[i].num--;
            dfs(t-c[i].val,i);
            c[i].num++;
        }
    }

}

int main()
{
    int i,j,q;
    int pe=0;
    while(cin>>n>>m)
    {
        if(pe) cout<<endl;
        pe=1;
        q=0;
        sum=0;
        for(i=0;i<m;i++)
        {
            cin>>c[i].val>>c[i].num;
        }

        dfs(n,0);
        cout<<sum<<endl;
    }
    return 0;
}
