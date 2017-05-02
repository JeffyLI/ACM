
#include<iostream>
#include <algorithm>
#include<queue>
using namespace std;

int a[35];
int m;
bool flag;
struct node
{
    int b[30];
    int n;
    int sum;
    int start;
};
node t;
queue<node> q;

bool mysearch(int *c,int start,int last,int num)
{
    int i=0;
    for(i=start;i<last;i++)
    {
        if(num==c[i]) return true;
    }
    return false;
}

void output(node ntemp)
{
    int i;
    for(i=0;i<ntemp.n-1;i++)
    {
        cout<<ntemp.b[i]<<"+";
    }
    cout<<ntemp.b[i]<<"="<<ntemp.sum<<endl;
}

void bfs()
{
    node temp;
    node g;
    while(!q.empty())
    {
        g=q.front();
        int i;
        int l=0;
        for(i=g.start+1;i<m;i++)
        {
            temp=g;
            temp.b[temp.n]=a[i];
            //cout<<temp.n<<endl;
            temp.n++;
            l++;
            temp.start+=l;
            temp.sum+=a[i];
            if(mysearch(a,0,m,temp.sum))
            {
                output(temp);
                flag=true;
            }
            if(temp.sum<a[m-1])
            {
                q.push(temp);
            }
        }
        q.pop();
    }
}

int main()
{
    int n;
    int k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        flag=false;
        cin>>m;
        int j;
        for(j=0;j<35;j++)
        {
            a[j]=0;
        }
        for(j=0;j<m;j++)
        {
            cin>>a[j];
        }
        sort(a,a+m);
        for(j=0;j<m-1;j++)
        {
            t.b[0]=a[j];
            t.start=j;
            t.sum=a[j];
            t.n=1;
            q.push(t);
        }
        bfs();
        if(!flag) cout<<"Can't find any equations."<<endl;
        cout<<endl;
    }
    return 0;
}
