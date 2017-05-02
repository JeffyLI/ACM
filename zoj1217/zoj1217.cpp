
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<map>
#include<queue>
using namespace std;

map<string,string>M;
queue<string> q;

int main()
{
    string gold="12345678x";
    map<string,string>::iterator my_it;
    bool flag[8];
    int n;
    int a[4]={1,-1,3,-3};
    q.push(gold);
    M[gold]=gold;
while(!q.empty())
    {
        n=0;
        string s=q.front();
        q.pop();
        while(s[n]!='x')
        {
            n++;
        }
        string ts;
        for(int i=0;i<2;i++)
        {
            ts=s;
            if(n%3+a[i]>2||n%3+a[i]<0) continue;
            int tx=n+a[i];
            char tc;
            tc=ts[tx];
            ts[tx]=ts[n];
            ts[n]=tc;
            my_it = M.find(ts);
            if(my_it==M.end())
            {
                q.push(ts);
                M[ts]=s;
            }
        }
        for(int i=2;i<4;i++)
        {
            ts=s;
            if(n+a[i]>=8||n+a[i]<0) continue;
            int tx=n+a[i];
            char tc;
            tc=ts[tx];
            ts[tx]=ts[n];
            ts[n]=tc;
            my_it = M.find(ts);
            if(my_it==M.end())
            {
                q.push(ts);
                M[ts]=s;
            }
        }
    }
    string is;
    while(getline(cin,is))
    {
        int begin = 0;

        begin = is.find(" ",begin);  //查找空格在str中第一次出现的位置

        while(begin != -1)  //表示字符串中存在空格

        {

        is.replace(begin, 1, "");  // 用空串替换str中从begin开始的1个字符

        begin = is.find(" ",begin);  //查找空格在替换后的str中第一次出现的位置

        }
        my_it = M.find(is);
        if(my_it==M.end())
        {
            cout<<"unsolvable"<<endl;
            continue;
        }
        string str1,str2;
        int w;
        str2=is;
        while(1)
        {
            str1=M[str2];
            int ix=0,iy=0;
            while(str1[ix]!='x')
            {
                ix++;
            }
            while(str2[iy]!='x')
            {
                iy++;
            }
            switch(ix-iy)
            {
                case 3:cout<<"d";break;
                case 1:cout<<"r";break;
                case -1:cout<<"l";break;
                case -3:cout<<"u";break;
            }
            str2=str1;
            if(str1==gold)
                break;
        }
        cout<<endl;
    }
    return 0;
}
